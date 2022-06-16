// ** ContainerMap v0.2
#include <iostream>
#include <string>
#include <map>

using namespace std;


map<int, int> Numbers;



void AddData(int _Key, int _Value);


int main(void)
{

	Numbers[0] = 0;
	Numbers[1] = 10;
	Numbers[2] = 20;
	Numbers.insert(make_pair(3, 30));

	Numbers[1] = 100;

	Numbers.insert(make_pair(4, 40));

	AddData(2, 200);
	
	for (map<int, int>::iterator iter = Numbers.begin();
		iter != Numbers.end() ; ++iter)
		cout << iter->second << endl;

	return 0;
}

void AddData(int _Key, int _Value)
{
	map<int, int>::iterator iter = Numbers.find(_Key);

	if (iter == Numbers.end())
		Numbers.insert(make_pair(_Key, _Value));
	else
		iter->second = _Value;
}
