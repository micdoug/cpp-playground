#include <iostream>
#include <string>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/strings/str_format.h"

ABSL_FLAG(std::string, name, "", "Your name");

int main(int argc, char** argv)
{
    absl::SetProgramUsageMessage("using_flags <yourname>");
    absl::ParseCommandLine(argc, argv);

    std::string name = absl::GetFlag(FLAGS_name);
    if (name.empty()) {
        std::cout << "You need to provide your name \n";
        return 1;
    }

    std::cout << absl::StrFormat("Welcome to C++, %s", name) << std::endl;
    return 0;
}