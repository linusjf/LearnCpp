#include <source_location>
#include <iostream>
#include <string>

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
