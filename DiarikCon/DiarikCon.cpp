#include <iostream>
#include "WorkDay.h"
int main()
{
    WorkDay wd;
    wd.append(Lesson(L"", L""));
    wd.append(Lesson(L"", L""));
    wd.lesson(0).load(L"ukr_lang.dat");
    wd.lesson(1).load(L"math.dat");
    wd.save(L"week.dat");

    std::wcout << wd.wform();
}
