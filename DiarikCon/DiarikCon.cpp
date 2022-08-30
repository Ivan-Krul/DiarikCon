#include <iostream>
#include "WorkWeek.h"
#include "Terminal.h"
int main()
{
    WorkWeek wwk;
    wwk.load(L"week.dat");

    Terminal t;
    std::wcout << wwk.wform();
    t.input('\15');
    std::wcout << "\nthis >" << t.put(' ');
}
