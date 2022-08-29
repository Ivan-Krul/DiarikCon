#include "WorkDay.h"
#include <sstream>

void WorkDay::append(Lesson lesson_)
{
	auto buf = _lessons;
	_size++;
	_lessons = new Lesson *[_size];
	for(int i = 0; i < _size - 1; i++)
		_lessons[i] = new Lesson(*buf[i]);
	_lessons[_size - 1] = new Lesson(lesson_);
	if(_size < 2)
	{
		for(int i = 0; i < _size - 1; i++)
			delete buf[i];
		delete[] buf;
	}
}

Lesson& WorkDay::lesson(int _index)
{
	if(_index >= _size)
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): Index is out of range: " << _index << ", but max element: "<<_size-1<<"\n\a";
		std::cin.get();
	}
	return *_lessons[_index%_size];
}

int WorkDay::size()
{
	return _size;
}

std::wstring WorkDay::wform()
{
	auto max = [](int a, int b) { return a < b ? b : a; };
	int maxch_name = 0;
	int maxch_hw = 0;
	for(int i = 0; i < _size; i++)
	{
		maxch_name = max(_lessons[i]->name().size(),maxch_name);
		maxch_hw = max(_lessons[i]->hw().size(), maxch_hw);
	}

	std::wstringstream sstream;
	for(int i = 0; i < _size; i++)
	{
		sstream << "[" << _lessons[i]->name() << "]";
		for(int j = 0; j < maxch_name - _lessons[i]->name().size(); j++)
			sstream << " ";
		sstream << ": [" << _lessons[i]->hw() << "]";
		for(int j = 0; j < maxch_hw - _lessons[i]->hw().size() + 1; j++)
			sstream << " ";
		if(_lessons[i]->is_done())
			sstream << "is done   ";
		else
			sstream << "isn't done";
		if(_lessons[i]->mark() != -1)
			sstream << " [" << _lessons[i]->mark() << "]";
		sstream << "\n";
	}
	return sstream.str();
}

WorkDay::~WorkDay()
{
	for(int i = 0; i < _size; i++)
		delete _lessons[i];
	delete[] _lessons;
}
