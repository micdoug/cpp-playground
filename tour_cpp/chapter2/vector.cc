#include "tour_cpp/chapter2/vector.h"
#include <stdexcept>
#include <algorithm>

namespace tcpp
{
    Vector::Vector() : elements_{nullptr}, size_{0} {}
    Vector::Vector(int size)
    {
        if (size < 0)
        {
            throw std::length_error{"Vector constructor: negative size value."};
        }
        elements_ = new double[size];
        size_ = size;
    }

    Vector::Vector(std::initializer_list<double> values)
    {
        elements_ = new double[values.size()];
        size_ = static_cast<int>(values.size());
        std::copy(values.begin(), values.end(), elements_);
    }

    Vector::~Vector()
    {
        delete[] elements_;
    }
    double &Vector::operator[](int index) const
    {
        if (index < 0 or index >= size_)
        {
            throw std::out_of_range{"out of range"};
        }
        return elements_[index];
    }

    const int Vector::size() const
    {
        return size_;
    }

    double *Vector::begin() const
    {
        return elements_;
    }

    double *Vector::end() const
    {
        return elements_ + size_;
    }

    void Vector::push_back(double value)
    {
        double *old_elements = elements_;
        elements_ = new double[size_ + 1];
        std::copy(old_elements, old_elements + size_, elements_);
        delete[] old_elements;
        elements_[size_] = value;
        size_++;
    }

    std::ostream &operator<<(std::ostream &out, const tcpp::Vector &vector)
    {
        out << "{";
        for (const double &value : vector)
        {
            out << value << ", ";
        }
        out << "}";
        return out;
    }

}