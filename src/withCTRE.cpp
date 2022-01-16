//! @file: withCTRE.cpp
//! @brief: 
// 
// Created by: nandanv
// Created at: 16/01/2022 08:49
//

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <ctre.hpp>
#include <fmt/format.h>

TEST_CASE("CTRE vs std::regex")
{
	static const std::string sExpectOutput = "summer by this sun";
//	static const std::string sInput = "66.249.64.13 - - [18/Sep/2004:11:07:48 +1000] \"GET /robots.txt HTTP/1.0\" 200 468 \"-\" \"Googlebot/2.1";
	static const std::string sInput = "66.249.64.13";

	fmt::print("Output: {}\n",
	           ctre::match<"(^\\d{2})(\\.)">(sInput));
}
