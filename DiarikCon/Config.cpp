#include "Config.h"

void Config::_readnumber(std::string line_, std::string parent_, std::string name_)
{
	bool is_float = false;
	float _float = 0;
	int coordot = 0;
	int _int = 0;
	for(int i = 0; !line_.empty(); i++)
	{
		if(!isnumber(line_[i]) && line_[i] != '.')
			break;

		if(line_[i] == '.')
		{
			coordot = i;
			is_float = true;
			continue;
		}

		if(!is_float)
			_int = _int * 10 + tonumber(line_[i]);
		else
			_float = _float + pow(tonumber(line_[i]), coordot - i);
	}

	if(is_float)
		_float += _int;

	std::any any;
	if(is_float)
		any = std::make_any<float>(_float);
	else
		any = std::make_any<int>(_int);
	_var.insert({ {parent_,name_},any });
}

void Config::_clearcomments(std::string &line_)
{
	// search comments
	for(int i = 0; i < line_.size(); i++)
		if(line_[i] == ';')
		{
			line_.erase(i, line_.size() - i);
			break;
		}
}

std::string Config::_readgroup(std::string line_)
{
	int sizegroup = 0;
	while(line_[sizegroup + 1] != ']')
		sizegroup++;
	return line_.substr(1, sizegroup);
}

std::string Config::_readnamevariable(std::string &line_)
{
	std::string str;
	int sizename = 0;
	for(sizename;sizename < line_.size();sizename++)
		if(line_[sizename] == ' ' || line_[sizename] == '=')
			break;
	str = line_.substr(0, sizename);
	line_ = line_.substr(sizename);
	return str;
}

void Config::_readvalue(std::string line_, std::string parent_, std::string name_)
{
	int end_of_text = 0;
	if(line_[0] == '"') // is text with spaces?
	{
		end_of_text++;
		while(end_of_text < line_.empty())
		{
			if(line_[end_of_text] == '"')
				break;
			end_of_text++;
		}
		std::any any = std::make_any<std::string>(line_.substr(1, end_of_text - 1));
		_var.insert({ { parent_, name_ }, any });
		return;
	}
	while(end_of_text < line_.empty())
	{
		if(line_[end_of_text] == ' ')
			break;
		end_of_text++;
	}
	std::any any = std::make_any<std::string>(line_.substr(0, end_of_text - 1));
	_var.insert({ {parent_,name_},any });
}

Config::Config(std::wstring file_)
{
	filename = file_;
	// load configs
	std::ifstream fin;
	fin.open(file_ + format);

	std::string group = "NULL";
	std::string variable;
	std::string line;
	while(!fin.eof())
	{
		std::getline(fin, line);

		if(line.empty()) // is it empty?
			continue;

		_clearcomments(line); // clear from comment
		if(line[0] == '[') // are first char scope from group?
		{
			// we have a deal with a new group
			group = _readgroup(line);
			continue;
		}
		if(!isletter(line[0])) // are first char letter?
			continue;
		variable = _readnamevariable(line); // we have a deal with variable and value
		// we're got name of variable, then we need extract value
		while(line[0] == ' ' || line[0] == '=')
			line = line.substr(1);
		if(isnumber(line[0])) // ok, then is it number?
		{
			_readnumber(line, group ,variable);
			continue;
		}
		// ok, then it's text, just copy it
		_readvalue(line, group ,variable);
	}

}

std::any &Config::get(std::string parent_, std::string index_)
{
	std::pair p = { parent_,index_ };
	return _var.find(p)->second;
}

Config::~Config()
{
	// save configs
	std::ofstream fout;
	fout.open(filename + format);
	// parse all configs
	std::string prev_group = "NULL";
	for(auto &iter : _var)
	{
		if(prev_group != iter.first.first)
		{
			prev_group = iter.first.first;
			fout << "[" << prev_group << "]\n";
		}
		fout << iter.first.second << " = ";
		if(iter.second.type().name() == "int")
			fout << std::any_cast<int>(iter.second);
		else if(iter.second.type().name() == "float")
			fout << std::any_cast<float>(iter.second);
		else
		{
			bool is_space = false;
			for(int i = 0;i< std::any_cast<std::string>(iter.second).size();i++)
				if(std::any_cast<std::string>(iter.second)[i] == ' ')
				{
					is_space = true;
					break;
				}

			if(is_space)
				fout << '"' << std::any_cast<std::string>(iter.second) << '"';
			else
				fout << std::any_cast<std::string>(iter.second);
		}
		fout << '\n';
	}
}
