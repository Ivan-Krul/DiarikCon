#pragma once
#include "Define.h"
#include <conio.h>
#include <list>
#include "WorkWeek.h"
class Terminal
{
	bool _is_terminal = false;
	bool _is_config = false;
	bool _is_quit = false;
	bool _is_cmd = false;

	bool _is_autosave;
	bool _is_allways_warning;
	bool _is_hide_additional_text;
	
	std::list<WorkWeek> _panel_list;
	std::list<WorkWeek>::iterator _cur_panel;;

	std::wstring _showMode();

	Week _input_dayweek(bool &inp_);
	bool warning();

	void _load_cfg();
	void _save_cfg();

	bool _CPshow();
	bool _CPadd();
	bool _CPdelete();
	bool _CPselect();
	bool _CTsave();
	bool _CPload();
	bool _CPrename();
	bool _CPclear();
	void _CPabout();

	bool _Ccmd();
	bool _Cconfig();
	void _Cshow();
	bool _CCallways_warning();
	bool _CCauto_save();
	bool _CChide_additional_text();
	bool _CCback();

	bool _CTshow();
	bool _CTadd();
	bool _CTdelete();
	bool _CTback();
	bool _CThw();
	bool _CTdone();
	bool _CTmark();
	void _Chelp();
	bool _CTrename();
	bool _CTclear();
	void _CTset_link();
	void _CTshow_link();
	void _CTgoto();
public:
	Terminal() { _load_cfg(); }
	std::wstring cmd;
	void input();
	bool is_terminal();
	bool is_quit();
};
struct Token
{
	std::wstring name;
	std::wstring regex;
};

static std::list<Token> list_terminal_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"create"},
	{L"DELETE",L"delete"},
	{L"SET_HOMEWORK",L"homework"},
	{L"SET_DONE",L"done"},
	{L"SET_MARK",L"mark"},
	{L"QUIT",L"quit"},
	{L"BACK",L"back"},
	{L"HELP",L"help"},
	{L"RENAME",L"rename"},
	{L"CLEAR",L"clear"},
	{L"CMD",L"cmd"},
	{L"SAVE",L"save"},
	{L"CONFIG",L"config"},
	{L"SET_LINK",L"link"},
	{L"SHOW_LINK",L"showlink"},
	{L"GOTO",L"goto"},
};

static std::list<Token> list_panel_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"create"},
	{L"DELETE",L"delete"},
	{L"SELECT",L"select"},
	{L"QUIT",L"quit"},
	{L"LOAD",L"load"},
	{L"HELP",L"help"},
	{L"RENAME",L"rename"},
	{L"CLEAR",L"clear"},
	{L"CMD",L"cmd"},
	{L"CONFIG",L"config"},
	{L"ABOUT",L"about"},
};

static std::list<Token> list_config_token = {
	{L"ALLWAYS_WARNING",L"allways_warning"},
	{L"AUTO_SAVE",L"autosave"},
	{L"HIDE_ADDITIONAL_TEXT",L"hide_additional_text"},
	{L"SAVE",L"save"},
	{L"BACK",L"back"},
};
