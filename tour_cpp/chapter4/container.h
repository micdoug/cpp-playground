#pragma once

#include <memory>

namespace tcpp {

class ContainerIterator {
 public:
  virtual ~ContainerIterator() = default;
  virtual double& operator*() = 0;
  virtual ContainerIterator& operator++() = 0;
  virtual ContainerIterator& operator++(int increment) = 0;
  virtual bool operator==(const ContainerIterator& other) = 0;
  bool operator!=(const ContainerIterator& other) {
    return !this->operator==(other);
  }
};

class ContainerIteratorProxy : public ContainerIterator {
 public:
  explicit ContainerIteratorProxy(ContainerIterator* iterator)
      : iterator_{iterator} {}
  ~ContainerIteratorProxy() = default;
  double& operator*() override { return *(*iterator_); }
  ContainerIterator& operator++() override {
    ++(*iterator_);
    return *this;
  }
  ContainerIterator& operator++(int increment) override {
    (*iterator_)++;
    return *this;
  }
  bool operator==(const ContainerIterator& other) override {
    try {
      const auto& casted = dynamic_cast<const ContainerIteratorProxy&>(other);
      return (*iterator_) == (*casted.iterator_);
    } catch (std::bad_cast& e) {
      return false;
    }
  }

 private:
  std::unique_ptr<ContainerIterator> iterator_;
};

class Container {
 public:
  virtual double& operator[](int) = 0;
  virtual const double& operator[](int) const = 0;
  virtual int size() const = 0;
  virtual ~Container() {}

  virtual ContainerIteratorProxy begin() = 0;
  virtual ContainerIteratorProxy end() = 0;
};
}  // namespace tcpp