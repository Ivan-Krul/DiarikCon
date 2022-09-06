#include <iostream>
#include "WorkWeek.h"
#include "Terminal.h"
int main(int args, wchar_t* argv[])
{
	Terminal t;
	while(!t.is_quit())
	{
		t.input();
	}
}
