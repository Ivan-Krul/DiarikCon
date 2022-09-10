#pragma once
#include <fstream>
#include <map>
#include <any>
#include <string>
class Config
{
	std::map<std::string, std::any &> _var;

	// for Config(std::wstring file_)
	void _readnumber(std::string line_, std::string name_);
	void _clearcomments(std::string &line_);
	std::string _readgroup(std::string line_);
	std::string _readnamevariable(std::string &line_);
	void _readvalue(std::string line_, std::string name_);
public:
	Config() = default;
	const std::wstring format = L".ini";
	Config(std::wstring file_);

	std::any &operator[](std::string index_);
	std::wstring filename;

	~Config();
};

inline bool isnumber(char num_)
{
	return '0' <= num_ && num_ <= '9';
}

inline int tonumber(char num_)
{
	return num_ - '0';
}

inline bool isletter(char num_)
{
	return ('A' <= num_ && num_ <= 'Z') || ('a' <= num_ && num_ <= 'z') || (num_ == '_');
}
