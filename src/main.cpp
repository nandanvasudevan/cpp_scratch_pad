#include <fmt/format.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE(fmt::format("{}!","Hello"))
{
	REQUIRE(1 == 1);
}
