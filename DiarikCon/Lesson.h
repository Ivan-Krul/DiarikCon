#pragma once
#include <string>
#include "Define.h"
class Lesson : public Itask
{
	std::wstring _name;
	std::wstring _hw;
	bool _is_done = false;
	short _mark = -1;
public:
	Lesson(std::wstring name_, std::wstring hw_);

	void mark_done();
	void mark_mark(short mark_);
	std::wstring name();
	std::wstring hw();
	bool is_done();
	short mark();

	std::wstring wform();
	void load(std::wstring dir_);
};
