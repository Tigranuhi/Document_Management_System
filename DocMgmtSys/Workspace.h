#ifndef DocumentManagementSystem_Workspace_H
#define DocumentManagementSystem_Workspace_H

#include <iostream>
#include "Entity.h"
#include "Document.h"
#include <list>

using std::string;
using std::list;

class Workspace : public Entity
{
private:
	string m_title;
	string m_visibilityStatus = "private";

	Workspace(const Workspace& obj);
	Workspace& operator=(const Workspace& obj);
public:
	Workspace(const string& title);
	Workspace(int ID, const string& title, const string& visibilityStatus);
	~Workspace();

	//setters
	void set_title(const string& title);
	void set_visibilityStatus(const string& title);

	//getters
	string get_title() const;
	string get_visibilityStatus() const;

	list<Document> docsInCurrentWorkspace;
};

#endif //DocumentManagementSystem_Workspace_H
