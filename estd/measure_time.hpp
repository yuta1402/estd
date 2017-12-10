#ifndef MEASURE_TIME_HPP
#define MEASURE_TIME_HPP

#include <chrono>
#include <string>

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
            event_name_{ event_name }
        {
            start_time_ = std::chrono::system_clock::now();
        }

        ~measure_time()
        {
            auto end_time = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time_).count();

            std::cout << event_name_ << ": " << elapsed << std::endl;
        }

    private:
        const std::string event_name_;
        std::chrono::system_clock::time_point start_time_;
    };
}

#endif
