#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include "perfectForwarding.h"

void wrapped_function(int& x)
{
    std::cout << "int& is called\n";
}

void wrapped_function(int&& x)
{
    std::cout << "int&& is called\n";
}

void wrapped_function(const int& x)
{
    std::cout << "const int& is called\n";
}

template<class T>
void wrapper_function(T&& x)
{
    wrapped_function(myForward<T>(x));
}

int main()
{
    int x{};
    const int y{};
    wrapper_function(x);
    wrapper_function(10);
    wrapper_function(y);
  
    return 0;
}

