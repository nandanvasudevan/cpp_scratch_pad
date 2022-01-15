#include <unordered_map>

#include <fmt/format.h>
#include <catch2/catch_all.hpp>

static constexpr int insertion_count = 100;
static constexpr int index_to_access = insertion_count - 1;

template<typename T>
void
insert(T &container, const int count) {
	for (int i = 0; i < count; i++) {
		container.insert(std::make_pair(i, 42));
	}
}

std::unordered_map<int, int> unordered_mapInt;
std::map<int, int> mapInt;

TEST_CASE("For unordered map")
{
	unordered_mapInt.clear();

	SECTION("Inserting elements")
	{
		static constexpr int iInserted = 2;
		insert(unordered_mapInt, iInserted);
		REQUIRE(iInserted == unordered_mapInt.size());
	}

	BENCHMARK(fmt::format("Insert {} elements", insertion_count))
				{
					return insert(unordered_mapInt, insertion_count);
				};

	BENCHMARK(fmt::format("Access {}th element", index_to_access))
				{
					return unordered_mapInt[index_to_access];
				};
}

TEST_CASE("For map")
{
	mapInt.clear();

	SECTION("Inserting elements")
	{
		static constexpr int iInserted = 2;
		insert(mapInt, iInserted);
		REQUIRE(iInserted == mapInt.size());
	}

	BENCHMARK(fmt::format("Insert {} elements", insertion_count))
				{
					return insert(mapInt, insertion_count);
				};

	BENCHMARK(fmt::format("Access {}th element", index_to_access))
				{
					return mapInt[index_to_access];
				};
}
