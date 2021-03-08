#include <catch2/catch.hpp>
/*
 * Catch2: examples
 * for more examples checkout:
 *   https://github.com/catchorg/Catch2/tree/devel/examples
 *
 * Catch has two natural expression assertion macro's:
 * - REQUIRE() stops at first failure.
 * - CHECK() continues after failure.
 *
 * There are two variants to support decomposing negated expressions:
 * - REQUIRE_FALSE() stops at first failure.
 * - CHECK_FALSE() continues after failure.
 *
 * TEST_CASE( "Title here", "[short name]" ) {
 *     REQUIRE( [BOOLEAN CONDITION] ) ;
 * }
 */


extern "C" {
#include "pair.h"
}

#include <stdio.h>
#include <string.h>

TEST_CASE( "pair create-destroy", "[pair]" ) {
	char *key = strdup("hello");
	char *value = strdup("world");
	t_pair *pair = pair_create((void *)key, (void *)value);
	printf("first=%s\nsecond=%s\n", pair->f.key, (char *)pair->s.second);
	pair_destroy(pair, free, free);
}
