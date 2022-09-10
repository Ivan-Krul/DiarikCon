#pragma once
#include <fstream>
#include <map>
#include <string>
class Config
{
	std::map<std::pair<std::string,std::string>, std::any &> _var;

	// for Config(std::wstring file_)
	void _readnumber(std::string line_,std::string parent_ ,std::string name_);
	void _clearcomments(std::string &line_);
	std::string _readgroup(std::string line_);
	std::string _readnamevariable(std::string &line_);
	void _readvalue(std::string line_, std::string parent_, std::string name_);
public:
	Config() = default;
	const std::wstring format = L".ini";
	Config(std::wstring file_);

	std::any &get(std::string parent_, std::string index_);
	std::wstring filename;

	~Config();
};

template<class T>
class any
{
	T *_ptr;
	type_info _info;
public:
	any(T obj_)
	{
		_info = T;
		_ptr = obj_;
	}
	T copy()
	{
		return &_ptr;
	}
	T &extract()
	{
		return _ptr;
	}
	any &operator=()
	{
		return _ptr;
	}
	void operator=(any &any_)
	{
		
	}
	~any()
	{
		delete _ptr;
	}
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
