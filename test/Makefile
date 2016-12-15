UNAME=$(shell uname)

CCFLAGS=-Wall -Wextra -Wno-unused-parameter -O3

ifeq ($(UNAME), Darwin)
LDFLAGS=-Wl,-flat_namespace,-undefined,dynamic_lookup
endif

all: testlogN testN testN1_6

remake: clean all

%.o: %.c ctest.h
	gcc $(CCFLAGS) -c -o $@ $<

testlogN: main.o ctest.h test_fib_complexlogN.o 
	gcc $(LDFLAGS) main.o test_fib_complexlogN.o -o test_fib_complexlogN -lm

testN: main.o ctest.h test_fib_complexN.o 
	gcc $(LDFLAGS) main.o test_fib_complexN.o -o test_fib_complexN -lm

testN1_6: main.o ctest.h test_fib_complexN1_6.o 
	gcc $(LDFLAGS) main.o test_fib_complexN1_6.o -o test_fib_complexN1_6 -lm

clean:
	rm -f test_fib_complexlogN test_fib_complexN test_fib_complexN1_6 *.o

