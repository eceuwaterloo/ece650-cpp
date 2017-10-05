// adapted from https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
#include <unistd.h>
#include <iostream>

/// main() must be declared with arguments
/// otherwise command line arguments are ignored
int main (int argc, char **argv)
{
    bool aflag = 0;
    bool bflag = 0;
    std::string cvalue;
    int cint_value;
    int index;
    int c;

    opterr = 0;

    // expected options are '-a', '-b', and '-c value'
    while ((c = getopt (argc, argv, "abc:")) != -1)
        switch (c)
        {
        case 'a':
            aflag = true;
            break;
        case 'b':
            bflag = true;
            break;
        case 'c':
            cvalue = optarg;
            cint_value = atoi(cvalue.c_str());
            break;
        case '?':
            if (optopt == 'c')
                std::cerr << "Error: option -" << optopt
                          << " requires an argument." << std::endl;
            else
                std::cerr << "Error: unknown option: " << optopt << std::endl;
            return 1;
        default:
            return 0;
        }

    std::cout << "aflag=" << aflag << " "
              << "bflag=" << bflag << " "
              << "cvalue=" << cvalue << " "
              << "cint_value=" << cint_value << std::endl;


    if (optind < argc) {
        std::cout << "Found positional arguments\n";
        for (index = optind; index < argc; index++)
            std::cout << "Non-option argument: " << argv[index] << "\n";
    }

    return 0;
}
