package main

// #cgo CFLAGS: -I${SRCDIR}/../../csrc
// #cgo LDFLAGS: -L${SRCDIR}/../../lib -lfoo -lstdc++
// #include "bridge.hpp"
import "C"

import (
	"fmt"
	"unsafe"
)

func main() {
	rows := 2
	cols := 3
	src := make([]byte, rows*cols*3)
	dst := make([]byte, rows*cols*3)
	for i := 0; i < rows*cols*3; i++ {
		src[i] = byte(i + 4)
	}
	srcp := unsafe.Pointer(&src[0])
	dstp := unsafe.Pointer(&dst[0])
	fmt.Printf("In: %#v\n", src)
	C.testbridge(srcp, C.int(rows), C.int(cols), dstp, C.int(2))
	fmt.Printf("Out: %#v\n", dst)
}
