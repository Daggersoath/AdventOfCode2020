#pragma once

#include <stdexcept>
#include <algorithm>
#include <vector>

namespace Vector {
    template<typename T>
    inline T PopFront(std::vector<T>& inVec)
    {
        if (auto it = inVec.begin(); it != inVec.end())
        {
            T obj = *it;
            inVec.erase(it);
            return obj;
        }

        throw std::runtime_error("Trying to pop empty vector");
    }

    template<typename T, typename U, typename TransformFunc>
    void Transform(const std::vector<T>& in, std::vector<U>& out, TransformFunc func)
    {
        out.resize(in.size());
        std::transform(in.begin(), in.end(), out.begin(), func);
    }

    template<typename T, typename ElementFetchFunc>
    size_t Sum(std::vector<T> v, ElementFetchFunc func = [](const T& t) {return t; })
    {
        size_t sum = 0;
        for (const T& t : v)
            sum += func(t);
        return sum;
    }
}