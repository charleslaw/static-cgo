#include "foo.hpp"

void foo::bar(const uint8_t * src_data, const int height, const int width, uint8_t* dst_data, const int mask_rad) {
    int offset;
    for (int center_r = 0; center_r < height; ++center_r) {
        for (int center_c = 0; center_c < width; ++center_c) {
            offset = ((center_r*width)+center_c)*3;
            dst_data[offset] = src_data[offset]-mask_rad;
            dst_data[offset+1] = src_data[offset+1]-mask_rad;
            dst_data[offset+2] = src_data[offset+2]-mask_rad;
        }
    }
}
