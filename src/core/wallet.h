
#ifndef ONETURE_WALLET_H
#define ONETURE_WALLET_H

#include <string>
#include <map>
#include <iostream>
#include "oneture_core.h"

class WalletManager {
private:
    Blockchain& blockchain;
public:
    WalletManager(Blockchain& bc) : blockchain(bc) {}

    void CreateWallet(const std::string& address) {
        blockchain.CreateWallet(address);
        std::cout << "Wallet created: " << address << std::endl;
    }

    bool Send(const std::string& from, const std::string& to, uint64_t amount) {
        Wallet* sender = blockchain.GetWallet(from);
        Wallet* receiver = blockchain.GetWallet(to);

        if (!sender) {
            std::cout << "Sender wallet not found.\n";
            return false;
        }
        if (!receiver) {
            std::cout << "Receiver wallet not found, creating wallet...\n";
            blockchain.CreateWallet(to);
            receiver = blockchain.GetWallet(to);
        }
        if (!sender->SubtractBalance(amount)) {
            std::cout << "Insufficient balance.\n";
            return false;
        }
        receiver->AddBalance(amount);
        std::cout << "Sent " << amount / COIN << " ONE from " << from << " to " << to << std::endl;
        return true;
    }

    void ShowBalance(const std::string& address) {
        Wallet* wallet = blockchain.GetWallet(address);
        if (!wallet) {
            std::cout << "Wallet not found.\n";
            return;
        }
        std::cout << "Balance for " << address << ": " << wallet->balance / COIN << " ONE\n";
    }
};

#endif // ONETURE_WALLET_H
