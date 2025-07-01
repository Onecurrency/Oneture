// src/chainparams.cpp

#include "chainparams.h"
#include "consensus/params.h"
#include "primitives/block.h"
#include "protocol.h"

#include <vector>
#include <string>
#include <cstring>

// Helper to convert seed data to network addresses (simplified)
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

// Sample seed nodes (IPs in IPv6 format)
static SeedSpec6 pnSeed6_main[] = {
    {{0x20,0x01,0x0d,0xb8,0xac,0x10,0xfe,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01}, 17171},
    {{0x20,0x01,0x0d,0xb8,0xac,0x10,0xfe,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02}, 17171},
};

static void CreateGenesisBlock(CBlock& genesisBlock, const std::string& pszTimestamp, uint32_t nTime,
                               uint32_t nNonce, uint32_t nBits, int32_t nVersion, uint64_t genesisReward)
{
    genesisBlock.nVersion = nVersion;
    genesisBlock.hashPrevBlock.SetNull();
    genesisBlock.nTime = nTime;
    genesisBlock.nBits = nBits;
    genesisBlock.nNonce = nNonce;

    // Create coinbase transaction here (simplified)
    // Normally you'd create a proper transaction, here is a placeholder
    // You will replace this with actual transaction creation logic later

    genesisBlock.vtx.clear();
    // ... add coinbase tx to vtx

    genesisBlock.hashMerkleRoot = genesisBlock.GetMerkleRoot();
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // Consensus params
        consensus.nSubsidyHalvingInterval = 840000; // Every 4 years approx
        consensus.nBlockReward = 50 * COIN;         // 50 ONE initial block reward
        consensus.nMaxMoney = 20000000 * COIN;      // Max 20 million ONE
        consensus.nTimeSlotLength = 600;            // 10 minutes block time

        // Genesis block params
        uint32_t nTime = 1688236800;  // Fixed timestamp (e.g. July 1, 2023)
        uint32_t nNonce = 2083236893; // Example nonce
        uint32_t nBits = 0x1d00ffff;  // Difficulty bits
        int32_t nVersion = 1;
        uint64_t genesisReward = 50 * COIN;

        CreateGenesisBlock(genesis, "Oneture Genesis Block - 2025", nTime, nNonce, nBits, nVersion, genesisReward);

        // Base58 prefixes
        base58Prefixes[PUBKEY_ADDRESS] = {0x1C}; // Example prefix for One addresses
        base58Prefixes[SCRIPT_ADDRESS] = {0x05};
        base58Prefixes[SECRET_KEY] = {0x80};
        bech32_hrp = "one";

        // Seeds
        // Seed nodes would be used here

    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams& Params() {
    return *globalChainParams;
}

void SelectParams(const std::string& network) {
    if (network == "main") {
        globalChainParams = std::make_unique<CMainParams>();
    } else {
        // Could add testnet or regtest params here
        throw std::runtime_error("Unknown network: " + network);
    }
}
