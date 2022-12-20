#pragma once
#include <string>

class Tiger
{
public:
	Tiger() {}
	int  getHeigth();
	void setHeigth(int heigth);
	
private:
	int _heigth;
	std::string _name;
	std::string _color;
};

