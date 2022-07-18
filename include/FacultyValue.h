#pragma once
//#include "FormValidator.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>

class FacultyValue
{
public:
	FacultyValue(int num = -1);
	FacultyValue(FacultyValue& other);
	~FacultyValue();
	int getFacultyValInt() const;
	void readFacultyVal(std::istream& is);
	void operator=(const FacultyValue& other);
	std::string getFacultyValStr() const;

private:
	int m_currFacultyVal;
	//1 - Computer Science, 2 -Medicine , 3 - Literature		
	std::vector<std::string> m_strFacultyVec;

};

std::ostream& operator<<(std::ostream& os, const FacultyValue& facultyValue);
std::istream& operator>>(std::istream& is, FacultyValue& facultyValue);

bool operator<(const FacultyValue& left, const FacultyValue& right);
bool operator>(const FacultyValue& left, const FacultyValue& right);
bool operator>=(const FacultyValue& left, const FacultyValue& right);
bool operator<=(const FacultyValue& left, const FacultyValue& right);
bool operator==(const FacultyValue& left, const FacultyValue& right);
