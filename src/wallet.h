
#ifndef ONETURE_WALLET_H
#define ONETURE_WALLET_H

#include <string>
#include <map>
#include <cstdint>

class Wallet {
private:
    std::string username;
    std::string password;
    uint64_t balance;

public:
    Wallet() : balance(0) {}

    bool Login(const std::string& user, const std::string& pass) {
        // هنا فقط مثال بسيط، يمكنك إضافة نظام تحقق حقيقي
        if (user == username && pass == password) {
            return true;
        }
        return false;
    }

    void SetCredentials(const std::string& user, const std::string& pass) {
        username = user;
        password = pass;
    }

    uint64_t GetBalance() const {
        return balance;
    }

    void AddBalance(uint64_t amount) {
        balance += amount;
    }

    bool SendCoins(uint64_t amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

#endif // ONETURE_WALLET_H
