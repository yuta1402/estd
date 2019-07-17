#include <vector>
#include "test.hpp"
#include "parallel.hpp"

void parallel_for_test()
{
    {
        estd::parallel_for(0, []([[maybe_unused]] const auto& i){
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

void parallel_sort()
{
    {
        std::vector<size_t> v{ 5, 3, 1, 4, 0, 2, 7, 6 };
        estd::parallel_sort(std::begin(v), std::end(v), 4);

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == i, "v[%lu] == %lu", i, v[i]);
        }
    }

    {
        std::vector<size_t> v{ 5, 3, 1, 4, 0, 2, 7, 6 };
        estd::parallel_sort(v, 4);

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == i, "v[%lu] == %lu", i, v[i]);
        }
    }

    {
        std::vector<size_t> v{ 5, 3, 1, 4, 0, 2, 7, 6 };
        estd::parallel_sort_by(std::begin(v), std::end(v), [](const auto& x, const auto& y){ return x > y; }, 4);

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == v.size()-1-i, "v[%lu] == %lu", i, v[i]);
        }
    }

    {
        std::vector<size_t> v{ 5, 3, 1, 4, 0, 2, 7, 6 };
        estd::parallel_sort_by(v, [](const auto& x, const auto& y){ return x > y; }, 4);

        for (size_t i = 0; i < v.size(); ++i) {
            eassert(v[i] == v.size()-1-i, "v[%lu] == %lu", i, v[i]);
        }
    }
}

void parallel_test()
{
    parallel_for_test();
    parallel_sort();

    // TODO: parallel_for_eachのテストを書く
    // TODO: parallel_for_with_reseedのテストを書く
    // TODO: parallel_for_each_with_reseedのテストを書く
    // TODO: parallel_sumのテストを書く
}
