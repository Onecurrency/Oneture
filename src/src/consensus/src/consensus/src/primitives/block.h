// src/primitives/block.h

#ifndef ONETURE_PRIMITIVES_BLOCK_H #define ONETURE_PRIMITIVES_BLOCK_H

#include <stdint.h> #include <string> #include <vector>

#include "uint256.h" #include "serialize.h" #include "script/script.h" #include "primitives/transaction.h"

class CBlockHeader { public: int32_t nVersion; uint256 hashPrevBlock; uint256 hashMerkleRoot; uint32_t nTime; uint32_t nBits; uint32_t nNonce;

CBlockHeader() {
    SetNull();
}

void SetNull() {
    nVersion = 0;
    hashPrevBlock.SetNull();
    hashMerkleRoot.SetNull();
    nTime = 0;
    nBits = 0;
    nNonce = 0;
}

bool IsNull() const {
    return (nBits == 0);
}

uint256 GetHash() const;

};

class CBlock : public CBlockHeader { public: std::vector<CTransaction> vtx;

CBlock() {
    SetNull();
}

void SetNull() {
    CBlockHeader::SetNull();
    vtx.clear();
}

CBlockHeader GetBlockHeader() const {
    CBlockHeader block;
    block.nVersion = nVersion;
    block.hashPrevBlock = hashPrevBlock;
    block.hashMerkleRoot = hashMerkleRoot;
    block.nTime = nTime;
    block.nBits = nBits;
    block.nNonce = nNonce;
    return block;
}

uint256 GetHash() const;
uint256 GetMerkleRoot() const;

};

#endif // ONETURE_PRIMITIVES_BLOCK_H

