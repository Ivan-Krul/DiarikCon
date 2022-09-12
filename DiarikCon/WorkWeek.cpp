#include "WorkWeek.h"
#include <sstream>
WorkDay &WorkWeek::operator[](Week index_)
{
	if((int)index_ >= 7)
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): Index is out of range: " << (int)index_ << ", but max element: " << 7 << "\n\a";
		std::wcin.get();
	}
	return _week[(unsigned char)index_%7];
}

std::wstring WorkWeek::wform()
{
	std::wstringstream sstream;
	auto max = [](int a, int b) { return a < b ? b : a; };
	int maxch_name = 0;
	int maxch_hw = 0;
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < _week[i].size(); j++)
		{
			maxch_name = max(_week[i][j].name().size(), maxch_name);
			maxch_hw = max(_week[i][j].hw().size(), maxch_hw);
		}
	}
	for(int i = 0; i < 7; i++)
	{
		switch((Week)i)
		{
			case Week::monday:
				sstream << "monday:\n";
				break;
			case Week::tuesday:
				sstream << "tuesday:\n";
				break;
			case Week::wednesday:
				sstream << "wednesday:\n";
				break;
			case Week::thursday:
				sstream << "thursday:\n";
				break;
			case Week::friday:
				sstream << "friday:\n";
				break;
			case Week::saturday:
				sstream << "saturday:\n";
				break;
			case Week::sunday:
				sstream << "sunday:\n";
				break;
			default:
				sstream << "day in week which isn't exist:\n";
				break;
		}
		for(int j = 0; j < _week[i].size(); j++)
		{
			sstream << j + 1<<":\t[" << _week[i][j].name() << "]";
			for(int k = 0; k < maxch_name - _week[i][j].name().size(); k++)
				sstream << " ";
			sstream << ": ("<<(_week[i][j].lessonlink().empty()? std::wstring(L""): std::wstring(L"link")) << ") [" << _week[i][j].hw() << "]";
			for(int k = 0; k < maxch_hw - _week[i][j].hw().size() + 1; k++)
				sstream << " ";
			if(_week[i][j].is_done())
				sstream << "is done   ";
			else
				sstream << "isn't done";
			if(_week[i][j].mark() != -1)
				sstream << " [" << _week[i][j].mark() << "]";
			sstream << "\n";
		}
	}

	return sstream.str();
}

void WorkWeek::load(std::wstring dir_)
{
	std::wifstream ifs;
	ifs.open(dir_, std::ios::out);
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
	std::getline(ifs, _name);
	for(int i = 0; i < 7; i++)
	{
		std::wstring buf;
		std::wstring name, hw,link;
		bool is_done;
		short mark;
		int size;
		std::getline(ifs, buf);
		std::getline(ifs, buf);
		size = std::stoi(buf);
		for(int j = 0; j < size; j++)
		{

			std::getline(ifs, name);
			std::getline(ifs, hw);
			std::getline(ifs,buf);
			is_done = std::stoi(buf);
			std::getline(ifs, buf);
			mark = std::stoi(buf);

			_week[i].append(Lesson(name));
			_week[i][j].mark_homework(hw);
			if(is_done) _week[i][j].mark_done();
			_week[i][j].mark_mark(mark);
			std::getline(ifs, link);
			_week[i][j].mark_lessonlink(link);
		}
	}

	ifs.close();
}

void WorkWeek::save(std::wstring dir_)
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
	ofs << _name<<'\n';
	for(int i = 0; i < 7; i++)
	{
		switch((Week)i)
		{
			case Week::monday:
				ofs << "monday:\n";
				break;
			case Week::tuesday:
				ofs << "tuesday:\n";
				break;
			case Week::wednesday:
				ofs << "wednesday:\n";
				break;
			case Week::thursday:
				ofs << "thursday:\n";
				break;
			case Week::friday:
				ofs << "friday:\n";
				break;
			case Week::saturday:
				ofs << "saturday:\n";
				break;
			case Week::sunday:
				ofs << "sunday:\n";
				break;
			default:
				ofs << "day in week which isn't exist:\n";
				break;
		}
		ofs << _week[i].size()<<'\n';
		for(int j = 0; j < _week[i].size(); j++)
		{
			ofs << _week[i][j].name() << '\n';
			ofs << _week[i][j].hw() << '\n';
			ofs << _week[i][j].is_done() << '\n';
			ofs << _week[i][j].mark() << '\n';
			ofs << _week[i][j].lessonlink() << '\n';
		}
	}
	ofs.close();
}

std::wstring WorkWeek::type()
{
	return L"WorkWeek";
}
