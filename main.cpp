#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <random>

struct xorshift32 {

    using result_type = uint32_t;

    result_type a;


    explicit xorshift32(result_type seed = 0) : a(static_cast<result_type>(seed + 1)) {}

    constexpr result_type operator()() noexcept {
        auto x = a;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a = x;
        return a;
    }

    static constexpr result_type min() noexcept { return std::numeric_limits<result_type>::min(); }

    static constexpr result_type max() noexcept { return std::numeric_limits<result_type>::max(); }
};

struct wangshash {

        using result_type = uint32_t;

        result_type a;

        explicit wangshash(result_type seed = 0) : a(static_cast<result_type>(seed + 1)) {}

        constexpr result_type operator()() noexcept {
            auto x = a;
            x = (x ^ 61) ^ (x >> 16);
            x *= 9;
            x = x ^ (x >> 4);
            x *= 0x27d4eb2d;
            x = x ^ (x >> 15);
            return a = x;
        }

        static constexpr result_type min() noexcept { return std::numeric_limits<result_type>::min(); }

        static constexpr result_type max() noexcept { return std::numeric_limits<result_type>::max(); }

};


int main() {
    std::vector<float> gailv = {0.6f, 0.25f, 0.05f, 0.1f};
    std::vector<float> gailv_scanned;
    std::inclusive_scan(gailv.begin(), gailv.end(), std::back_inserter(gailv_scanned));
    for (float i : gailv_scanned) {
        printf("%f\n", i);
    }
    std::vector<std::string> lian = {"mushi", "she", "enlosi", "wuya"};
    xorshift32 rng{std::random_device{}()};
    std::uniform_real_distribution<float> unf(0.0f, 1.0f);
    auto genlian = [&] () -> std::string {
        float f = unf(rng);
        auto it = std::lower_bound(gailv_scanned.begin(), gailv_scanned.end(), f);
        if (it == gailv_scanned.end()) return "";
        return lian[it - gailv_scanned.begin()];
    };
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    std::cout << genlian() << '\n';
    return 0;
}