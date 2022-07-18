#pragma once
#include <string>
#include "FieldValidator.h"


class NoDigitValidator : public FieldValidator<std::string>
{
public:
	NoDigitValidator();
	~NoDigitValidator();

	virtual bool isValid(const std::string& str) const override;

};


