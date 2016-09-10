.PHONY: clean

BASE:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
PROJECT=gblur
TARGET=${BASE}/bin/${PROJECT}
LIB=${BASE}/lib
CSRC=${BASE}/csrc
GOSRC:=$(shell find ${BASE}/src -type f -name \*.go -print)

#TODO: the deps don't seem that reliable here, updating a cpp should update the .o, then the .a, and then the target
${TARGET}: ${LIB}/libfoo.a ${GOSRC}
	env GOPATH=${BASE} go install ${PROJECT}

${LIB}:
	mkdir -p ${LIB}

${LIB}/libfoo.a: ${LIB}/foo.o ${LIB}/bridge.o
	ar r $@ $^

${LIB}/%.o: ${CSRC}/%.cpp | ${LIB}
	gcc -Wall -pedantic -Wreturn-type -Wextra -fPIC -Werror -g -o $@ -c $^

clean:
	rm -f ${LIB}/*.o ${LIB}/*.a
	rm -f ${TARGET}

