#pragma once
#include "FieldValidator.h"
#include <cstdint>

class IDValidator : public FieldValidator<uint32_t>
{
public:
	IDValidator();
	~IDValidator();

	virtual bool isValid(const uint32_t& id) const override;
private:
	const uint32_t m_digitMod = 10;
	const int m_maxDigits = 8;
};