#include "IdValidator.h"

IDValidator::IDValidator()
{
	setErrorMsg("Wrong control digits");
}

IDValidator::~IDValidator()
{
}
//id algorethem
bool IDValidator::isValid(const uint32_t& id) const
{
	uint32_t currDigit, tempId = id;

	uint32_t keyDigit;
	int sum = 0;

	keyDigit = tempId % m_digitMod;
	tempId /= m_digitMod;

	for (int index = 0; index < m_maxDigits && tempId > 0; index++)
	{
		int multiplier = (index % 2 == 0 ? 2 : 1);
		currDigit = ((tempId % m_digitMod) * multiplier);

		if (currDigit / m_digitMod > 0)
			currDigit = (currDigit % m_digitMod) + 1;

		sum += currDigit;
		tempId /= m_digitMod;
	}

	return (keyDigit == (m_digitMod - (sum % m_digitMod)));
}