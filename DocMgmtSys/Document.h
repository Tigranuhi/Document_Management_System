#ifndef DocumentManagementSystem_Document_H
#define DocumentManagementSystem_Document_H

#include <iostream>
#include "Entity.h"
#include "Comment.h"
#include <list>

using std::string;
using std::list;

class Document : public Entity
{
private:
	string m_path;
	string m_title;
	string m_extension;
	double m_size;
	int m_ownerID;
	int m_version;
	int m_workspaceID;
	string m_visibilityStatus;

	Document(const Document& obj);
	Document& operator=(const Document& obj);
public:
	Document(const string& path, int workspaceID,const string& visibilityStatus, list<int> userIDs);
	Document(const string& title, const string& extension, size_t size, int ownerID, list<int> userIDs, int version, int workspaceID, const string& visibility_status);
	~Document();
	
	//setters
	void set_path(const string& path);
	void set_title(const string& title);
	void set_extension(const string& extension);
	void set_size(size_t size);
	void set_ownerID(int ownerID);
	void set_version(int version);
	void set_workspaceID(int workspaceID);
	void set_visibilityStatus(const string& visibilityStatus);

	//getters
	string get_path() const;
	string get_title() const;
	string get_extension() const;
	double get_size() const;
	int get_ownerID() const;
	int get_version() const;
	int get_workspaceID() const;
	string get_visibilityStatus() const;

	list<Comment> commentsOfThisDocument;
	list<int> IDsOfThoseUsersWhoCanSeeThisDocument;
};

#endif //DocumentManagementSystem_Document_H
