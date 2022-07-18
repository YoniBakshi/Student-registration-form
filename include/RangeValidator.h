#pragma once
#include "FieldValidator.h"

template <class Type>
class RangeValidator : public FieldValidator<Type>
{
public:
	RangeValidator(Type t1, Type t2);
	~RangeValidator();

	virtual bool isValid(const Type& type) const override;

private:
	Type m_rangeMax, m_rangeMin;

};

template<class Type>
inline RangeValidator<Type>::~RangeValidator()
{
}


template<class Type>
inline RangeValidator<Type>::RangeValidator(Type t1, Type t2) :
	m_rangeMax(t1),
	m_rangeMin(t2)
{
	FieldValidator<Type>::setErrorMsg("Out of range.");
}


template<class Type>
inline bool RangeValidator<Type>::isValid(const Type& type) const
{
	return (type >= m_rangeMax && type <= m_rangeMin);
}

