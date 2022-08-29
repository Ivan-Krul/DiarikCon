#include <iostream>
#include "Lesson.h"
int main()
{
    Lesson les(L"math",L"ex 1 p 143");
    std::wcout << les.out();
}
