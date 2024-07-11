#include <cstdio>
#include <random>

struct xorshift32 {

    uint32_t a;

    using result_type = uint32_t;

    explicit xorshift32(uint32_t seed = 0) : a(static_cast<uint32_t>(seed + 1)) {}

    constexpr uint32_t operator()() noexcept {
        auto x = a;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a = x;
        return a;
    }

    static constexpr uint32_t min() noexcept { return 0; }

    static constexpr uint32_t max() noexcept { return UINT32_MAX; }
};

struct wangshash {

        uint32_t a;

        using result_type = uint32_t;

        explicit wangshash(uint32_t seed = 0) : a(static_cast<uint32_t>(seed + 1)) {}

        constexpr uint32_t operator()() noexcept {
            uint32_t x = a;
            x = (x ^ 61) ^ (x >> 16);
            x *= 9;
            x = x ^ (x >> 4);
            x *= 0x27d4eb2d;
            x = x ^ (x >> 15);
            return a = x;
        }

        static constexpr uint32_t min() noexcept { return 0; }

        static constexpr uint32_t max() noexcept { return UINT32_MAX; }

};


int main() {
    std::mt19937 rng(1);
    std::uniform_int_distribution<int> uni(0, 100); // random number between 0 and 100
    for (int i = 0; i < 10; i++) {
        int num = uni(rng);
        printf("Random number: %d\n", num);
    }
    return 0;
}