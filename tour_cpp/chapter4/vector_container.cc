#include "tour_cpp/chapter4/vector_container.h"

namespace tcpp {

namespace {
class VectorContainerIterator : public ContainerIterator {
 public:
  explicit VectorContainerIterator(double* initial_pointer)
      : current_pointer_{initial_pointer} {}
  ~VectorContainerIterator() = default;
  double& operator*() override { return *current_pointer_; }
  ContainerIterator& operator++() override {
    current_pointer_++;
    return *this;
  }
  ContainerIterator& operator++(int) override {
    current_pointer_++;
    return *this;
  }
  bool operator==(const ContainerIterator& other) override {
    try {
      auto& other_casted = dynamic_cast<const VectorContainerIterator&>(other);
      return current_pointer_ == other_casted.current_pointer_;
    } catch (std::bad_cast& e) {
      return false;
    }
  }

 private:
  double* current_pointer_ = nullptr;
};
}  // namespace

double& VectorContainer::operator[](int index) { return vector_[index]; }

const double& VectorContainer::operator[](int index) const {
  return vector_[index];
}

int VectorContainer::size() const { return vector_.size(); }

void VectorContainer::push_back(double value) { vector_.push_back(value); }

ContainerIteratorProxy VectorContainer::begin() {
  return ContainerIteratorProxy{new VectorContainerIterator{vector_.begin()}};
}

ContainerIteratorProxy VectorContainer::end() {
  return ContainerIteratorProxy{
      new VectorContainerIterator{vector_.end()}};  // namespace tcpp
}

}  // namespace tcpp