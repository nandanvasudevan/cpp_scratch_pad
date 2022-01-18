//! @file: withCTRE.cpp
//! @brief: 
// 
// Created by: nandanv
// Created at: 16/01/2022 08:49
//

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <ctre.hpp>
#include <ctll.hpp>
#include <fmt/printf.h>

TEST_CASE("CTRE")
{
	static constexpr auto patternIP = ctll::fixed_string{"(\\d{2,4}\\.){3}\\d+"};
	static constexpr auto patternDateTime = ctll::fixed_string{"(?=\\[)(.*)(?=\\])"};
	static constexpr auto patternTime = ctll::fixed_string{
			"([^\\[])(\\d{1}\\/\\w+\\/\\d{4})\\:((\\d{2}\\:){2}\\w+)\\s(\\+\\w+)"};
	static constexpr auto
			patternRequestType = ctll::fixed_string{"(GET)|(POST)"};
	static constexpr auto
			patternRequestURL = ctll::fixed_string{"(?!GET\\s+)\\/+\\w*\\.\\w+"};
	static constexpr auto patternType =
			ctll::fixed_string{"(HTTP).(?!\\/)(\\d\\.\\d)"};

// Does not work. Generates a segmentation fault
//	static constexpr auto
//			patternType = ctll::fixed_string{"(HTTP(|S)?).(?!\\/)+\\d\\.\\d"};

	static const auto sInput
			= "66.249.64.13 - - [18/Sep/2004:11:07:48 +1000] "
			  "\"GET /robots.txt HTTP/1.0\" 200 468 "
			  "\"-\" \"Googlebot/2.1";

	auto[svType, svProtocol, svVersion] =ctre::search<patternType>(sInput);

	fmt::print(
			"Output: \n\tIP: {}\n\tDate: {}\n\tRequest: {}\n\t\tURL: {}\n\tType: {}\n\t\tProtocol: {}\n\t\tVersion: {}\n",
			ctre::search<patternIP>(sInput),
			ctre::search<patternDateTime>(sInput).to_string().erase(0, 1),
			ctre::search<patternRequestType>(sInput),
			ctre::search<patternRequestURL>(sInput),
			svType,
			svProtocol,
			svVersion);

	SECTION("Match IP")
	{
		static constexpr auto svExpectedOutput = "66.249.64.13";

		REQUIRE(svExpectedOutput == ctre::search<patternIP>(sInput));
	}
}
