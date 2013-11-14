#ifndef DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
#define DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H

#include "Query.h"

class db_manager
{
private:
    db_manager();
    db_manager(const db_manager& obj);
    db_manager& operator=(const db_manager& obj);

    Query qr;

public:
    //singleton block
    static db_manager* s_instance = nullptr;
    static db_manager* get_instance();
    static void remove_instance();

    //setter
    void set_query(const Query& qr);
    //getter
    Query get_query() const;
    //others
    void execute(const Query& qr);
};

#endif // DOCUMENTMANAGEMENTSYSTEM_DB_MANAGER_H
