#ifndef _IDENTIFICABLE_H_
#define _IDENTIFICABLE_H_

#include <cstdint>

class Identificable {
private:
    const uint8_t UUID_;
public:
    Identificable(uint8_t uuid);
    virtual ~Identificable();
    uint8_t uuid();
};

#endif
