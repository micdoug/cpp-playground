#include <iostream>
#include <memory>

#include "glog/logging.h"
#include "tour_cpp/chapter4/container.h"
#include "tour_cpp/chapter4/list_container.h"
#include "tour_cpp/chapter4/vector_container.h"

using tcpp::Container;
using tcpp::ListContainer;
using tcpp::VectorContainer;

void print(Container& container) {
  for (const double& value : container) {
    std::cout << value << std::endl;
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
  VectorContainer container;
  container.push_back(42);
  container.push_back(10);

  print(container);

  ListContainer list_container;
  list_container.push_back(1);
  list_container.push_back(2);
  list_container.push_back(3);

  print(list_container);

  std::cout << list_container[3] << std::endl;

  return 0;
}