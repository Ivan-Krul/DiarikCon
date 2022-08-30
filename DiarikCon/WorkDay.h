#pragma once
#include "Lesson.h"
#include <vector>
class WorkDay : public Panel
{
private:
	std::vector<Lesson> _lessons;
public:
	void append(Lesson lesson_);
	Lesson& operator[](int index_);
	int size();

	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
	std::wstring type() override;
};

