#ifndef DocumentManagementSystem_USER_MANAGER_H
#define DocumentManagementSystem_USER_MANAGER_H

#include "User.h"
#include <vector>

class user_manager
{
private:
	user_manager();
	user_manager(const user_manager& obj);
	user_manager& operator=(const user_manager& obj);

	User current_user;
	vector<User> other_users;
public:
	//singleton block
	static user_manager* s_instance = nullptr;
	static user_manager* get_instance();
	static void remove_instance();

	//functions referreed to users
	void set_user(const User& usr);
	User get_user() const;
	void add_user_to_db(const User& usr);
	void remove_user_from_db(const User& usr);

	void include_users();
	
}
#endif // DocumentManagementSystem_USER_MANAGER_H
