#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_chronometer.hpp>

#include <boost/uuid/name_generator.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/name_generator_md5.hpp>

#include <uuid/uuid.h>

static constexpr const char *const sTag = "[uuid]";

TEST_CASE("Random UUID generator",
          sTag)
{
    BENCHMARK_ADVANCED("[Boost] Simple random")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::random_generator gen;
            chronometer.measure([&] { return gen(); });
        };

    BENCHMARK_ADVANCED("[Boost] Bulk generator")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::random_generator_mt19937 bulkgen;
            chronometer.measure([&] { return bulkgen(); });
        };

    BENCHMARK_ADVANCED("[POSIX]")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            chronometer.measure([&] {
                uuid_generate_random(uuid);
                return *uuid;
            });
        };

    BENCHMARK("POSIX")
                {
                    uuid_t uuid;
                    uuid_generate_random(uuid);
                    return *uuid;
                };
}

TEST_CASE("String generator",
          sTag)
{
    static constexpr const char *const sInputText = "I love C++";
    BENCHMARK_ADVANCED("[Boost] SHA1 - DNS")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_sha1 generator(boost::uuids::ns::dns());
            chronometer.measure([&]() { return generator(sInputText); });
        };

    BENCHMARK_ADVANCED("[Boost] SHA1 - OID")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_sha1 generator(boost::uuids::ns::oid());
            chronometer.measure([&]() { return generator(sInputText); });
        };

    BENCHMARK_ADVANCED("[Boost] SHA1 - URL")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_sha1 generator(boost::uuids::ns::url());
            chronometer.measure([&]() { return generator(sInputText); });
        };


    BENCHMARK_ADVANCED("[Boost] SHA1 - x500")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_sha1 generator(boost::uuids::ns::x500dn());
            chronometer.measure([&]() { return generator(sInputText); });
        };
    BENCHMARK_ADVANCED("[Boost] MD5 - DNS")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_md5 generator(boost::uuids::ns::dns());
            chronometer.measure([&]() { return generator(sInputText); });
        };

    BENCHMARK_ADVANCED("[Boost] MD5 - OID")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_md5 generator(boost::uuids::ns::oid());
            chronometer.measure([&]() { return generator(sInputText); });
        };

    BENCHMARK_ADVANCED("[Boost] MD5 - URL")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_md5 generator(boost::uuids::ns::url());
            chronometer.measure([&]() { return generator(sInputText); });
        };


    BENCHMARK_ADVANCED("[Boost] MD5 - x500")(Catch::Benchmark::Chronometer chronometer) {
            boost::uuids::name_generator_md5 generator(boost::uuids::ns::x500dn());
            chronometer.measure([&]() { return generator(sInputText); });
        };

    BENCHMARK_ADVANCED("[POSIX] SHA1 - DNS")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("dns"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_sha1(uuid,
                                   hash,
                                   sInputText,
                                   strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] SHA1 - OID")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("oid"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_sha1(uuid,
                                   hash,
                                   sInputText,
                                   strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] SHA1 - URL")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("url"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_sha1(uuid,
                                   hash,
                                   sInputText,
                                   strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] SHA1 - x500")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("x500"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_sha1(uuid,
                                   hash,
                                   sInputText,
                                   strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] MD5 - DNS")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("dns"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_md5(uuid,
                                  hash,
                                  sInputText,
                                  strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] MD5 - OID")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("oid"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_md5(uuid,
                                  hash,
                                  sInputText,
                                  strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] MD5 - URL")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("url"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_md5(uuid,
                                  hash,
                                  sInputText,
                                  strlen(sInputText));
                return uuid;
            });
        };

    BENCHMARK_ADVANCED("[POSIX] MD5 - x500")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            uuid_t hash;

            memcpy(&hash,
                   uuid_get_template("x500"),
                   sizeof(hash));

            chronometer.measure([&]() {
                uuid_generate_md5(uuid,
                                  hash,
                                  sInputText,
                                  strlen(sInputText));
                return uuid;
            });
        };
}

TEST_CASE("Time based",
          sTag)
{
    BENCHMARK_ADVANCED("[POSIX] Basic")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            chronometer.measure([&]() {
                uuid_generate_time(uuid);
                return uuid;
            });
        };
    BENCHMARK_ADVANCED("[POSIX] Safe")(Catch::Benchmark::Chronometer chronometer) {
            uuid_t uuid;
            chronometer.measure([&]() {
                uuid_generate_time_safe(uuid);
                return uuid;
            });
        };
}
