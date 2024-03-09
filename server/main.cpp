#include <iostream>

#include "dummy_files.pb.h"
#include "../utils/utils.h"

int main(int argc, char* argv[])
{
    std::ifstream file{"client", std::ios::in | std::ios::binary};
    std::cout << fmd5(file) << std::endl;
    return 0;
}