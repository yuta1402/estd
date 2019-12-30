#include <vector>
#include <thread>
#include <future>
#include "test.hpp"
#include "random.hpp"

void default_random_engine_class_test()
{
    {
        estd::detail::DefaultRandomEngine e;
        for (int i = 0; i < 9999; ++i) {
            e();
        }

        auto r = e(); eassert(r == 4123659995, "r == %d", r);
        eassert(e.generate_count() == 10000, "e.generate_count() == %lu", e.generate_count());
    }

    {
        estd::detail::DefaultRandomEngine e0(0);
        for (int i = 0; i < 9999; ++i) {
            e0();
        }

        estd::detail::DefaultRandomEngine e1(0, 9999);

        auto r0 = e0(); auto r1 = e1(); eassert(r0 == r1, "r0 == %d, r1 == %d", r0, r1);
    }

    {
        estd::detail::DefaultRandomEngine e0(0);
        for (int i = 0; i < 9999; ++i) {
            e0();
        }

        estd::detail::DefaultRandomEngine e1;
        e1.reseed(0, 9999);

        auto r0 = e0(); auto r1 = e1(); eassert(r0 == r1, "r0 == %d, r1 == %d", r0, r1);
    }
}

void get_default_random_engine_test()
{
    auto e = estd::GetDefaultRandomEngine();
    e.reseed(0);

    auto f = std::async(std::launch::async, [](){
        auto e = estd::GetDefaultRandomEngine();
        return e.seed();
    });

    auto s0 = e.seed();
    auto s1 = f.get();

    eassert(s0 == 0, "s0 == %d", s0);
    eassert(s1 == estd::detail::DefaultRandomEngine::default_seed, "s1 == %d", s1);
}

void default_random_engine_test()
{
    default_random_engine_class_test();
    get_default_random_engine_test();
}
