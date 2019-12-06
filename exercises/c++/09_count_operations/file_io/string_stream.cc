#include <fstream>
#include <sstream>

/* Create a file with name dynamically changing */
int main() {
  std::string base_name{"file_"};
  for (auto i = 0; i < 10; ++i) {
    std::stringstream ss; /* string stream allows you to create a composed string using << */
    ss << base_name << i << ".txt"; /* int and so on are automatically converted in a string */
    std::ofstream f{ss.str()};
    f << i << std::endl;
  }

  return 0;
}
