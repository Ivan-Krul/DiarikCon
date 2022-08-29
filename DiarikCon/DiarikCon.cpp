#include <iostream>
#include "WorkDay.h"
int main()
{
    WorkDay wd;
    //wd.append(Lesson(L"ukr_lang", L"ex 5 p 110, write sentence"));
    wd.append(Lesson(L"", L""));
    wd.lesson(0).load(L"ukr_lang.dat");

    std::wcout << wd.wform();
}
