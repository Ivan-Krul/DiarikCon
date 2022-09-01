#pragma once
#include "Define.h"
#include <conio.h>
#include <list>
#include "WorkWeek.h"
class Terminal
{
	bool _is_terminal = false;
	bool _is_quit = false;
	std::list<WorkWeek> _panel_list;
	std::list<WorkWeek>::iterator _cur_panel;

	Week _input_dayweek(bool &inp_);
	bool warning();

	bool _CPshow();
	bool _CPadd();
	bool _CPdelete();
	bool _CPselect();
	bool _CPsave();
	bool _CPload();

	bool _CTshow();
	bool _CTadd();
	bool _CTdelete();
	bool _CTback();
	bool _CThw();
	bool _CTdone();
	bool _CTmark();
	void _Chelp();
public:
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
};

static std::list<Token> list_panel_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"create"},
	{L"DELETE",L"delete"},
	{L"SELECT",L"select"},
	{L"QUIT",L"quit"},
	{L"SAVE",L"save"},
	{L"LOAD",L"load"},
	{L"HELP",L"help"},
};
