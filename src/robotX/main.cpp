#include <iostream>
#include <utils/utils.h>

#include <utils/JSONConfigureFile.h>
#include <utils/IConfigure.h>
#include <unistd.h>

using namespace Utils;
int main() {
    char current_path[256] = {0};
    getcwd(current_path,256);
    std::cout << "Hello, World! " << std::endl;
    printf("current path：%s \n",current_path);

    JSONConfigureFile jsonConfig;
    jsonConfig.readConfigureFile("../default.conf");


    printf("name %s\n",jsonConfig.getConfigure("/people")->getString("name"));

    return 0;
}