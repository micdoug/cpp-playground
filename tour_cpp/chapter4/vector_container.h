#pragma once

#include "tour_cpp/chapter4/container.h"
#include "tour_cpp/chapter2/vector.h"

namespace tcpp
{
    class VectorContainer : public Container
    {
    public:
        virtual ~VectorContainer() = default;
        double &operator[](int index) override;
        const double &operator[](int index) const override;
        int size() const override;

        void push_back(double value);
        ContainerIteratorProxy begin() override;
        ContainerIteratorProxy end() override;

    private:
        Vector vector_;
    };
}