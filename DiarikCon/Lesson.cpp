#include "Lesson.h"
#include <sstream>

Lesson::Lesson(std::wstring name_, std::wstring hw_)
{
	_name = name_;
	_hw = hw_;
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

std::wstring Lesson::hw()
{
	return _hw;
}

std::wstring Lesson::wform()
{
	const char *not_aviable = "N/a";
	std::wstringstream sstream;
	sstream << "[" << _name << "] : ["<<_hw<<"] is";
	sstream << _is_done ? " " : "n't ";
	sstream << "done [";
	if(_mark == -1) sstream << not_aviable;
	else sstream << _mark;
	sstream << "]";

	return sstream.str();
}

bool Lesson::is_done()
{
	return _is_done;
}

short Lesson::mark()
{
	return _mark;
}
