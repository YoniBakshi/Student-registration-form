#pragma once
#include "BaseValidator.h"
#include "Field.h"

class FormValidator : public BaseValidator
{
public:
	FormValidator();
	~FormValidator();
	virtual bool formValid() const = 0;
};

