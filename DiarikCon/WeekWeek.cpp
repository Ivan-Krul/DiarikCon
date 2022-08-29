#include "WeekWeek.h"
#include <sstream>
WorkDay &WeekWeek::operator[](Week index_)
{
	return _week[(unsigned char)index_];
}

std::wstring WeekWeek::wform()
{
	std::wstringstream sstream;
	auto max = [](int a, int b) { return a < b ? b : a; };
	int maxch_name = 0;
	int maxch_hw = 0;
	for(int i = 0; i < 7; i++)
	{
		switch((Week)i)
		{
			case Week::monday:
				sstream << "monday:\n";
				break;
			case Week::tuesday:
				sstream << "tuesday:\n";
				break;
			case Week::wednesday:
				sstream << "wednesday:\n";
				break;
			case Week::thursday:
				sstream << "thursday:\n";
				break;
			case Week::friday:
				sstream << "friday:\n";
				break;
			case Week::saturday:
				sstream << "saturday:\n";
				break;
			case Week::sunday:
				sstream << "sunday:\n";
				break;
			default:
				sstream << "what:\n";
				break;
		}
		for(int j = 0; j < _week[i].size(); j++)
		{
			maxch_name = max(_week[i][j].name().size(), maxch_name);
			maxch_hw = max(_week[i][j].hw().size(), maxch_hw);
		}
	}

	return std::wstring();
}

void WeekWeek::load(std::wstring dir_)
{
}

void WeekWeek::save(std::wstring dir_)
{
}
