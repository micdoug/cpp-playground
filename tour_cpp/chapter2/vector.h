#pragma once
#include <initializer_list>
#include <iostream>

namespace tcpp
{
    class Vector
    {
    public:
        Vector();
        explicit Vector(int size);
        Vector(std::initializer_list<double> values);
        virtual ~Vector();

        double &operator[](int index) const;

        const int size() const;

        double* begin() const;
        double* end() const;

        void push_back(double value);

    private:
        double *elements_ = nullptr;
        int size_ = 0;
    };

    std::ostream &operator<<(std::ostream &out, const tcpp::Vector &vector);
}
