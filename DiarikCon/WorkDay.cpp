#include "WorkDay.h"
#include <sstream>

void WorkDay::append(Lesson lesson_)
{
	_lessons.push_back(lesson_);
}

Lesson& WorkDay::operator[](int _index)
{
	if(_index >= _lessons.size())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): Index is out of range: " << _index << ", but max element: "<<_lessons.size()-1 << "\n\a";
		std::wcin.get();
	}
	return _lessons[_index% _lessons.size()];
}

int WorkDay::size()
{
	return _lessons.size();
}

std::wstring WorkDay::wform()
{
	auto max = [](int a, int b) { return a < b ? b : a; };
	int maxch_name = 0;
	int maxch_hw = 0;
	for(int i = 0; i < _lessons.size(); i++)
	{
		maxch_name = max(_lessons[i].name().size(),maxch_name);
		maxch_hw = max(_lessons[i].hw().size(), maxch_hw);
	}

	std::wstringstream sstream;
	for(int i = 0; i < _lessons.size(); i++)
	{
		sstream << i+1<<": [" << _lessons[i].name() << "]";
		for(int j = 0; j < maxch_name - _lessons[i].name().size(); j++)
			sstream << " ";
		sstream << ": [" << _lessons[i].hw() << "]";
		for(int j = 0; j < maxch_hw - _lessons[i].hw().size() + 1; j++)
			sstream << " ";
		if(_lessons[i].is_done())
			sstream << "is done   ";
		else
			sstream << "isn't done";
		if(_lessons[i].mark() != -1)
			sstream << " [" << _lessons[i].mark() << "]";
		sstream << "\n";
	}
	return sstream.str();
}

void WorkDay::load(std::wstring dir_)
{
	std::wifstream ifs;
	ifs.open(dir_, std::ios::in);
	if(!ifs.is_open())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File isn't open: " << dir_ << "\n\a";
		std::wcin.get();
		ifs.close();
		return;
	}
	if(ifs.fail())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File is failed: " << dir_ << "\n\a";
		std::wcin.get();
		ifs.close();
		return;
	}
	while(ifs)
	{
		std::wstring name,hw;
		bool is_done;
		short mark;
		std::getline(ifs, name);
		std::getline(ifs, hw);
		_lessons.push_back(Lesson(name));
		_lessons[_lessons.size() - 1].mark_homework(hw);
		ifs >> is_done >> mark;
		if(is_done) _lessons[_lessons.size() - 1].mark_done();
		_lessons[_lessons.size() - 1].mark_mark(mark);
	}
	ifs.close();
}

void WorkDay::save(std::wstring dir_)
{
	std::wofstream ofs;
	ofs.open(dir_, std::ios::out);
	if(ofs.fail())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File is failed: " << dir_ << "\n\a";
		std::wcin.get();
		ofs.close();
		return;
	}
	if(!ofs || !ofs.is_open())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File isn't open: " << dir_ << "\n\a";
		std::wcin.get();
		ofs.close();
		return;
	}
	for(int i = 0; i < _lessons.size(); i++)
	{
		ofs << _lessons[i].name() << '\n';
		ofs << _lessons[i].hw() << '\n';
		ofs << _lessons[i].is_done() << ' ' << _lessons[i].mark()<<'\n';
	}
	ofs.close();
}

void WorkDay::delet(std::wstring name_)
{
	for(int i = 0; i < _lessons.size(); i++)
	{
		if(_lessons[i].name() == name_)
		{
			_lessons.erase(_lessons.begin() + i);
			return;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): Element isn't found: " << name_ << "\n\a";
	std::wcerr << "ERROR: " << "For users: try to type name of existance name\n\a";
	std::wcin.get();
}

std::wstring WorkDay::type()
{
	return L"WorkDay";
}

