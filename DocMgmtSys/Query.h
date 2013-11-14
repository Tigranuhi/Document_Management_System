#ifndef DocumentManagementSystem_Query_H
#define DocumentManagementSystem_Query_H

#include <iostream>
#include <map>
#include "Condition.h"

using std::string;
using std::map;

class Query
{
private:
	Query(const Query& obj);
	Query& operator=(const Query& obj);

	string m_tableName;
	map<string, string> column_value;
	Condition cond;
	string type;
public:
	Query();
	~Query();

	//setters
	void set_tableName(const string& tblName);

	void add_column_value(const string& columnName, const string& obj);
	void add_column_value(const string& columnName, int i);

	void set_condition(const Condition& c);

	void set_type(int type);
	//getters
	int get_condition_id() const;
	
	//others
	int* Execute() const;

	//query_type
	enum query_type
	{
		INSERT,
		SELECT,
		DELETE,
		UPDATE
	};
};

#endif //DocumentManagementSystem_Query_H