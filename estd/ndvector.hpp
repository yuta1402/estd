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

        using index_container_type = std::vector<size_t>;

    public:
        template<class... Args>
        ndvector(Args... args) :
            dim_{ sizeof...(args) },
            size_{},
            data_{},
            bases_{},
            dims_{}
        {
            bases_.resize(dim_);
            dims_.resize(dim_);
            size_ = init(0, args...);
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

        size_t size(size_t d) const { return dims_[d]; }

    private:
        template<class T>
        size_t init(size_t d, T v)
        {
            bases_[d] = 1;
            dims_[d] = v;
            return v;
        }

        template<class T, class... Args>
        size_t init(size_t d, T v, Args... args)
        {
            size_t b = init(d+1, args...);
            bases_[d] = b;
            dims_[d] = v;
            return (v * b);
        }

        template<class T>
        size_t calc_index(size_t d, T i) const
        {
            return (i*bases_[d]);
        }

        template<class T, class... Args>
        size_t calc_index(size_t d, T i, Args... args) const
        {
            return (i*bases_[d] + calc_index(d+1, args...));
        }

    private:
        size_t dim_;
        size_t size_;
        container_type data_;
        index_container_type bases_;
        index_container_type dims_;
    };
}

#endif
