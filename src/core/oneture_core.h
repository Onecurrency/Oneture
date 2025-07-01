
#ifndef ONETURE_CORE_H
#define ONETURE_CORE_H

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <ctime>

// --------------
// CONSTANTS & DEFINES
// --------------
static const uint64_t COIN = 100000000; // وحدة العملة (8 أرقام عشرية)
static const uint64_t MAX_MONEY = 20000000 * COIN; // الحد الأقصى للعملات: 20 مليون
static const uint32_t BLOCK_TIME = 600; // 10 دقائق بين الكتل (بالثواني)
static const uint32_t HALVING_INTERVAL = 210000; // كل 4 سنوات تقريباً

// --------------
// STRUCTS & CLASSES
// --------------

struct CBlock {
    uint32_t nVersion;
    uint64_t nTime;        // توقيت الكتلة (Unix Timestamp)
    uint32_t nHeight;      // رقم الكتلة في السلسلة
    std::string hashPrevBlock;
    std::string hashMerkleRoot;
    uint64_t nStakeModifier; // لPoS
    uint64_t nBits;        // صعوبة التعدين
    std::vector<std::string> vTx; // قائمة المعاملات كأمثلة نصية (يمكن تطويرها لاحقاً)
};

struct CTxOut {
    uint64_t nValue;       // القيمة بالساتوشي
    std::string scriptPubKey; // عنوان الاستقبال (يمكن تحسينها لاحقاً)
};

struct CTransaction {
    uint32_t nVersion;
    std::vector<CTxOut> vout; 
    std::string hash; // معرف المعاملة
};

// ---------
// CONSENSUS
// ---------
class ConsensusParams {
public:
    uint32_t nSubsidyHalvingInterval = HALVING_INTERVAL;
    uint64_t nMaxMoney = MAX_MONEY;
    uint32_t nStakeMinAge = 60 * 60 * 24; // 1 يوم بالثواني
    uint32_t nStakeMaxAge = 60 * 60 * 24 * 90; // 90 يوم كحد أقصى
    uint32_t nTargetSpacing = BLOCK_TIME;
    uint32_t nTargetTimespan = BLOCK_TIME * 14 * 24 * 6; // تقريباً 2 أسابيع
    uint64_t nBaseBlockReward = 50 * COIN; // مكافأة الكتلة الأساسية (50 ONE)
    
    uint64_t GetBlockReward(uint32_t nHeight) const {
        // تقليل المكافأة كل 210000 كتلة (نصف كل 4 سنوات)
        uint32_t halvings = nHeight / nSubsidyHalvingInterval;
        uint64_t reward = nBaseBlockReward >> halvings;
        return (reward > 0) ? reward : 0;
    }
};

// ---------
// WALLET & BALANCE
// ---------
class Wallet {
public:
    std::string ownerAddress;
    uint64_t balance;

    Wallet(const std::string& address): ownerAddress(address), balance(0) {}

    void AddBalance(uint64_t amount) {
        if (balance + amount <= MAX_MONEY)
            balance += amount;
    }

    bool SubtractBalance(uint64_t amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }
};

// -------------
// BLOCKCHAIN MANAGER
// -------------

class Blockchain {
private:
    std::vector<CBlock> chain;
    ConsensusParams consensus;
    std::map<std::string, Wallet> wallets; // العنوان -> المحفظة

public:
    Blockchain(const std::string& founderAddress) {
        // انشاء Genesis Block مع توزيع 5 مليون لـمحفظة المؤسس
        CBlock genesis;
        genesis.nVersion = 1;
        genesis.nTime = std::time(nullptr);
        genesis.nHeight = 0;
        genesis.hashPrevBlock = "0";
        genesis.hashMerkleRoot = "genesisMerkleRoot";
        genesis.nStakeModifier = 0;
        genesis.nBits = 0x1d00ffff; // تعقيد مبدئي
        genesis.vTx = {};
        
        chain.push_back(genesis);
        
        // إضافة محفظة المؤسس و 5 مليون عملة
        wallets[founderAddress] = Wallet(founderAddress);
        wallets[founderAddress].AddBalance(5000000ULL * COIN);
    }

    const CBlock& GetLatestBlock() const {
        return chain.back();
    }

    bool AddBlock(const CBlock& newBlock) {
        // تحقق أساسي: هل الكتلة التالية مباشرة؟
        if (newBlock.nHeight != chain.size()) return false;
        // تحقق الهاش السابق:
        if (newBlock.hashPrevBlock != GetLatestBlock().hashMerkleRoot) return false;
        chain.push_back(newBlock);
        return true;
    }

    Wallet* GetWallet(const std::string& address) {
        auto it = wallets.find(address);
        if (it != wallets.end()) return &(it->second);
        return nullptr;
    }

    Wallet& CreateWallet(const std::string& address) {
        wallets[address] = Wallet(address);
        return wallets[address];
    }
};

#endif // ONETURE_CORE_H
