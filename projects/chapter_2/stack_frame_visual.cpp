// stack_frame_visual.cpp
#include <iostream>
int foo(int x, int y)
{
    int z = x + y;
    return z;
}
int main()
{
    int m = 5;
    int n = 6;
    int p = 0;
    p = foo(m, n);
    std::cout << "Result of addition z = " << p << std::endl;
    return 0;
}