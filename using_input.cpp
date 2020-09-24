#include <iostream>
#include <unistd.h>

void child(void) {

  char *args[3];
  args[0] = (char *)"ls";
  args[1] = (char *)"-l";
  args[2] = nullptr;
  execv("/bin/ls", args);
}
int main(void) {

  int CtoP[2];
  pipe(CtoP);

  auto fid = fork();
  if (fid == 0) {
    dup2(CtoP[1], STDOUT_FILENO);
    close(CtoP[0]);
    close(CtoP[1]);
    child();
    std::exit(0);
  } else if (fid < 0) {
    std::exit(1);
  }

  // child is running

  dup2(CtoP[0], STDIN_FILENO);
  close(CtoP[0]);
  close(CtoP[1]);

  while (!std::cin.eof()) {
    std::string line;
    std::getline(std::cin, line);
    std::cout << "[P]: " << line << "\n";
  }

  int status;
  waitpid(fid, &status, 0);
  std::cout << "child finished with status: " << status << "\n";
}
