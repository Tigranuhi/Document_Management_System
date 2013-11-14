#ifndef DocumentManagementSystem_Notification_H
#define DocumentManagementSystem_Notification_H

#include <iostream>
#include "Entity.h"
#include <list>

using std::list;
using std::string;

class Notification : public Entity
{
private:
	int m_ownerID;
	int m_type;
	int m_docID;

	Notification(const Notification& obj);
	Notification& operator=(const Notification& obj);
public:
	Notification(int ownerID, int type, int docID, list<int> UsersNotIsAbout);
	Notification(int ID, int ownerID, int type, int docID, list<int> UsersNotIsAbout);
	~Notification();

	//setters
	void set_ownerID(int id);
	void set_type(int type);
	void set_docID(int docID);
	void set_userID(int userID);

	//getters
	int get_ownerID() const;
	string get_type() const;
	int get_docID() const;
	list<int> get_users() const;

	//others
	void Create();
	void Show();
	void Delete();

	list<int> users;

	//type
	enum notificationType
	{
		SHARING,
		COMMENT
	};
};

#endif //DocumentManagementSystem_Notification_H