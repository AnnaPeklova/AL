#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include "Pipe.h"
#include "CS.h"
#include "Template.h"
#include "unordered_map"
#include "map"

using namespace std;

string file_name()
{
	string name_file;
	cout << "Введите название файла: ";
	cin.ignore(1, '\n');
	getline(cin, name_file);
	return name_file;
}

template <typename PC, typename T>
vector<int> Find_PipeOrCS_ByFilter(unordered_map<int, PC>& pc, Filter<PC, T> f, T param)
{
	vector <int> res;
	res.reserve(pc.size());
	for (auto& pipe_or_cs : pc)
	{
		if (f(pipe_or_cs.second, param))
			res.push_back(pipe_or_cs.first);
	}
	return res;
}

template <typename PC, typename T> 
using Filter = bool(*)(PC& pc, T param);

bool CheckByName(CS& cs, string param)
{
	return cs.Get_Name() == param;
}

bool CheckByRepair(Pipe& pipe, bool repair)
{
	return pipe.GetRepair() == repair;
}

bool CheckBy_Notworking_CS(CS& cs, float percent)
{
	return percent > ((cs.Get_amount() - cs.Get_amount_work()) / cs.Get_amount() * 100);
}

void delete_pipe(unordered_map<int, Pipe>& pipe_group)
{
	unordered_map<int, Pipe>::iterator number;
	unsigned int index;
	cout << "Введите ID трубы, которую нужно удалить: ";
	index = checking(1u, pipe_group.size(), "Введите ID трубы, которую нужно удалить: ");
	number = pipe_group.find(index);
	pipe_group.erase(number);
}

void delete_cs(unordered_map<int, CS>& cs_group)
{
	unordered_map<int, CS>::iterator number;
	unsigned int index;
	cout << "Введите ID КС, которую нужно удалить: ";
	index = checking(1u, cs_group.size(), "Введите ID КС, которую нужно удалить: ");
	number = cs_group.find(index);
	cs_group.erase(number);
}

void menu()
{
	system("cls");
	cout << "1.Добавить трубу" << endl;
	cout << "2.Добавить КС" << endl;
	cout << "3.Просмотр информации о трубе" << endl;
	cout << "4.Просмотр информации о КС" << endl;
	cout << "5.Редактировать трубу" << endl;
	cout << "6.Редактировать КС" << endl;
	cout << "7.Сохранить трубы" << endl;
	cout << "8.Сохранить КС" << endl;
	cout << "9.Загрузить трубы" << endl;
	cout << "10.Загрузить КС" << endl;
	cout << "11. Поиск труб по признаку 'в ремонте'" << endl;
	cout << "12. Поиск КС по проценту незадействованных цехов" << endl;
	cout << "13. Поиск КС по названию" << endl;
	cout << "14. Удалить трубу" << endl;
	cout << "15. Удалить КС" << endl;
	cout << "16. Пакетное редактирование труб" << endl;
	cout << "0.Выход" << endl;
	cout << "Введите команду: ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	unordered_map<int, Pipe> pipe_group;
	unordered_map<int, CS> cs_group;

	while (true)
	{
		menu();
		int command;
		cout << "Введите команду: ";
		command = checking(0, 16, "Введите команду: ");
		switch (command)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			Pipe pipe
			pipe_group.push_back(pipe);
			break;
		}
		case 2:
		{
			CS cs;
			cs_group.push_back(cs);
			break;
		}
		case 3:
		{
			
			system("Pause");
			break;
		}
		case 4:
		{
			
			system("Pause");
			
			break;
		}
		case 5:
		{
			
			system("Pause");
			break;
		}
		case 6:
		{
		
			system("Pause");
			break;
		}
		case 7:
		{
			
			system("Pause");
			break;
		}
		case 8:
		{
			
			system("Pause");
			break;
		}
		case 9:
		{
			
			break;
		}
		case 10:
		{
			
			break;
		}
		}
	}
}