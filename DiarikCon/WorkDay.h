#pragma once
#include "Lesson.h"
class WorkDay
{
private:
	int _size;
	Lesson **_lessons;
public:
	void append(Lesson lesson_);
	Lesson lesson(int _index);

};

