//
// Created by koepke on 24.06.2021.
//

#include <cmake_tutorial/sub2/ClassB.h>

#include <iostream>
#include "internal.h"

namespace sub2 {

ClassB::ClassB()
{
    std::cout << ::sub2::message << std::endl;
}

}
