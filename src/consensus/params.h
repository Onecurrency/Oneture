
// consensus/params.h

#ifndef ONETURE_CONSENSUS_PARAMS_H
#define ONETURE_CONSENSUS_PARAMS_H

#include <cstdint>

namespace Consensus {

struct Params {
    int nSubsidyHalvingInterval; // عدد الكتل قبل تقليل المكافأة للنصف
    uint64_t nBlockReward;        // مكافأة البلوك (بالـ satoshi أو الوحدة الصغيرة)
    uint64_t nMaxMoney;           // الحد الأقصى للعرض الكلي للعملة
    int nTimeSlotLength;          // طول فترة البلوك (بالثواني)
};

} // namespace Consensus

#endif // ONETURE_CONSENSUS_PARAMS_H
