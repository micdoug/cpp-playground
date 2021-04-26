#include "tour_cpp/chapter2/vector.h"

namespace tcpp
{
    Vector::Vector(int size) : elements_{new double[size]}, size_{size} {}
    Vector::~Vector()
    {
        delete[] elements_;
    }
    double &Vector::operator[](int index) const
    {
        return elements_[index];
    }

    const int Vector::size() const {
        return size_;
    }

}