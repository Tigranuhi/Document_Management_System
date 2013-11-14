#ifndef DOCUMENTMANAGEMENTSYSTEM_NOTIFICATION_MANAGER_H
#define DOCUMENTMANAGEMENTSYSTEM_NOTIFICATION_MANAGER_H

#include "Notification.h"
#include <vector>

class notification_manager
{
private:
    notification_manager();
    notification_manager(const notification_manager& obj);
    notification_manager& operator=(const notification_manager& obj);

    std::vector<Notification> cur_nots;

public:
    //singleton block
    static notification_manager* s_instance = nullptr;
    static notification_manager* get_instnace();
    static void remove_instance();

    //functions referred to nots
    void add_notification(const Notification& ntf);
    void add_ntf_to_db(const Notification& ntf);
    void remove_ntf(int ntfID);
    void remove_ntf_from_db(int ntfID);
    void empty_ntf();
    void show_ntfs();
    void show_ntfs(int start_index, int end_index);

    void Create(const Notification& ntf);
    void Delete(const Notification& ntf);
};

#endif // DOCUMENTMANAGEMENTSYSTEM_NOTIFICATION_MANAGER_H
