#pragma once
#include <iostream>
#include <cassert>

__interface Itask
{
	std::wstring wform();
	void load(std::wstring dir_);
	void save(std::wstring dir_);
};
