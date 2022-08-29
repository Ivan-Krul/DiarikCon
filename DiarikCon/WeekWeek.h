#pragma once
#include "WorkDay.h"
enum class Week : unsigned char
{
	monday = 0,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	sunday
};
class WeekWeek : public Itask
{
	WorkDay _week[7];
public:
	WorkDay &operator[](Week index_);

	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
};

