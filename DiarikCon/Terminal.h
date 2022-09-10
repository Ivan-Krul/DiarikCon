#pragma once
#include "Define.h"
#include <conio.h>
#include <list>
#include "WorkWeek.h"
#include "Config.h"
class Terminal
{
	bool _is_terminal = false;
	bool _is_config = false;
	bool _is_quit = false;
	bool _is_cmd = false;
	
	std::list<WorkWeek> _panel_list;
	std::list<WorkWeek>::iterator _cur_panel;

	Config cfg;

	std::wstring _showMode();

	Week _input_dayweek(bool &inp_);
	bool warning();

	bool _CPshow();
	bool _CPadd();
	bool _CPdelete();
	bool _CPselect();
	bool _CTsave();
	bool _CPload();
	bool _CPrename();
	bool _CPclear();

	bool _Ccmd();
	bool _Cconfig();
	bool _CCcentric_elements();
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
public:
	Terminal() : cfg(L"settings") {}
	std::wstring cmd;
	void input();
	bool is_terminal();
	bool is_quit();
	~Terminal() { cfg.~Config(); }
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
};

static std::list<Token> list_config_token = {
	{L"CENTRIC_ELEMENTS",L"centric_elements"},
	{L"ALLWAYS_WARNING",L"allways_warning"},
	{L"AUTO_SAVE",L"auto_save"},
	{L"HIDE_ADDITIONAL_TEXT",L"hide_additional_text"},
	{L"BACK",L"back"},
};
