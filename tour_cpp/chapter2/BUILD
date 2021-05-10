load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "vector_lib",
    srcs = [
        "vector.cc",
    ],
    hdrs = [
        "vector.h",
    ],
    visibility = [
        "//visibility:public",
    ],
)

cc_binary(
    name = "vector_main",
    srcs = [
        "vector_main.cc",
    ],
    deps = [
        ":vector_lib",
    ],
)

cc_binary(
    name = "union_main",
    srcs = [
        "union_main.cc",
    ],
    deps = [
        "@com_google_absl//absl/strings:str_format",
    ],
)
