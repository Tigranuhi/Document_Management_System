#ifndef DocumentManagementSystem_Entity_H
#define DocumentManagementSystem_Entity_H

class Entity
{
private:
	int m_id;

	Entity(const Entity& obj);
	Entity& operator=(const Entity& obj);

public:
	Entity();
	~Entity();

	//setters
	void set_id(int id);

	//getters
	int get_id() const;
};

#endif //DocumentManagementSystem_Entity_H