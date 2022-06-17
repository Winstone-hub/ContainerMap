// ** ContainerMap v0.4
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};

	Vector3(const float& _x, const float& _y) : x(_x), y(_y), z(0.0f) {};

	Vector3(const float& _x, const float& _y, const float& _z)
		: x(_x), y(_y), z(_z) {};
};

struct Trasnform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};





struct Object
{
	Trasnform Info;

	Object() {};

	Object(const Trasnform& _Info) : Info(_Info) {};
};

struct Player : public Object
{
	Player() {};

	Player(const Trasnform& _Info) : Object(_Info) {};
};


// ** 오브젝트 몃개 더 추가함.
struct Enemy : public Object
{
	Enemy() {};

	Enemy(const Trasnform& _Info) : Object(_Info) {};
};

struct Bullet : public Object
{
	Bullet() {};

	Bullet(const Trasnform& _Info) : Object(_Info) {};
};

struct Boss : public Object
{
	Boss() {};

	Boss(const Trasnform& _Info) : Object(_Info) {};
};




map<string, list<Object*>> Objects;


void Initialize();
void AddObject(string _Key, Object* _Object);


int main(void)
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;
	
	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));
	AddObject("Player", new Player(Info));

	Info.Position.x = 100;
	Info.Position.y = 200;
	Info.Position.z = 300;

	AddObject("Enemy", new Enemy(Info));
	AddObject("Enemy", new Enemy(Info));

	Info.Position.x = 1000;
	Info.Position.y = 2000;
	Info.Position.z = 3000;

	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));
	AddObject("Bullet", new Bullet(Info));

	Info.Position.x = 10000;
	Info.Position.y = 20000;
	Info.Position.z = 30000;

	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));
	AddObject("Boss", new Boss(Info));

	for (map<string, list<Object*>>::iterator iter = Objects.begin(); 
		iter != Objects.end(); ++iter)
	{
		cout << " [" << iter->first << "] " << endl;
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << (*iter2)->Info.Position.x << ", " <<
				(*iter2)->Info.Position.y << ", " << (*iter2)->Info.Position.z << endl;
		}
		cout << endl;
	}

	return 0;
}

void Initialize()
{
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}

void AddObject(string _Key, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = Objects.find(_Key);

	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	else
		iter->second.push_back(_Object);
}
