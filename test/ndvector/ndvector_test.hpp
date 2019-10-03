#include "ndvector.hpp"

void ndvector_test()
{
    estd::ndvector<int> v(5, 5, 4, 2);
    v(1, 1, 1, 1) = 100;
    std::cout << v(1, 1, 1, 1) << std::endl;
    std::cout << v(0, 1, 1, 1) << std::endl;
}
