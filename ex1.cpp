#include <iostream>
#include <unistd.h>

void run(void) {
  while (!std::cin.eof()) {
    std::string line;
    std::getline(std::cin, line);
    if (line.size() > 0)
      std::cout << "[OUT-" << getpid() << "]" << line << std::endl;
  }
  std::cout << "[OUT" << getpid() << "]"
            << "EOF" << std::endl;
}

int main(void) {
  pid_t kid;

  kid = fork();
  if (kid == 0) {
    std::cout << "[CHILD]: here" << std::endl;
    run();
    return 0;
  }

  std::cout << "[OUT] started child with pid=" << kid << std::endl;
  run();
  return 0;
}
