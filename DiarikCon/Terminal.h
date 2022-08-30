#pragma once
#include "Define.h"
#include <conio.h>
#include <list>
#include "WorkWeek.h"
class Terminal
{
	bool _is_terminal = false;
	std::list<WorkWeek> _panel_list;
	std::list<WorkWeek>::iterator _cur_panel;

	bool _CTshow();
	bool _CTadd();
	bool _CTdelete();
public:
	std::wstring cmd;
	void input();
	bool is_terminal();
};

struct Token
{
	std::wstring name;
	std::wstring regex;
};

std::list<Token> list_terminal_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"add"},
	{L"DELETE",L"delete"},
	{L"HOMEWORK_SET",L"homework"},
	{L"CHANGE",L"change"},
	{L"QUIT",L"quit"},
	{L"BACK",L"back"},
};

std::list<Token> list_panel_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"add"},
	{L"DELETE",L"delete"},
	{L"SELECT",L"select"},
	{L"CHANGE",L"change"},
	{L"QUIT",L"quit"},
	{L"BACK",L"back"},
};
