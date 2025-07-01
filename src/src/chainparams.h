
// src/consensus/params.h

#ifndef ONETURE_CONSENSUS_PARAMS_H
#define ONETURE_CONSENSUS_PARAMS_H

#include <stdint.h>
#include <limits>
#include <string>

namespace Consensus {

    struct Params {
        uint32_t nSubsidyHalvingInterval;
        uint64_t nBlockReward;
        uint64_t nMaxMoney;
        uint32_t nTimeSlotLength;
        uint256 posLimit;
        uint256 hashGenesisBlock;
    };

} // namespace Consensus

#endif // ONETURE_CONSENSUS_PARAMS_H
