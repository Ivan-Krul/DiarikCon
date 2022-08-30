#pragma once
#include <iostream>
#include <cassert>

__interface IPanel
{
	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
	std::wstring type();
};

class Panel : public IPanel
{
public:
	std::wstring _name;
};
