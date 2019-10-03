#include "test.hpp"
#include "ndvector.hpp"

void ndvector_size_test()
{
    {
        estd::ndvector<int> v(3);
        eassert(v.size(0) == 3, "v.size(0) == %ld", v.size(0));
    }

    {
        estd::ndvector<int> v(2, 5);
        eassert(v.size(0) == 2, "v.size(0) == %ld", v.size(0));
        eassert(v.size(1) == 5, "v.size(1) == %ld", v.size(1));
    }

    {
        estd::ndvector<int> v(2, 2, 3);
        eassert(v.size(0) == 2, "v.size(0) == %ld", v.size(0));
        eassert(v.size(1) == 2, "v.size(1) == %ld", v.size(1));
        eassert(v.size(2) == 3, "v.size(2) == %ld", v.size(2));
    }
}

void ndvector_3dim_test()
{
    estd::ndvector<int> v(2, 2, 3);

    int c = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                v(i, j, k) = c;
                ++c;
            }
        }
    }

    c = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                eassert(v(i, j, k) == c, "v(i, j, k) == %d, c == %d", v(i, j, k), c);
                ++c;
            }
        }
    }
}

void ndvector_test()
{
    ndvector_size_test();
    ndvector_3dim_test();
}
