#pragma once
#include <iostream>
#include <string>

class BaseValidator
{
public:
	BaseValidator();
	virtual ~BaseValidator();
	void setErrorMsg(std::string);
	std::string getErrorMsg() const;

protected:
	std::string m_errorMsg;
};

