#ifndef DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
#define DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H

#include "Query.h"
#include <sqlite3>

class db_manager
{
private:
    db_manager();
    db_manager(const db_manager& obj);
    db_manager& operator=(const db_manager& obj);

    Query m_qr;

public:
    //singleton block
    static db_manager* s_instance = nullptr;
    static db_manager* get_instance()
    {
        s_instance = new db_manager;
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

    //others
    void execute()
	{

    }
};

#endif // DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
