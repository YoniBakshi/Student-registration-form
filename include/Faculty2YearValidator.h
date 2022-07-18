#pragma once
#include "FormValidator.h"
#include "Field.h"
template<class Type1, class Type2>
class Faculty2YearValidator : public FormValidator
{
public:
	Faculty2YearValidator(Type1* currFacultyVal, Type2* currYear);
	~Faculty2YearValidator() = default;
	bool formValid() const;

private:
	Type1* m_field1;
	Type2* m_field2;
	int m_maxYearFacultyVec[3];
};

template<class Type1, class Type2>
inline Faculty2YearValidator<Type1, Type2>::Faculty2YearValidator(Type1* currFacultyVal, Type2* currYear)
	: m_field1(currFacultyVal), m_field2(currYear)
{
	m_maxYearFacultyVec[0] = 4;
	m_maxYearFacultyVec[1] = 7;
	m_maxYearFacultyVec[2] = 3;
	FormValidator::setErrorMsg("Faculty and year don't match");
}


template<class Type1, class Type2>
inline bool Faculty2YearValidator<Type1, Type2>::formValid() const
{
	int i = m_field1->userAnswer().getFacultyValInt() - 1;
	if (m_field2->userAnswer() <= m_maxYearFacultyVec[i])
		return true;

	m_field1->setIsValid();
	m_field2->setIsValid();
	return false;
}
