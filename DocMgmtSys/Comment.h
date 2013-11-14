 #ifndef DocumentManagementSystem_Comment_H
#define DocumentManagementSystem_Comment_H

#include <iostream>
#include "Entity.h"

using std::string;

class Comment :	public Entity
{
private:
	string m_text;
	int m_ownerID;
	int m_docID;

	Comment(const Comment& obj);
	Comment& operator=(const Comment& obj);
public:
	Comment(const string& text,int ownerID, int docID);
	Comment(int ID, const string& text, int ownerID, int docID);
	~Comment();

	void Add();
	void Delete();
	void Show();
};

#endif //DocumentManagementSystem_Comment_H
