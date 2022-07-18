#include "FacultyValue.h"


FacultyValue::FacultyValue(int num) : m_currFacultyVal(num)
{
	m_strFacultyVec.push_back("Computer Science");
	m_strFacultyVec.push_back("Medicine");
	m_strFacultyVec.push_back("Literature");
}
//copy constrector to make changes by need
FacultyValue::FacultyValue(FacultyValue& other): FacultyValue(other.getFacultyValInt())
{
}

FacultyValue::~FacultyValue()
{
}

void FacultyValue::readFacultyVal(std::istream& is)
// the function get std::istream by & 
// and read the input directly to the member.
{
	is >> m_currFacultyVal;
}
//return a string of the faculty
std::string FacultyValue::getFacultyValStr() const
{
	switch (m_currFacultyVal)
	{
	case 1: return m_strFacultyVec[0];
	case 2:	return m_strFacultyVec[1];
	case 3:	return m_strFacultyVec[2];
	default:break;
	}
	return std::to_string(m_currFacultyVal);
}
//return a int of the faculty
int FacultyValue::getFacultyValInt() const
{
	return m_currFacultyVal;
}

void FacultyValue::operator=(const FacultyValue& other)
{
	m_currFacultyVal = other.getFacultyValInt();
}

std::ostream& operator<<(std::ostream& os, const FacultyValue& facultyValue)
{
	return os << facultyValue.getFacultyValStr();
}

std::istream& operator>>(std::istream& is, FacultyValue& facultyValue)
{
	// insted to read the input to a int parameter 
	// and send the parameter to the function we send the 
	// std::istream by & to the class and we read the input
	// directly to the int member prameter of the class.

	facultyValue.readFacultyVal(is);
	return is;
}

bool operator<(const FacultyValue& left, const FacultyValue& right)
{
	return (left.getFacultyValInt() < right.getFacultyValInt());
}

bool operator>(const FacultyValue& left, const FacultyValue& right)
{
	return (left.getFacultyValInt() > right.getFacultyValInt());
}

bool operator>=(const FacultyValue& left, const FacultyValue& right)
{
	//Re-use
	return !(left < right);
}

bool operator<=(const FacultyValue& left, const FacultyValue& right)
{
	//Re-use
	return !(left > right);
}

bool operator==(const FacultyValue& left, const FacultyValue& right)
{
	//Re-use
	return (left >= right && left <= right);
}
