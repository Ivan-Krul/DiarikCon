#include <iostream>
#include "WorkWeek.h"
#include "Terminal.h"
int main()
{
	Terminal t;
	while(!t.is_quit())
	{
		t.input();
	}
}
