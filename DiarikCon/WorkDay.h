#pragma once
#include "Lesson.h"
#include <vector>
class WorkDay : public Itask
{
private:
	std::vector<Lesson> _lessons;
public:
	void append(Lesson lesson_);
	Lesson& operator[](int _index);
	int size();

	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
};

