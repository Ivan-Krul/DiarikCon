#include "Terminal.h"

Week Terminal::_input_dayweek(bool &inp_)
{
	std::wstring dayweek;
	std::wcout << "\tDay of week: ";
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
		inp_ = true;
		return (Week)8;
	}
	return wek;
}

bool Terminal::warning()
{
	std::wstring type;
	std::wcout << "You are trying to quit, are you accepting fact about losing work? [accept/(any else)]: ";
	std::wcin >> type;
	if(type == L"accept")
		_is_quit = true;
	return true;
}

void Terminal::_Chelp()
{
	for(auto &token : (_is_terminal ? list_terminal_token : list_panel_token))
	{
		std::wcout <<'\t'<< token.regex << '\n';
	}
}

bool Terminal::_CPshow()
{
	int i = 0;
	for(auto &panel : _panel_list)
	{
		std::wcout << i << ": " << panel._name << '\n';
		i++;
	}

	return true;
}

bool Terminal::_CTshow()
{
	std::wcout<<(*_cur_panel).wform();
	return true;
}
bool Terminal::_CPdelete()
{
	std::wstring name;
	std::wcout << "\tName of panel: ";
	std::wcin >> name;
	for(auto iter = _panel_list.begin();iter != _panel_list.end();iter++)
	{
		if((*iter)._name == name)
		{
			_panel_list.erase(iter);
			return true;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): name isn't detected: " << name << "\n";
	std::wcerr << "ERROR: For users: try to type name, what exist\n\a";
	std::wcin.get();
	return false;
}
bool Terminal::_CPadd()
{
	std::wstring name;
	std::wcout << "\tName of panel: ";
	std::wcin >> name;
	_panel_list.push_back(WorkWeek());
	(--_panel_list.end())->_name = name;
	return true;
}
bool Terminal::_CPsave()
{
	system("dir");
	std::wstring namedir;
	std::wcout << "File name to save: ";
	std::getline(std::wcin, namedir);
	_panel_list.rbegin()->save(namedir);
	return true;
}
bool Terminal::_CPload()
{
	system("dir");
	std::wstring namedir;
	std::wcout << "File name to load: ";
	std::getline(std::wcin, namedir);
	_panel_list.push_back(WorkWeek());
	_panel_list.rbegin()->load(namedir);
	return true;
}

bool Terminal::_CTadd()
{

	std::wstring name;
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	(*_cur_panel)[wek].append(Lesson(name));
	return true;
}

bool Terminal::_CPselect()
{
	int choose;
	_CPshow();
	std::wcout << "Number: ";
	std::wcin >> choose;
	auto iter = _panel_list.begin();
	for(iter; iter != _panel_list.end() && choose != 0; (choose--, iter++));
	if(iter == _panel_list.end())
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): index of panel isn't found: " << choose << "\n";
		std::wcerr << "ERROR: For users: try to type number on start of the string, when it show for you\n\a";
		std::wcin.get();
		return false;
	}
	_cur_panel = iter;
	_is_terminal = true;
	return true;
}

bool Terminal::_CTdelete()
{
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wcout << "\tName of lesson: ";
	std::wstring name;
	std::wcin >> name;

	(*_cur_panel)[wek].delet(name);

	return true;
}

bool Terminal::_CTback()
{
	_is_terminal = false;
	return true;
}

bool Terminal::_CThw()
{
	std::wstring name, dayweek;
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			std::wstring hw;
			std::wcout << "\tHomework: ";
			std::wcin >> hw;
			(*_cur_panel)[wek][i].mark_homework(hw);
			return true;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): name isn't found: " << name << "\n";
	std::wcerr << "ERROR: For users: try to type correctly\n\a";
	std::wcin.get();
	return false;
}

bool Terminal::_CTdone() 
{
	std::wstring name, dayweek;
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			(*_cur_panel)[wek][i].mark_done();
			return true;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): name isn't found: " << name << "\n";
	std::wcerr << "ERROR: For users: try to type correctly\n\a";
	std::wcin.get();
	return false;
}

bool Terminal::_CTmark() 
{
	std::wstring name, dayweek;
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			short hw;
			std::wcin >> hw;
			(*_cur_panel)[wek][i].mark_mark(hw);
			return true;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): name isn't found: " << name << "\n";
	std::wcerr << "ERROR: For users: try to type correctly\n\a";
	std::wcin.get();
	return false;
}

void Terminal::input()
{
	std::wcout << (_is_terminal? std::wstring(L"Panel ")+(*_cur_panel)._name + L": " : std::wstring(L"Panel Chooser: "));
	std::wcin >> cmd;
	for(auto &token : (_is_terminal?list_terminal_token:list_panel_token))
	{
		if(token.regex == cmd)
		{
			if(token.name == L"SHOW") (_is_terminal ? _CTshow() : _CPshow());
			if(token.name == L"QUIT") warning();
			if(token.name == L"ADD") (_is_terminal ? _CTadd() : _CPadd());
			if(token.name == L"DELETE") (_is_terminal ? _CTdelete() : _CPdelete());
			if(token.name == L"SELECT" && !_is_terminal) _CPselect();
			if(token.name == L"BACK" && _is_terminal) _CTback();
			if(token.name == L"SET_HOMEWORK" && _is_terminal) _CThw();
			if(token.name == L"SET_DONE" && _is_terminal) _CTdone();
			if(token.name == L"SET_MARK" && _is_terminal) _CTmark();
			if(token.name == L"SAVE" && !_is_terminal) _CPsave();
			if(token.name == L"LOAD" && !_is_terminal) _CPload();
			if(token.name == L"HELP") _Chelp();
			return;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): token to " << cmd << " isn't detected\n";
	std::wcerr<<"ERROR: For users: this command wasn't found in list of accessed commands, try type correctly\n\a";
	std::wcin.get();
}

bool Terminal::is_terminal()
{
	return _is_terminal;
}

bool Terminal::is_quit()
{
	return _is_quit;
}
