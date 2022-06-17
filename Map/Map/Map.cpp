// ** ContainerMap v0.3
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

map<string, list<Object*>> Objects;

void Initialize();
void AddObject(string _Key, Object* _Object);

int main(void)
{
	//Initialize();
	Trasnform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	AddObject("Player", new Player(Info));

	//cout << Objects["Player"]->Info.Position.x << endl;
	//cout << Objects["Player"]->Info.Position.y << endl;
	//cout << Objects["Player"]->Info.Position.z << endl;

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
