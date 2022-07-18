#include "BaseValidator.h"

BaseValidator::BaseValidator()
{
}

BaseValidator::~BaseValidator()
{
}

void BaseValidator::setErrorMsg(std::string msg)
{
	m_errorMsg = msg;
}

std::string BaseValidator::getErrorMsg() const
{
	return m_errorMsg + '\n';
}
