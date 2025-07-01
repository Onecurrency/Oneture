// src/protocol.h

#ifndef ONETURE_PROTOCOL_H #define ONETURE_PROTOCOL_H

#include <stdint.h> #include <string>

// Protocol message start string static const unsigned char pchMessageStart[4] = { 0xfa, 0xbf, 0xb5, 0xda }; // Custom network magic bytes

// Maximum size of a block (in bytes) static const unsigned int MAX_BLOCK_SIZE = 2000000;

// Default port static const int DEFAULT_PORT = 17171;

// User agent string static const std::string USER_AGENT = "/Oneture:1.0.0/";

#endif // ONETURE_PROTOCOL_H

