#ifndef DocumentManagementSystem_Query_H
#define DocumentManagementSystem_Query_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Condition.h"

using std::vector;

class Query
{
private:
	Query(const Query& obj);
	Query& operator=(const Query& obj);

    std::string m_table_name;
    vector<std::string> column_names;
    vector<std::string> values;
	Condition m_cond;
    std::string m_type;

    std::string near_to_select;
public:
    Query()
        :near_to_select("")
    {}
	~Query();

	//setters
    void set_tableName(const std::string& tblName)
    {
        m_table_name = tblName;
    }
    void add_column_name(const std::string& columnName)
    {
        column_names.push_back(columnName);
    }
    void add_value(const std::string& str)
    {
        values.push_back(str);
    }
    void add_value(int i)
    {
        std::stringstream stream;
        std::string tmp;
        stream << i;
        stream >> tmp;
        values.push_back(tmp);
    }

    void set_condition(const Condition& c)
    {
        m_cond = c;
    }

    void set_type(int type)
    {
        switch(type)
        {
            case 0:
                m_type = "INSERT";
                break;
            case 1:
                m_type = "SELECT";
                break;
            case 2:
                m_type = "DELETE";
                break;
            case 3:
                m_type = "UPDATE";
                break;
            default:
                m_type = "INSERT";
                break;
        }
    }

	//getters
	std::string get_type() const
	{
		return m_type;
	}
	
	std::string get_result()
	{
		string result = "";
		if (m_type == "INSERT")
		{
			result = m_type + " INTO " + m_table_name + "(";
			int size = column_names.size();
			for (int i = 0; i < size - 1; ++i)
			{
				result += column_names[i];
				result += ", ";
			}
			result += (column_names[size-1] + ")");
			result += " VALUES (";
			for (int i = 0; i < size - 1; ++i)
			{
				result += values[i];
				result += ", ";
			}
			result += (column_names[size-1] + ")");
			result += ";";

            return result;
		}

		if (m_type == "SELECT")
		{
			string result = "";
            result = m_type + " " + near_to_select + " FROM " + m_table_name + " WHERE " + m_cond.get_value() + ";";

            return result;
        }

        if (m_type == "DELETE")
        {
            string result = "";
            result = m_type + " FROM " + m_table_name + " WHERE " + m_cond.get_value() + ";";

            return result;
        }

        if (m_type == "UPDATE")
        {
            string result = "";
            result = m_type + m_table_name + " SET " + column_names[0] + " = " + values[0] + " WHERE " + m_cond.get_value() + ";";

            return result;
        }

	}
	
    //others
    void reset_query()
    {
        m_table_name = "";
        column_names.clear();
        values.clear();
        m_type = "";

        near_to_select = "*";
    }

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
