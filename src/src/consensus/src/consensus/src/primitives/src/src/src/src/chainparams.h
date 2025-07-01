// src/chainparams.h

#ifndef ONETURE_CHAINPARAMS_H
#define ONETURE_CHAINPARAMS_H

#include "consensus/params.h"
#include "primitives/block.h"
#include "protocol.h"

#include <string>
#include <vector>

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

class CChainParams {
public:
    enum Base58Type {
        PUBKEY_ADDRESS,
        SCRIPT_ADDRESS,
        SECRET_KEY,
        MAX_BASE58_TYPES
    };

    const Consensus::Params& GetConsensus() const { return consensus; }
    const CBlock& GenesisBlock() const { return genesis; }
    const std::vector<unsigned char>& Base58Prefix(Base58Type type) const { return base58Prefixes[type]; }
    const std::string& Bech32HRP() const { return bech32_hrp; }

protected:
    Consensus::Params consensus;
    CBlock genesis;
    std::vector<unsigned char> base58Prefixes[MAX_BASE58_TYPES];
    std::string bech32_hrp;
};

const CChainParams& Params();
void SelectParams(const std::string& network);

#endif // ONETURE_CHAINPARAMS_H
