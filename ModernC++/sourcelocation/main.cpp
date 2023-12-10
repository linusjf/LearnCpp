#include <source_location>
#include <iostream>
#include <string>

/**
https://www.linkedin.com/posts/ramtintjb_cplusplus-datastructuresandalgorithms-activity-7138875647031971840-QPD8
*/
void log(const std::string& msg,
    const std::source_location loc =
    std::source_location::current()) {
  std::cout
    << loc.file_name() << '('
    << loc.line() << ':'
    << loc.column() << ')' << "\n\t"
    << loc.function_name() << ": "
    << msg << "\n";
}

int main(int _argc, const char** _argv) {
  log("Hello!");
  return 0;
}
