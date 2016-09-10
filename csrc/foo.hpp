#pragma once
#include <stdint.h> //for uint8

namespace foo {
    void bar(const uint8_t * src_data, const int height, const int width, uint8_t* dst_data, const int mask_rad);
}
