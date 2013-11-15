#ifndef DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
#define DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H

#include <iostream>
#include "Query.h"
#include <string>
#include <sqlite3.h>

class db_manager
{
private:
    db_manager()
    {
    	rc = sqlite3_open(db_path, &db);
    }
    db_manager(const db_manager& obj);
    db_manager& operator=(const db_manager& obj);

    Query m_qr;
    std::string db_path;
    
    //db(connection)
    sqlite3* db;
    char* err_msg = "";
    int rc;
    
    //db_call_back function
    int call_back(void *NotUsed, int argc, char **argv, char **azColName)
    {
    	//TODO
    }

    
public:
    //singleton block
    static db_manager* s_instance = nullptr;
    static db_manager* get_instance()
    {
    	s_instance = new db_manager;
    	if(get_permission())
    	{
        	return nullptr;
    	}
    	else
    	{
    		return s_instance;
    	}
    	
    }
    static void remove_instance()
    {
        delete s_instance;
        s_instance = nullptr;
    }

    //setter
    void set_query(const Query& qr)
    {
    	m_qr = qr;
    }
    void set_db_path(const std::string& path)
    {
    	db_path = path;
    }

    //others
    bool get_permission()
    {
    	if(rc)
    	{
    		return false;
    	}
    	else
    	{
    		return true;
    	}
    }
    
    void execute()
    {
	sqlite3_exec(db, m_qr.get_result(), call_back, 0, &err_msg);
    }
};

#endif // DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
