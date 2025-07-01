
// src/protocol.h

#ifndef ONETURE_PROTOCOL_H
#define ONETURE_PROTOCOL_H

#include <cstdint>
#include <string>

// مثال على بعض تعريفات البروتوكول

static const int PROTOCOL_VERSION = 70015;

enum NetworkMessageType {
    VERSION = 0,
    VERACK = 1,
    PING = 2,
    PONG = 3,
    // إضافة المزيد حسب الحاجة
};

#endif // ONETURE_PROTOCOL_H
