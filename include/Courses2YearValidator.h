#pragma once
#include "FormValidator.h"
#include "Field.h"

template<class Type1, class Type2>
class Courses2YearValidator : public FormValidator
{
public:
	Courses2YearValidator(Type1* currcours, Type2* currYear);
	~Courses2YearValidator() = default;
	bool formValid() const;

private:
	Type1* m_field1;
	Type2* m_field2;
	const int max1And2 = 6;
	const int max3And4 = 10;
	const int max5 = 8;
};

template<typename Type1, typename Type2>
inline Courses2YearValidator<Type1, Type2>::Courses2YearValidator(Type1* currcours, Type2* currYear)
	: m_field1(currcours), m_field2(currYear)
{
	FormValidator::setErrorMsg("Courses and year don't match");
}


template<typename Type1, typename Type2>
inline bool Courses2YearValidator<Type1, Type2>::formValid() const
{

	int course = m_field1->userAnswer();
	int year = m_field2->userAnswer();

	if ((year == 1 || year == 2) &&  (course <= max1And2))
		return true;
	else if ((year == 3 || year == 4) && (course <= max3And4))
		return true;
	else if (year >= 5 && (course <= max5))
		return true;

	m_field1->setIsValid();
	m_field2->setIsValid();
	return false;
}