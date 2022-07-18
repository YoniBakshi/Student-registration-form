#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "BaseValidator.h"
//base class to hold all fields
class BaseField
{
public:
	BaseField() {};
	virtual ~BaseField() {};
	virtual std::string getFieldMsg() const = 0;
	virtual std::string getStrContent() const = 0;
	virtual std::string getErrorMsgField() const = 0;
	virtual int getUserAnswer() const = 0;
	virtual void setField() = 0;
	virtual void setIsValid() = 0 ;
	virtual bool isFieldValid() const = 0;
	BaseValidator m_baseValidator;

};

