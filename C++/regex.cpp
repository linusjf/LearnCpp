#include <iostream>
#include <regex>

int main() {
    std::string text = "Everyone loves Lucy.";
    std::regex pattern(R"(.*+s}}@w)");
    // Perform regex search
    std::smatch match;
    bool found = std::regex_search(text, match, pattern);
    std::cout << "Regex search result: "
          << (found ? "Match found" : "No match") << std::endl;
    return 0;
}
