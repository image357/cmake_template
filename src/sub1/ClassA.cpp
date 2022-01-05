//
// Created by koepke on 24.06.2021.
//

#include <cmake_tutorial/sub1/ClassA.h>

#include <iostream>
#include "internal.h"

namespace sub1 {

ClassA::ClassA()
{
    std::cout << ::sub1::message << std::endl;
}

}
