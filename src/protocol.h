
// src/main.cpp

#include <iostream> #include "chainparams.h" #include "consensus/params.h"

int main() { std::cout << "\n==============================\n"; std::cout << "    Oneture Blockchain Node    \n"; std::cout << "==============================\n";

// Example output to confirm block reward and block time
Consensus::Params params;
params.nBlockReward = 50;
params.nSubsidyHalvingInterval = 210240; // ~4 years
params.nTimeSlotLength = 600; // 10 minutes

std::cout << "Block Reward: " << params.nBlockReward << " ONE\n";
std::cout << "Block Time: " << params.nTimeSlotLength << " seconds\n";
std::cout << "Halving Every: " << params.nSubsidyHalvingInterval << " blocks\n";

return 0;

}

