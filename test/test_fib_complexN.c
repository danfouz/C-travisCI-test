
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ctest.h"
#include "../src/fib_complexN.c"

//Caso de Prueba PR-UN-002
CTEST(suite1, test1) {
	ASSERT_EQUAL(fib2(10),55);
}
//Caso de Prueba PR-UN-005
//CTEST(suite1, test2) {
  // ASSERT_FAIL(fib2(-5));
//}
//Caso de Prueba PR-UN-008
CTEST(suite1, test3) {
	ASSERT_EQUAL(fib2(0),0);

}

CTEST(suite1, test4) {
	ASSERT_EQUAL(fib2(1),1);

}
CTEST(suite1, test5) {
	ASSERT_EQUAL(fib2(1000000),1884755131);

}
