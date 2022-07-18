#pragma once
#include "FieldValidator.h"

template <class Type>
class MinValidator : public FieldValidator<Type>
{
public:
	MinValidator(Type shorty);
	~MinValidator();

	virtual bool isValid(const Type& num) const override;

private:
	Type m_shorty;
};

template<class Type>
inline MinValidator<Type>::MinValidator(Type shorty)
{
	m_shorty = shorty;
	FieldValidator<Type>::setErrorMsg("Minimum of courses is 2.");
}

template<class Type>
inline MinValidator<Type>::~MinValidator()
{
}

template<class Type>
inline bool MinValidator<Type>::isValid(const Type& num) const
{
	return num >= m_shorty;
}