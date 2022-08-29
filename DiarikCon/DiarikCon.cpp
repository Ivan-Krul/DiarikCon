#include <iostream>
#include "WorkDay.h"
int main()
{
    Lesson les(L"math",L"ex 1 p 143");
    std::wcout << les.wform()<<'\n';
    WorkDay wd;
    wd.append(les);
    wd.append(Lesson(L"ukr_lang", L"ex 5 p 110, write sentence"));
    wd.lesson(1).mark_mark(8);
    wd.lesson(0).mark_done();

    std::wcout << wd.wform();
}
