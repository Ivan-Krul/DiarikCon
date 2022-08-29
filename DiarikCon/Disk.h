#pragma once
#include "Define.h"
#include <fstream>

std::wofstream openFileO(const std::wstring dir_)
{
	std::wofstream ofs;
	ofs.open(dir_);

	if(ofs.fail())
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File " << dir_ << " is failed\n\a";
	return ofs;
}

std::wifstream openFileI(const std::wstring dir_)
{
	std::wifstream ifs;
	ifs.open(dir_);

	if(!ifs.is_open()) 
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File " << dir_ << " isn't open\n\a";
	if(ifs.fail())
		std::wcerr << "ERROR: " << __FUNCTION__ << "(): File " << dir_ << " is failed\n\a";
	return ifs;
}
