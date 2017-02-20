#include <iostream>
#include "TutorialConfig.h"

#ifdef USE_
#include "customlib/libone.h"
#endif


int main() {
    std::cout << "Hello, World!" << Tutorial_VERSION_MAJOR << "!" << std::endl;
#ifdef  USE_
    func();
#endif
    return 0;
}