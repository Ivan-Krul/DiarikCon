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

void Lesson::mark_name(std::wstring name_)
{
	_name = name_;
}

std::wstring Lesson::lessonlink()
{
	return _lessonlink;
}

void Lesson::mark_lessonlink(std::wstring lessonlink_)
{
	_lessonlink = lessonlink_;
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

void Lesson::goto_link(std::wstring type_)
{
	if(type_ == L"edge")
		_wsystem((std::wstring(L"\"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\" ") + _lessonlink).c_str());
	else if(type_ == L"chrome")
		_wsystem((std::wstring(L"\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" ") + _lessonlink).c_str());
	else if(type_ == L"firefox")
		_wsystem((std::wstring(L"\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\" ") + _lessonlink).c_str());
	else if(type_ == L"opera")
		_wsystem((std::wstring(L"\"C:\\Program Files(x86)\\Opera\\launcher.exe\" ") + _lessonlink).c_str());
	else
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): Browser isn't found\n";
		std::wcerr << "ERROR: For users: try to type your browser correctly\n\a";
		std::wcin.get();
	}
}
