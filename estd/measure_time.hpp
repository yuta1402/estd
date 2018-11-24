#ifndef MEASURE_TIME_HPP
#define MEASURE_TIME_HPP

#include <iostream>
#include <chrono>
#include <string>
#include "stopwatch.hpp"

/*!
@namespace estd
@brief extended std
*/
namespace estd
{
    class measure_time
    {
    public:
        measure_time(const std::string& event_name) :
            event_name_{ event_name },
            stopwatch_{ true }
        {
        }

        ~measure_time()
        {
            auto elapsed = stopwatch_.elapsed();
            std::cout << event_name_ << ": " << elapsed << "[ms]" << std::endl;
        }

    private:
        const std::string event_name_;
        estd::stopwatch stopwatch_;
    };
}

#endif
