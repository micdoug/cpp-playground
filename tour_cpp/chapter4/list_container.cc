#include "tour_cpp/chapter4/list_container.h"

#include <stdexcept>

namespace tcpp {

namespace {
class ListContainerIterator : public ContainerIterator {
 public:
  explicit ListContainerIterator(std::list<double>::iterator iterator)
      : iterator_{iterator} {}
  ~ListContainerIterator() = default;
  double& operator*() { return *iterator_; }
  ContainerIterator& operator++() {
    iterator_++;
    return *this;
  }
  ContainerIterator& operator++(int increment) {
    iterator_++;
    return *this;
  }
  bool operator==(const ContainerIterator& other) {
    try {
      const auto& casted = dynamic_cast<const ListContainerIterator&>(other);
      return casted.iterator_ == iterator_;
    } catch (std::bad_cast& e) {
      return false;
    }
  }

 private:
  std::list<double>::iterator iterator_;
};
}  // namespace

int ListContainer::size() const { return list_.size(); }

double& ListContainer::operator[](int index) {
  if (index < 0 || index >= static_cast<int>(list_.size())) {
    throw std::invalid_argument("out of bounds index");
  }
  auto iter = list_.begin();
  while (index) {
    iter++;
    index--;
  }
  return *iter;
}

const double& ListContainer::operator[](int index) const {
  if (index < 0 || index >= static_cast<int>(list_.size())) {
    throw std::invalid_argument("out of bounds index");
  }
  auto iter = list_.begin();
  while (index) {
    iter++;
    index--;
  }
  return *iter;
}

ContainerIteratorProxy ListContainer::begin() {
  std::list<double>::iterator iter = list_.begin();
  return ContainerIteratorProxy{new ListContainerIterator{iter}};
}

ContainerIteratorProxy ListContainer::end() {
  return ContainerIteratorProxy{new ListContainerIterator{list_.end()}};
}

void ListContainer::push_back(double value) {
  list_.push_back(value);
}

}  // namespace tcpp