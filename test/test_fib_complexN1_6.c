
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ctest.h"
#include "../src/fib_complexN1_6.c"

CTEST(suite2, test1) {
	ASSERT_EQUAL(fib1(10),55);
}
CTEST(suite1, test2) {
   ASSERT_EQUAL(fib1(64),1231);
}
CTEST(suite2, test3) {
	ASSERT_EQUAL(fib1(0),0);

}
CTEST(suite2, test4) {
	ASSERT_EQUAL(fib1(1),1);

}
