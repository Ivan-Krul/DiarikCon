#pragma once
#include <string>
#include <fstream>
#include "Define.h"
class Lesson
{
	std::wstring _name;
	std::wstring _hw;
	bool _is_done = false;
	short _mark = -1;
public:
	Lesson(std::wstring name_);

	void mark_homework(std::wstring hw_);
	void mark_done();
	void mark_mark(short mark_);
	void mark_name(std::wstring name_);
	std::wstring name();
	std::wstring hw();
	bool is_done();
	short mark();

	std::wstring type();
};
