#include <cstdio>
#include <memory>
#include <string>

using namespace std;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"

struct CloseFile {
  void operator()(FILE *file) {
    fclose(file);
  }
};

void write_to_file(const string &s) {
  unique_ptr<FILE, CloseFile> file{fopen("hello-world.txt", "a")};
  fprintf(file.get(), s.c_str());
}

int main() {
  write_to_file("Hello, ");
  write_to_file("world!\n");
}

#pragma clang diagnostic pop
