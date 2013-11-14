#ifndef DocumentManagementSystem_User_H
#define DocumentManagementSystem_User_H

#include <iostream>
#include "Entity.h"
#include "Document.h"
#include "Workspace.h"
#include "Comment.h"
#include <list>

using std::string;
using std::list;

class User : public Entity
{
private:
	string m_fullName;
	string m_eMail;
	string m_username;
	string m_password;
	string m_picture;

	User(const User& obj);
	User& operator=(const User& obj);
public:
	User(string fullName, string eMail, string username, string password, string picture);
	User(int id, string fullName, string eMail, string picture);
	~User();
	
	//Achtung, Achtung, this set(get)ters are not sertificated and approved by Vardan Grigoryan, so they can be modified!!!
	//setters
	void set_fullName(const string& fullName);
	void set_eMail(const string& eMail);
	void set_username(const string& username);
	void set_password(const string& password);
	void set_picture(const string& picture);

	//getters
	string get_fullName() const;
	string get_eMail() const;
	string get_username() const;
	string get_password() const;
	string get_picture() const;

	//others
	void Add();

	list<Document> documentsOfCurrentUser;
	list<Workspace> workspacesOfCurrentUser;
	list<Comment> commentsOfCurrentUser;
};

#endif //DocumentManagementSystem_User_H