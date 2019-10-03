#include "test.hpp"
#include "ndvector.hpp"

void ndvector_test()
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
