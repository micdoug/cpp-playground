#pragma once

#include <list>

#include "tour_cpp/chapter4/container.h"

namespace tcpp {
class ListContainer : public Container {
 public:
  ~ListContainer() = default;
  int size() const override;

  double& operator[](int) override;
  const double& operator[](int) const override;
  ContainerIteratorProxy begin() override;
  ContainerIteratorProxy end() override;

  void push_back(double value);

 private:
  std::list<double> list_;
};
}  // namespace tcpp