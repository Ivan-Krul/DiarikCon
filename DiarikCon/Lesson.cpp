#include "Lesson.h"
#include <sstream>

Lesson::Lesson(std::wstring name_, std::wstring hw_)
{
	_name = name_;
	_hw = hw_;
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

std::wstring Lesson::hw()
{
	return _hw;
}

void Lesson::load(std::wstring dir_)
{
	
	std::wifstream ifs;
	ifs.open(dir_, std::ios::in);
	if(!ifs.is_open())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File isn't open: "<<dir_<<"\n\a";
		std::cin.get();
		ifs.close();
		return;
	}
	if(ifs.fail())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File is failed: " << dir_ << "\n\a";
		std::cin.get();
		ifs.close();
		return;
	}
	std::getline(ifs,_name);
	std::getline(ifs, _hw);
	ifs >> _is_done;
	ifs >> _mark;

	ifs.close();
}

void Lesson::save(std::wstring dir_)
{
	std::wofstream ofs;
	ofs.open(dir_,  std::ios::out);
	if(ofs.fail())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File is failed: " << dir_ << "\n\a";
		std::cin.get();
		ofs.close();
		return;
	}
	if(!ofs || !ofs.is_open())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File isn't open: " << dir_ << "\n\a";
		std::cin.get();
		ofs.close();
		return;
	}
	ofs << _name << '\n';
	ofs << _hw << '\n';
	ofs << _is_done << ' ' << _mark;
	ofs.close();
}

std::wstring Lesson::wform()
{
	const char *not_aviable = "N/a";
	std::wstringstream sstream;
	sstream << "[" << _name << "] : ["<<_hw<<"] is";
	if(_is_done)
		sstream << " ";
	else
		sstream << "n't ";
	sstream << "done [";
	if(_mark == -1) sstream << not_aviable;
	else sstream << _mark;
	sstream << "]";

	return sstream.str();
}

bool Lesson::is_done()
{
	return _is_done;
}

short Lesson::mark()
{
	return _mark;
}
