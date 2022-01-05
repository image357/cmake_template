//
// Created by koepke on 24.06.2021.
//

#include <thread>
#include <sub1/ClassA.h>
#include <sub2/ClassB.h>

void a_func()
{
    sub1::ClassA a;
}

void b_func()
{
    sub2::ClassB b;
}

int main()
{
    std::thread a_thread(a_func);
    std::thread b_thread(b_func);

    a_thread.join();
    b_thread.join();
    return 0;
}
