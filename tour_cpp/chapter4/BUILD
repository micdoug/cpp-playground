load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "container_lib",
    srcs = [
        "list_container.cc",
        "vector_container.cc",
    ],
    hdrs = [
        "container.h",
        "list_container.h",
        "vector_container.h",
    ],
    visibility = [
        "//visibility:public",
    ],
    deps = [
        "//tour_cpp/chapter2:vector_lib",
    ],
)

cc_binary(
    name = "container_main",
    srcs = [
        "container_main.cc",
    ],
    deps = [
        ":container_lib",
        "@com_github_google_glog//:glog",
    ],
)
