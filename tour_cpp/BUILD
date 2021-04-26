load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "using_flags",
    srcs = [
        "using_flags.cc",
    ],
    deps = [
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:str_format",
    ],
)
