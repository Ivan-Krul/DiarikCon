#include "Terminal.h"

Week Terminal::_input_dayweek(bool &inp_)
{
	std::wstring dayweek;
	if(!_is_cmd) std::wcout << "\tDay of week: ";
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
	static std::wstring str_accept = L"accept";
	std::wstring type;
	std::wcout << "Are you "<<str_accept << " with losing work [" << str_accept << "/(any else)]: ";
	std::wcin >> type;
	return type == str_accept;
}

std::wstring Terminal::_showMode()
{
	if(_is_config)
		return L"Config";
	if(_is_terminal)
		return L"Panel " + (*_cur_panel)._name;
	return L"Panel Chooser";
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
	int choose;
	if(!_is_cmd) _CPshow();
	if(!_is_cmd) std::wcout << "Number: ";
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
	_panel_list.erase(iter);
	return true;
}
bool Terminal::_CPadd()
{
	std::wstring name;
	if(!_is_cmd) std::wcout << "\tName of panel: ";
	std::wcin >> name;
	_panel_list.push_back(WorkWeek());
	(--_panel_list.end())->_name = name;
	return true;
}
bool Terminal::_CTsave()
{
	if(!_is_cmd) system("dir");
	std::wstring namedir;
	if(!_is_cmd) std::wcout << "File name to save: ";
	std::wcin >> namedir;
	(*_cur_panel).save(namedir);
	return true;
}
bool Terminal::_CPload()
{
	if(!_is_cmd) system("dir");
	std::wstring namedir;
	if(!_is_cmd) std::wcout << "File name to load: ";
	std::wcin >> namedir;
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
	if(!_is_cmd) std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	(*_cur_panel)[wek].append(Lesson(name));
	return true;
}

bool Terminal::_CPselect()
{
	int choose;
	if(!_is_cmd) _CPshow();
	if(!_is_cmd) std::wcout << "Number: ";
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

bool Terminal::_CPrename()
{
	int choose;
	if(!_is_cmd) _CPshow();
	if(!_is_cmd) std::wcout << "Number: ";
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
	std::wstring renamed;
	if(!_is_cmd) std::wcout << "\tNew name: ";
	std::wcin >> renamed;
	iter->_name = renamed;

	return true;
}

bool Terminal::_CTdelete()
{
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	if(!_is_cmd) std::wcout << "\tName of lesson: ";
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
	if(!_is_cmd) std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			std::wstring hw;
			if(!_is_cmd) std::wcout << "\tHomework: ";
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
	if(!_is_cmd) std::wcout << "\tName of lesson: ";
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
	std::wstring name;
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	if(!_is_cmd) std::wcout << "\tName of lesson: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			short hw;
			if(!_is_cmd) std::wcout << "\tMark: ";
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
bool Terminal::_CPclear()
{
	if(!warning()) return true;
	_panel_list.clear();
	return true;
}
bool Terminal::_CTclear()
{
	if(!warning()) return true;
	for(int i = 0; i < 7; i++)
		for(int j = 0; j < (*_cur_panel)[(Week)i].size(); j++)
			(*_cur_panel)[(Week)i].delet((*_cur_panel)[(Week)i][0].name());
	return true;
}

bool Terminal::_Ccmd()
{
	_is_cmd = true;
	std::wcin >> cmd;
	for(auto &token : _is_config ? list_config_token : (_is_terminal ? list_terminal_token : list_panel_token))
	{
		if(token.regex == cmd)
		{
			if(token.name == L"SHOW") (_is_terminal ? _CTshow() : _CPshow());
			if(token.name == L"QUIT") if(warning()) _is_quit = true;
			if(token.name == L"ADD") (_is_terminal ? _CTadd() : _CPadd());
			if(token.name == L"DELETE") (_is_terminal ? _CTdelete() : _CPdelete());
			if(token.name == L"SELECT" && !_is_terminal) _CPselect();
			if(token.name == L"BACK" && _is_terminal) _CTback();
			if(token.name == L"SET_HOMEWORK" && _is_terminal) _CThw();
			if(token.name == L"SET_DONE" && _is_terminal) _CTdone();
			if(token.name == L"SET_MARK" && _is_terminal) _CTmark();
			if(token.name == L"SAVE" && _is_terminal) _CTsave();
			if(token.name == L"LOAD" && !_is_terminal) _CPload();
			if(token.name == L"HELP") _Chelp();
			if(token.name == L"RENAME") _is_terminal ? _CTrename() : _CPrename();
			if(token.name == L"CLEAR") _is_terminal ? _CTclear() : _CPclear();
			if(token.name == L"CMD") _Ccmd();
			if(token.name == L"CONFIG") _Cconfig();
			if(token.name == L"CENTRIC_ELEMENTS" && _is_config) _CCcentric_elements();
			_is_cmd = false;
			return true;
		}
	}
	std::wcerr << "ERROR: " << __FUNCTION__ << "(): token to " << cmd << " isn't detected\n";
	std::wcerr << "ERROR: For users: this command wasn't found in list of accessed commands, try type correctly\n\a";
	std::wcin.get();
	_is_cmd = false;
	return false;
}

bool Terminal::_Cconfig()
{
	_is_config = true;
	return true;
}

bool Terminal::_CCcentric_elements()
{
	try
	{
		int param = std::any_cast<int>(cfg.get("settings", "center_elements"));
		param = (param == 0 ? 1 : 0);
		return true;
	}
	catch(const std::exception &)
	{
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): catched exception\n\a";
		std::wcin.get();
		return false;
	}
}
bool Terminal::_CCallways_warning()
{
	int param = std::any_cast<int>(cfg.get("settings", "allways_warning"));
	param = (param == 0 ? 1 : 0);
	return true;
}
bool Terminal::_CCauto_save()
{
	int param = std::any_cast<int>(cfg.get("settings", "autosave"));
	param = (param == 0 ? 1 : 0);
	return true;
}
bool Terminal::_CChide_additional_text()
{
	int param = std::any_cast<int>(cfg.get("settings", "hide_additional_text"));
	param = (param == 0 ? 1 : 0);
	return true;
}
bool Terminal::_CCback()
{
	_is_config = false;
	return true;
}

bool Terminal::_CTrename()
{
	bool inp = false;
	Week wek = _input_dayweek(inp);
	if(inp) return false;
	std::wstring name;
	if(!_is_cmd) std::wcout << "\tName for renaming: ";
	std::wcin >> name;
	for(int i = 0; i < (*_cur_panel)[wek].size(); i++)
	{
		if((*_cur_panel)[wek][i].name() == name)
		{
			std::wstring renamed;

			if(!_is_cmd) std::wcout << "\tNew name: ";
			std::wcin >> renamed;
			(*_cur_panel)[wek][i].mark_name(renamed);
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
	std::wcout << _showMode()<<": ";
	std::wcin >> cmd;
	for(auto &token : _is_config ? list_config_token : (_is_terminal ? list_terminal_token : list_panel_token))
	{
		if(token.regex == cmd)
		{
			if(token.name == L"SHOW") (_is_terminal ? _CTshow() : _CPshow());
			if(token.name == L"QUIT") if(warning()) _is_quit = true;
			if(token.name == L"ADD") (_is_terminal ? _CTadd() : _CPadd());
			if(token.name == L"DELETE") (_is_terminal ? _CTdelete() : _CPdelete());
			if(token.name == L"SELECT" && !_is_terminal) _CPselect();
			if(token.name == L"BACK") (_is_config ? _CCback() : _is_terminal ? _CTback() : 0);
			if(token.name == L"SET_HOMEWORK" && _is_terminal) _CThw();
			if(token.name == L"SET_DONE" && _is_terminal) _CTdone();
			if(token.name == L"SET_MARK" && _is_terminal) _CTmark();
			if(token.name == L"SAVE" && _is_terminal) _CTsave();
			if(token.name == L"LOAD" && !_is_terminal) _CPload();
			if(token.name == L"HELP") _Chelp();
			if(token.name == L"RENAME") _is_terminal ? _CTrename() : _CPrename();
			if(token.name == L"CLEAR") _is_terminal ? _CTclear() : _CPclear();
			if(token.name == L"CMD") _Ccmd();
			if(token.name == L"CONFIG") _Cconfig();
			if(token.name == L"CENTRIC_ELEMENTS" && _is_config) _CCcentric_elements();
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
