#include "Terminal.h"

bool Terminal::_CTshow()
{
	(*_cur_panel).wform();
	return true;
}
bool Terminal::_CTadd()
{
	std::wstring dayweek;
	std::wstring name;
	std::wcin >> dayweek >> name;
	Week wek;
	if(dayweek == L"monday") wek = Week::monday;
	else if(dayweek == L"tuesday") wek = Week::tuesday;
	else if(dayweek == L"wednesday") wek = Week::wednesday;
	else if(dayweek == L"thursday") wek = Week::thursday;
	else if(dayweek == L"friday") wek = Week::friday;
	else if(dayweek == L"saturday") wek = Week::saturday;
	else if(dayweek == L"sunday") wek = Week::sunday;
	else
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): name of day in week isn't common: "<<dayweek<<"\n";
		std::wcerr << "ERROR: For users: try to type correctly\n\a";
		std::wcin.get();
		return false;
	}

	(*_cur_panel)[wek].append(Lesson(name));
	return true;
}

bool Terminal::_CTdelete()
{
	std::wstring dayweek;
	std::wcin >> dayweek;
	Week wek;
	if(dayweek == L"monday") wek = Week::monday;
	else if(dayweek == L"tuesday") wek = Week::tuesday;
	else if(dayweek == L"wednesday") wek = Week::wednesday;
	else if(dayweek == L"thursday") wek = Week::thursday;
	else if(dayweek == L"friday") wek = Week::friday;
	else if(dayweek == L"saturday") wek = Week::saturday;
	else if(dayweek == L"sunday") wek = Week::sunday;
	else
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): name of day in week isn't common: " << dayweek << "\n";
		std::wcerr << "ERROR: For users: try to type correctly\n\a";
		std::wcin.get();
		return false;
	}
	std::wstring name;
	std::wcin >> name;

	for(int i = 0;i< (*_cur_panel)[wek].size();i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			(*_cur_panel)[wek]
			return true;
		}
	}

	return true;
}

void Terminal::input()
{
	std::wcin >> cmd;
	for(auto &token : (_is_terminal?list_terminal_token:list_panel_token))
	{
		if(token.regex == cmd)
		{
			if(token.name == L"SHOW" && _is_terminal) _CTshow();
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): token to " << cmd << " isn't detected\n";
	std::wcerr<<"ERROR: For users: this command wasn't found in list of accessed commands, try type correctly\n\a";
	std::wcin.get();
	return;
}

bool Terminal::is_terminal()
{
	return _is_terminal;
}
