#include<unistd.h>
#include <iostream>
int main(void) {


    char* argv[3];

    argv[0] = (char*)"ls";
    argv[1] = (char*)"-l";
    argv[2] = nullptr;
    std::cout << "[exec] executing '/bin/ls -l' using execv" << std::endl;

    pid_t kid;
    kid = fork ();
    if (kid == 0) {
        sleep (4);
        execv ("/bin/ls", argv);
        // execl("/bin/ls", "ls", "-l", nullptr);
        perror ("Error from arie");
        return 1;
    }

    int res;
    waitpid(kid, &res, 0);
    std::cout << "ls returned status: " << res << std::endl;

    return 0;
}
