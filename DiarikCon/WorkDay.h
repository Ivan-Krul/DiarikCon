#pragma once
#include "Lesson.h"
class WorkDay : public Itask
{
private:
	int _size = 0;
	Lesson **_lessons;
public:
	void append(Lesson lesson_);
	Lesson& lesson(int _index);
	int size();

	std::wstring wform();

	~WorkDay();
};

