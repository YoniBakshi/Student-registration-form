#include "NoDigitValidator.h"


NoDigitValidator::NoDigitValidator()
{
	setErrorMsg("Can't contain digits");
}

NoDigitValidator::~NoDigitValidator()
{
}

bool NoDigitValidator::isValid(const std::string& str) const
{
	for (int i = 0; i < str.size(); ++i)
		if (isdigit(str[i]))
			return false;

	return true;
}