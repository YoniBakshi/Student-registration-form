#pragma once
#include "BaseField.h"
#include "FieldValidator.h"
#include "FacultyValue.h"

template<class Type>
class Field : public BaseField
{
public:
	Field(const std::string& fieldMsgQ);
	void addValidator(FieldValidator<Type>* validator);
	virtual std::string getErrorMsgField() const;
	virtual std::string getFieldMsg() const;
	virtual std::string getStrContent() const override; 
	virtual int getUserAnswer() const override;
	virtual void setField() override;
	virtual void setIsValid() override;
	virtual bool isFieldValid() const override;
	Type userAnswer();

private:
	bool m_isValid;
	Type m_fieldUserAnswer;
	std::string m_fieldMsgQuestion;
	FieldValidator<Type>* m_fieldValidatorPtr;
};

template<class Type>
inline Field<Type>::Field(const std::string& fieldMsgQ)
	:m_isValid(false), m_fieldValidatorPtr(nullptr)
{
	m_fieldMsgQuestion = fieldMsgQ;
}
//get msg to print
template<class Type>
inline std::string Field<Type>::getFieldMsg() const
{
	std::string msg = m_fieldMsgQuestion + " = " + getStrContent();
	if (!m_isValid)
		return msg = msg + "		" + m_fieldValidatorPtr->getErrorMsg();
	return msg;
}
//fill the field
template<class Type>
inline void Field<Type>::setField()
{
	std::cout << m_fieldMsgQuestion << '\n';
	std::cin >> m_fieldUserAnswer;
	m_isValid = m_fieldValidatorPtr->isValid(m_fieldUserAnswer);
}

template<class Type>
inline void Field<Type>::addValidator(FieldValidator<Type>* validator)
{
	m_fieldValidatorPtr = validator;
}

template<class Type>
inline bool Field<Type>::isFieldValid() const
{
	return m_isValid;
}

template<class Type>
inline Type Field<Type>::userAnswer()
{
	return m_fieldUserAnswer;
}

template<class Type>
inline int Field<Type>::getUserAnswer() const
{
	return std::atoi(getStrContent().c_str());
}

template<class Type>
inline void Field<Type>::setIsValid()
{
	m_isValid = false;
}

//convert to string for printing
template<class Type>
inline std::string Field<Type>::getStrContent() const
{
	std::ostringstream base_str;
	base_str << m_fieldUserAnswer;
	return base_str.str();

}

template<class Type>
inline std::string Field<Type>::getErrorMsgField() const
{
	return m_baseValidator.getErrorMsg();
}
