#pragma once
#include <string>
#include <fstream>
#include "Define.h"
class Lesson : public Panel
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
	std::wstring name();
	std::wstring hw();
	bool is_done();
	short mark();

	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
	std::wstring type() override;
};
