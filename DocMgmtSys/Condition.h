#ifndef DocumentManagementSystem_Condition_H
#define DocumentManagementSystem_Condition_H

#include <string>
using std::string;

class Condition
{
private:
	string m_value;
	
public:
	Condition(const string& column,const string& my_operator,const string& value);
	Condition(const string& column,const string& my_operator,int value);
	~Condition();
	Condition(const Condition& obj);
	Condition& operator=(const Condition& obj);

	Condition& operator+(const Condition& rhs);
	Condition& operator+=(const Condition& rhs);
	Condition& operator*(const Condition& rhs);
	Condition& operator*=(const Condition& rhs);	

	//getters
	string get_value() const;
};

#endif //DocumentManagementSystem_Condition_H
