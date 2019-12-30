#include <string>
#include "test.hpp"
#include "discrete_distribution.hpp"
#include "random.hpp"

void discrete_distribution_test()
{
    {
        estd::discrete_distribution<int> dist({ 0.0, 1.0 }, { 0, 1 });

        for (int i = 0; i < 10; ++i) {
            auto r = dist();
            eassert(r == 1, "r == %d", r);
        }
    }

    {
        estd::discrete_distribution<std::string> dist({ 1.0, 0.0 }, { "hoge", "fuga" });

        for (int i = 0; i < 10; ++i) {
            auto r = dist();
            eassert(r == "hoge", "r == %s", r.c_str());
        }
    }
}
