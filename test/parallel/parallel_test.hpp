#include <vector>
#include "test.hpp"
#include "parallel.hpp"

void parallel_for_test()
{
    {
        estd::parallel_for(0, [](const auto& i){
        });
    }

    {
        std::vector<int> v(1, 1);

        estd::parallel_for(v.size(), [&v](const auto& i){
            v[i] = 0;
        });

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == 0, "v[%lu] == %d", i, v[i]);
        }
    }

    {
        std::vector<int> v(32, 1);

        estd::parallel_for(v.size(), [&v](const auto& i){
            v[i] = 0;
        });

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == 0, "v[%lu] == %d", i, v[i]);
        }
    }

    {
        std::vector<int> v(50, 1);

        estd::parallel_for(v.size(), [&v](const auto& i){
            v[i] = 0;
        });

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == 0, "v[%lu] == %d", i, v[i]);
        }
    }
}

void parallel_test()
{
    parallel_for_test();
}
