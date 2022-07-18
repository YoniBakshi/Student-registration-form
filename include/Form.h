#pragma once
#include<iostream>
#include<vector>

#include "BaseField.h"
#include "Field.h"
#include "FormValidator.h"
#include "FieldValidator.h"

class Form
{
public:
	Form();
	~Form();
	bool validateForm() const;
	void fillForm();
	void addField(BaseField* newField);
	void addValidator(FormValidator* newFormValidPtr);
	size_t getNumOfFields() const;
	BaseField* operator[](int index) const;

private:
	std::vector<BaseField*> m_baseFieldsVec;
	std::vector<FormValidator*> m_formValidVec;
	bool m_isFormCorrect;
};

std::ostream& operator<<(std::ostream& output, const Form& form);