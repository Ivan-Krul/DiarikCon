#pragma once
#include "Define.h"
#include <conio.h>
#include <list>
class Terminal
{
	bool _is_terminal = false;
	std::list<Panel> _panel_list;
	std::list<Panel>::iterator _cur_panel;
	void _Cshow();
public:
	std::wstring cmd;
	void input(wchar_t when_stop = '\xd');
	std::wstring put(wchar_t blocked_sym);
	void complete();
	bool is_terminal() { return _is_terminal; }
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
	{L"SELECT",L"select"},
	{L"CHANGE",L"change"},
	{L"HELP",L"help"},
	{L"QUIT",L"quit"},
	{L"BACK",L"back"},
};

std::list<Token> list_panel_token = {
	{L"SHOW",L"show"},
	{L"ADD",L"add"},
	{L"DELETE",L"delete"},
	{L"WEEK",L"selweek"},
	{L"DAY",L"selday"},
	{L"HELP",L"help"},
	{L"SETTINGS",L"settings"},
	{L"CONFIGURATE",L"configurate"},
	{L"LOCALIZE",L"localize"},
	{L"QUIT",L"quit"},
	{L"PANEL",L"panel"},
	{L"LOAD",L"load"},
	{L"SAVE",L"save"},

};
