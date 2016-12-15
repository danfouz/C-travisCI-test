
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ctest.h"
#include "../src/fib_complexlogN.c"

CTEST(suite3, test1) {
	ASSERT_EQUAL(fib3(10),55);
}
//CTEST(suite1, test2) {
  // ASSERT_FAIL(fib2(-5));
//}
CTEST(suite3, test3) {
	ASSERT_EQUAL(fib3(0),0);

}
CTEST(suite3, test4) {
	ASSERT_EQUAL(fib3(1),1);

}
CTEST(suite3, test5) {
	ASSERT_EQUAL(fib3(1000000),1884755131);

}

