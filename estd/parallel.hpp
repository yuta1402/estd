#ifndef PARALLEL_HPP
#define PARALLEL_HPP

/*!
@class random.hpp
@brief algorithm関連の並列処理
*/

#include <algorithm>
#include <thread>
#include <future>
#include "random.hpp"

/*!
@namespace estd
@brief extended std
*/
namespace estd
{
    template<class Iterator, class Function>
    inline Function parallel_for_each(Iterator begin, Iterator end, Function f)
    {
        if(begin == end) {
            return std::move(f);
        }

        std::size_t num_threads = std::thread::hardware_concurrency();
        std::size_t step = std::max<std::size_t>(1, std::distance(begin, end) / num_threads);

        std::vector<std::thread> threads;

        for(; begin < end - step; begin += step) {
            threads.emplace_back([=, &f](){
                std::for_each(begin, begin + step, f);
            });
        }

        threads.emplace_back([=, &f](){
            std::for_each(begin, end, f);
        });

        for(auto&& t : threads) {
            t.join();
        }

        return std::move(f);
    }

    template<class Container, class Function>
    inline Function parallel_for_each(Container&& c, Function f)
    {
        return parallel_for_each(std::begin(c), std::end(c), f);
    }

    template<class Iterator, class Function, class RandomEngine>
    inline Function parallel_for_each_with_reseed(Iterator begin, Iterator end, Function f, RandomEngine&& engine)
    {
        if(begin == end) {
            return std::move(f);
        }

        std::size_t num_threads = std::thread::hardware_concurrency();
        std::size_t step = std::max<std::size_t>(1, std::distance(begin, end) / num_threads);

        std::vector<std::thread> threads;

        for(; begin < end - step; begin += step) {
            auto seed = engine();

            threads.emplace_back([=, &f](){
                Reseed(seed);
                std::for_each(begin, begin + step, f);
            });
        }

        threads.emplace_back([=, &f](){
            std::for_each(begin, end, f);
        });

        for(auto&& t : threads) {
            t.join();
        }

        return std::move(f);
    }

    template<class Iterator, class Function>
    inline Function parallel_for_each_with_reseed(Iterator begin, Iterator end, Function f)
    {
        return parallel_for_each_with_reseed(begin, end, f, GetDefaultRandomEngine());
    }

    template<class Container, class Function, class RandomEngine>
    inline Function parallel_for_each_with_reseed(Container&& c, Function f, RandomEngine&& engine)
    {
        return parallel_for_each_with_reseed(std::begin(c), std::end(c), f, engine);
    }

    template<class Container, class Function>
    inline Function parallel_for_each_with_reseed(Container&& c, Function f)
    {
        return parallel_for_each_with_reseed(c, f, GetDefaultRandomEngine());
    }

    template<class Iterator, class Type = typename std::iterator_traits<Iterator>::value_type>
    inline Type parallel_sum(Iterator begin, Iterator end)
    {
        if(begin == end) {
            return Type(0);
        }

        std::size_t num_threads = std::thread::hardware_concurrency();
        std::size_t step = std::max<std::size_t>(1, std::distance(begin, end) / num_threads);

        std::vector<std::future<Type>> futures;

        for(; begin < end - step; begin += step) {
            futures.emplace_back(std::async([=](){
                return std::accumulate(begin, begin + step, Type(0));
            }));
        }

        futures.emplace_back(std::async([=](){
            return std::accumulate(begin, end, Type(0));
        }));

        Type sum(0);

        for(auto&& f : futures) {
            sum += f.get();
        }

        return sum;
    }

    template<class Container>
    inline auto parallel_sum(const Container& c)
    {
        return parallel_sum(std::begin(c), std::end(c));
    }
}

#endif
