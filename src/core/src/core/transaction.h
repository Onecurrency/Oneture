
#ifndef ONETURE_TRANSACTION_H
#define ONETURE_TRANSACTION_H

#include <string>
#include <vector>
#include <cstdint>

struct CTxOut {
    uint64_t nValue;           // قيمة العملة بالساتوشي
    std::string scriptPubKey;  // عنوان الاستقبال (يمكن تطويره لاحقا)
};

struct CTransaction {
    uint32_t nVersion;
    std::vector<CTxOut> vout;  // مخرجات المعاملة
    std::string hash;          // معرف المعاملة (يمكن استخدام تجزئة لاحقا)
};

#endif // ONETURE_TRANSACTION_H
