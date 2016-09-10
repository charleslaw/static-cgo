#include "foo.hpp"
#include "bridge.hpp"
#include <stdint.h> //for uint8
#include <stdio.h> //printf

void testbridge(void * srcv, int rows, int cols, void * dstv, int radius){
    printf("in bridge: rows:%d, cols:%d, rad:%d\n", rows, cols, radius);
    const uint8_t * src_data = (uint8_t *) srcv;
    uint8_t* dst_data = (uint8_t *) dstv;
    foo::bar(src_data, rows, cols, dst_data, radius);
}
