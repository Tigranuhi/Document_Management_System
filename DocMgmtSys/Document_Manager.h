#ifndef DOCUMENTMANAGEMENTSYSTEM_DOCUMENT_MANAGER_H
#define DOCUMENTMANAGEMENTSYSTEM_DOCUMENT_MANAGER_H

#include <vector>
#include "Document.h"
#include "Workspace.h"
#include <string>

using std::vector;

class document_manager
{
private:
    document_manager();
    document_manager(const document_manager& obj);
    document_manager& operator=(const document_manager& obj);

    vector<Document> cur_docs;
    vector<Workspace> cur_workspaces;
    vector<Comment> cur_comments;

public:
    //singleton block
    static document_manager* s_instance = nullptr;
    static document_manager* get_instance();
    static void remove_instance();

    //functions conserned to docs
    void add_doc(const Document& doc);
    void add_doc_to_db(const Document& doc);
    void remove_doc(int docID);
    void remove_doc_from_db(int docID);
	void update_doc_in_db(const Document& doc);
    void empty_doc();
    void show_docs();
    void show_docs(int start_index, int end_index);
    void on_doc_double_click(const Document& doc);
    void on_doc_right_click(const Document& doc);

    void Upload(const Document& doc);
    void Delete(const Document& doc);
    void Rename(const string& newName);
    void Move(int newWorkspaceID);
    void Edit(const Document& doc);
    void Share(list<int> userIDs);
    void Archive(const Document& doc);
    Document* Search(string doc_name, int workspace_id=0);

    //functions conserned to workspaces
    void add_workspace(const Workspace& ws);
    void add_workspace_to_db(const Workspace& ws);
    void remove_workspace(int wsID);
    void remove_workspace_from_db(int wsID);
	void update_workspace_in_db(const Workspace& ws);
    void empty_workspace();
    void show_workspaceses();
    void show_workspaceses(int start_index, int end_index);
    void on_workspace_double_click(const Workspace& ws);
    void on_workspace_right_click(const Workspace& ws);

    void Create(const Workspace& ws);
    void Delete(const Workspace& ws);
    void Rename(const string& newTitle);
    void ChangeVisibilityStatus(list<Document> docsInCurrentWorkspace);

    //functions conserned to comments
    void add_comment(const Comment& commnet);
    void add_comment_to_db(const Comment& comment);
    void remove_comment(int commentID);
    void remove_comment_from_db(int commentID);
    void empty_comment();
    void show_comments();
    void show_comments(int start_index, int end_index);

    void Add(const Comment& commnet);
    void Delete(const Comment& commnet);
};

#endif // DOCUMENTMANAGEMENTSYSTEM_DOCUMENT_MANAGER_H
