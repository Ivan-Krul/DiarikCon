#pragma once
#include <string>
#include <fstream>
#include "Define.h"
class Lesson
{
	std::wstring _name;
	std::wstring _hw;
	std::wstring _lessonlink;
	bool _is_done = false;
	short _mark = -1;
public:
	Lesson(std::wstring name_);

	void mark_homework(std::wstring hw_);
	void mark_done();
	void mark_mark(short mark_);
	void mark_name(std::wstring name_);
	void mark_lessonlink(std::wstring lessonlink_);
	std::wstring lessonlink();
	std::wstring name();
	std::wstring hw();
	bool is_done();
	short mark();
	void goto_link(std::wstring type_);

	std::wstring type();
};
