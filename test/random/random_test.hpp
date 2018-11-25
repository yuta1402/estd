#include "test.hpp"
#include "random.hpp"

void random_func_test()
{
    estd::Reseed(0);

    auto r = estd::Random(0);
    eassert(r == 0, "r == %d", r);

    for (int i = 0; i < 10; ++i) {
        auto r = estd::Random(-1, 3);
        eassert(-1 <= r && r <= 3, "r == %d", r);
    }

    for (int i = 0; i < 10; ++i) { 
        auto r = estd::Random(3);
        eassert(0 <= r && r <= 3, "r == %d", r);
    }
}

void random_bool_test()
{
    estd::Reseed(0);

    for (int i = 0; i < 10; ++i) {
        auto b = estd::RandomBool(1.0);
        eassert(b == true, "b must be true.");
    }

    for (int i = 0; i < 10; ++i) {
        auto b = estd::RandomBool(0.0);
        eassert(b == false, "b must be false.");
    }
}

void random_multiple_test()
{
    estd::Reseed(0);

    {
        auto v = estd::RandomMultiple(-1, 8, 10);

        for (const auto& vi : v) {
            eassert(-1 <= vi && vi <= 8, "vi == %d", vi);
        }
    }

    {
        auto v = estd::RandomMultiple(9, 10);

        for (const auto& vi : v) {
            eassert(0 <= vi && vi <= 9, "vi == %d", vi);
        }
    }

    {
        auto v = estd::RandomMultiple(0, 10);
        eassert(v.size() == 1, "v.size() == %lu", v.size());
        eassert(v[0] == 0, "v[0] == %d", v[0]);
    }
}

void random_test()
{
    random_func_test();
    random_bool_test();
    random_multiple_test();

    // TODO: estd::RandomMultipleSelectのテストを書く
    // TODO: estd::Shuffleのテストを書く
}
