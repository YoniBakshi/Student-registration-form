#include "Form.h"

Form::Form()
	: m_isFormCorrect(false)
{
}

Form::~Form()
{
}

bool Form::validateForm() const
{
	return m_isFormCorrect;
}

//set the form
void Form::fillForm()
{
	m_isFormCorrect = true;
	for (auto& currField : m_baseFieldsVec)
	{
		if (!currField->isFieldValid())					//Check if specific filled field is all valid
		{
			currField->setField();
			m_isFormCorrect = false;
		}
	}
	if (m_isFormCorrect)
		for (auto& formCheck : m_formValidVec)
		{
			if (!formCheck->formValid())				//check tow conditions of fields
			{
				std::cout << formCheck->getErrorMsg() << "\n";
				fillForm();
				m_isFormCorrect = false;
			}
		}
}

void Form::addField(BaseField* newField)
{
	m_baseFieldsVec.push_back(newField);
}

void Form::addValidator(FormValidator* newFormValidPtr)
{
	m_formValidVec.push_back(newFormValidPtr);
}

//how many fields
size_t Form::getNumOfFields() const
{
	return m_baseFieldsVec.size();
}

//currntly to use ate the output
BaseField* Form::operator[](int index) const
{
	if (0 <= index && index < m_baseFieldsVec.size())
		return m_baseFieldsVec[index];
	return nullptr;
}

//output form
std::ostream& operator<<(std::ostream& output, const Form& form)
{
	for (int i = 0; i < form.getNumOfFields(); i++)
	{
		output << "------------------------------------------------------------------------\n"
			<< '\n' << form[i]->getFieldMsg()
			<< "\n\n-------------------------------------------------------------------------\n";
	}
	return output;
}
