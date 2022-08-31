#include "Lesson.h"
#include <sstream>

Lesson::Lesson(std::wstring name_)
{
	_name = name_;
}

void Lesson::mark_done()
{
	_is_done = true;
}

void Lesson::mark_mark(short mark_)
{
	_mark = mark_;
}

std::wstring Lesson::name()
{
	return _name;
}

void Lesson::mark_homework(std::wstring hw_)
{
	_hw = hw_;
}

std::wstring Lesson::hw()
{
	return _hw;
}

bool Lesson::is_done()
{
	return _is_done;
}

short Lesson::mark()
{
	return _mark;
}

std::wstring Lesson::type()
{
	return L"Lesson";
}
