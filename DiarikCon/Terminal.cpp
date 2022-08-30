#include "Terminal.h"

void Terminal::_Cshow()
{
    if(_is_terminal)
    {
        std::wcout << "panel: " << (*_cur_panel)._name << "\n";
        (*_cur_panel).wform();
    }
    else
    {
        std::wcout << "panel chooser\n";
        for(auto &panels : _panel_list)
            std::wcout << panels._name << " " << panels.type() << '\n';
    }
}

void Terminal::input(wchar_t when_stop)
{
    wchar_t sym = L'\0';
    std::wcout << "[!Type here]: ";
    std::wcout << cmd;
    while(sym != 13)
    {
        if(_kbhit())
        {
            sym = _getwch();

            if(sym != 13 || sym != when_stop)
            {

                if(sym != '\b')
                {
                    cmd += sym;
                    std::wcout << sym;
                }
                else if(cmd.size() != 0)
                {
                    cmd.erase(cmd.end() - 1);
                    std::wcout << "\b \b";
                }

            }

        }
    }

    for(int i = 0; i < cmd.size() + 14; i++) std::wcout << "\b \b";
    std::wcout << cmd;

}

std::wstring Terminal::put(wchar_t blocked_sym)
{
    std::wstring str;
    int i = 0;
    while(i < cmd.size())
    {
        if(cmd[i] == blocked_sym) break;
        i++;
    }
    str = cmd.substr(0, i);
    cmd.erase(0, str.size() + 1);
    return str;
}

void Terminal::complete()
{
    auto command = put(' ');
    for(auto &token : (_is_terminal?list_terminal_token:list_panel_token))
    {
        if(command == token.regex)
        {
            if(_is_terminal)
            {
                _Cshow();
            }
            else
            {

            }
            return;
        }
    }

}
