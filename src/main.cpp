#include <regex>

#include <fmt/format.h>
//#include <catch2/catch_all.hpp>

int main()
{
	std::regex re{"abc*|[0-9]+"};

	fmt::print("{}",std::regex_match("123",re));

	return 0;
}