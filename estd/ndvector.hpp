#ifndef NDVECTOR_HPP
#define NDVECTOR_HPP

#include <vector>

#include <iostream>

/*!
@namespace estd
@brief extended std
*/
namespace estd
{
    /*!
    @class ndvector
    @brief n-dimensional vector
    */
    template<class Type>
    class ndvector
    {
    public:
        using container_type  = std::vector<Type>;
        using reference       = typename container_type::reference;
        using const_reference = typename container_type::const_reference;

        using base_container_type = std::vector<size_t>;

    public:
        template<class... Args>
        ndvector(Args... args) :
            dim_{ sizeof...(args) },
            size_{},
            data_{},
            base_{}
        {
            size_ = init_base(args...);
            data_.resize(size_);
        }

        ~ndvector() = default;

        template<class... Args>
        reference operator()(Args... args)
        {
            assert(sizeof...(args) == dim_);

            size_t i = calc_index(0, args...);
            return data_[i];
        }

        template<class... Args>
        const_reference operator()(Args... args) const
        {
            assert(sizeof...(args) == dim_);

            size_t i = calc_index(0, args...);
            return data_[i];
        }

    private:
        template<class T>
        size_t init_base(T v)
        {
            base_.emplace_back(1);
            return v;
        }

        template<class T, class... Args>
        size_t init_base(T v, Args... args)
        {
            size_t b = init_base(args...);
            base_.emplace_back(b);
            return (v * b);
        }

        template<class T>
        size_t calc_index(size_t d, T i) const
        {
            return (i*base_[d]);
        }

        template<class T, class... Args>
        size_t calc_index(size_t d, T i, Args... args) const
        {
            return (i*base_[d] + calc_index(d+1, args...));
        }

    private:
        size_t dim_;
        size_t size_;
        container_type data_;
        base_container_type base_;
    };
}

#endif
