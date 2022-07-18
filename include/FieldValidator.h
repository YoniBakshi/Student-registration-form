#pragma once
#include "BaseValidator.h"

template<class Type>
class FieldValidator : public BaseValidator
{
public:
	FieldValidator() = default;
	~FieldValidator() = default;

	virtual bool isValid(const Type& type) const = 0;
};

