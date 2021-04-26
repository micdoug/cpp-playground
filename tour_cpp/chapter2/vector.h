#pragma once

namespace tcpp
{
    class Vector
    {
    public:
        Vector(int size);
        virtual ~Vector();

        double& operator[](int index) const;

        const int size() const;

    private:
        double *elements_;
        int size_;
    };

}