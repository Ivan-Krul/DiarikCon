#include <iostream>
#include "WorkWeek.h"
int main()
{
    WorkWeek wwk;
    wwk.load(L"week.dat");

    std::wcout << wwk.wform();
}
