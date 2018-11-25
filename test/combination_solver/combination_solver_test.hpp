#include "test.hpp"
#include "combination_solver.hpp"

void combination_solver_test()
{
    {
        estd::combination_solver comb(0);
        eassert(comb(0, 0) == 1, "comb(0, 0) == %ld", comb(0, 0));
    }

    {
        estd::combination_solver comb(1);
        eassert(comb(0, 0) == 1, "comb(0, 0) == %ld", comb(0, 0));
        eassert(comb(1, 0) == 1, "comb(1, 0) == %ld", comb(1, 0));
        eassert(comb(1, 1) == 1, "comb(1, 1) == %ld", comb(1, 1));
    }

    {
        estd::combination_solver comb(3);
        eassert(comb(3, 0) == 1, "comb(3, 0) == %ld", comb(3, 0));
        eassert(comb(3, 1) == 3, "comb(3, 1) == %ld", comb(3, 1));
        eassert(comb(3, 2) == 3, "comb(3, 2) == %ld", comb(3, 2));
        eassert(comb(3, 3) == 1, "comb(3, 3) == %ld", comb(3, 3));
    }
}
