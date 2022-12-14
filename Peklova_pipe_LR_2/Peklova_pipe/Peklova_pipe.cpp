#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pipe.h"
#include "CS.h"
#include "Template.h"
#include "unordered_map"
#include "map"

using namespace std;

void delete_pipe(unordered_map<int, Pipe>& pipe_group)
{
	unordered_map<int, Pipe>::iterator number;
	unsigned int index;
	cout << "Введите ID трубы, которую нужно удалить: ";
	index = checking(1u, Pipe::GetMaxID(), "Введите ID трубы, которую нужно удалить: ");
	number = pipe_group.find(index);
	if (pipe_group.count(index) != 0)
	{
		while (pipe_group.count(index) != 0)
		{
			pipe_group.erase(number);
		}
	}
	else
		cout << "Труба не найдена!\n";
}

void delete_cs(unordered_map<int, CS>& cs_group)
{
	unordered_map<int, CS>::iterator number;
	unsigned int index;
	cout << "Введите ID КС, которую нужно удалить: ";
	index = checking(1u, CS::GetMaxID(), "Введите ID КС, которую нужно удалить: ");
	number = cs_group.find(index);
	cs_group.erase(number);
}

string file_name()
{
	string name_file;
	cout << "Введите название файла: ";
	cin.ignore(1, '\n');
	getline(cin, name_file);
	return name_file;
}

void menu()
{
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
}

template<typename PC, typename T>
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

template<typename PC, typename T>
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
			Pipe pipe;
			cin >> pipe;
			pipe_group.insert(pair<int, Pipe>(pipe.GetId(), pipe));
			break;
		}
		case 2:
		{
			CS cs;
			cin >> cs;
			cs_group.insert(pair<int, CS>(cs.GetId(), cs));
			break;

		}
		case 3:
		{
			if (pipe_group.size() > 0)
				for (auto& iter : pipe_group)
				{
					cout << endl;
					cout << iter.second << endl;
				}
			else 
				cout << "Вы забыли ввести данные трубы!\n";
			system("Pause");
			break;
		}
		case 4:
		{
			if (cs_group.size() > 0)
				for (auto iter : cs_group)
				{
					cout << endl;
					cout << iter.second << endl;
				}
			else 
				cout << "Вы забыли ввести данные КС!\n";
			system("Pause");
			break;
		}
		case 5:
		{
			unordered_map <int, Pipe>::iterator number;
			cout << "Введите ID трубы: ";
			if (pipe_group.size() > 0)
			{
				unsigned index = checking(1u, Pipe::GetMaxID(), "Введите ID трубы: ");
				number = pipe_group.find(index);
				number->second.editing_pipe();
			}
			else 
				cout << "Вы забыли ввести данные трубы!\n";
			system("Pause");
			break;
		}
		case 6:
		{
			unordered_map <int, CS>::iterator number;
			cout << "Введите ID КС: ";
			if (cs_group.size() > 0)
			{
				unsigned index = checking(1u, CS::GetMaxID(), "Введите ID КС: ");
				number = cs_group.find(index);
				number->second.editing_cs();
			}
			else 
				cout << "Вы забыли ввести данные КС!\n";
			system("Pause");
			break;
		}
		case 7:
		{
			ofstream fout;
			fout.open(file_name(), ios::out);
			if (fout.is_open())
			{
				if (pipe_group.size() > 0)
				{
					fout << pipe_group.size() << endl;
					for (auto iter:pipe_group)
						fout << iter.second;
				}
				else 
					cout << "Вы забыли ввести данные для труб!\n";

				if (cs_group.size() > 0)
				{
					fout << cs_group.size() << endl;
					for (auto iter : cs_group)
						fout << iter.second;
				}
				else 
					cout << "Вы забыли ввести данные для КС!\n";
				fout.close();

				fout.close();
			}
			else 
				cout << "Файл не открыт" << endl;
			system("Pause");
			break;
		}
		case 8:
		{
			ofstream fout;
			fout.open(file_name(), ios::out);
			if (fout.is_open())
			{
				if (cs_group.size() > 0)
				{
				fout << cs_group.size() << endl;
				for (auto iter:cs_group)
						fout << iter.second;
				}
				else 
					cout << "Вы забыли ввести данные для КС!\n";
				fout.close();
			}
			else 
				cout << "Файл не открыт" << endl;
			system("Pause");
			break;
		}
		case 9:
		{
			ifstream fin;
			fin.open(file_name(), ios::in);
			if (fin.is_open())
			{
				pipe_group.erase(pipe_group.begin(), pipe_group.end());
				int count;
				fin >> count;
				for (int i = 1; i <= count; ++i)
				{
					Pipe pipe;
					fin >> pipe;
					pipe_group.insert(pair<int, Pipe>(pipe.GetId(), pipe));
				}
				fin.close();
			}
			else 
				cout << "Файл не открыт" << endl;
			break;
		}
		case 10:
		{
			ifstream fin;
			fin.open(file_name(), ios::in);
			if (fin.is_open())
			{
				cs_group.erase(cs_group.begin(), cs_group.end());
				int count;
				fin >> count;
				for (int i = 1; i <= count; ++i)
				{
					CS cs;
					fin >> cs;
					cs_group.insert(pair<int, CS>(cs.GetId(), cs));
				}

				fin.close();
			}
			else 
				cout << "Файл не открыт" << endl;
			break;
		}
		case 11:
		{
			bool rep;
			cout << "Фильтр ремонта (1 или 0): ";
			rep = checking(0, 1, "Фильтр ремонта (1 или 0): ");
			if (pipe_group.size() != 0)
			{
				for (int i : Find_PipeOrCS_ByFilter(pipe_group, CheckByRepair, rep))
					cout << pipe_group[i];
			}
			else
				cout << "Не добавлены трубы" << endl;
			system("pause");
			break;
		}
		case 12:
		{
			float perc;
			cout << "Введите процент незадействованных КС для поиска:";
			cin >> perc;
			if (cs_group.size() != 0)
			{

				for (int i : Find_PipeOrCS_ByFilter(cs_group, CheckBy_Notworking_CS, perc))
					cout << cs_group[i];
			}
			else
				cout << "Не добавлены КС" << endl;
			system("pause");
			break;

		}
		case 13:
		{
			string name;
			cout << "Введите название КС для поиска: ";
			cin.ignore(1, '\n');
			getline(cin, name);
			if (cs_group.size() != 0)
			{
				for (int i : Find_PipeOrCS_ByFilter(cs_group, CheckByName, name))
					cout << cs_group[i];
			}
			else
				cout << "Не добавлены КС" << endl;
			system("pause");
			break;

		}
		case 14:
		{
			if (pipe_group.size() > 0)
				delete_pipe(pipe_group); 
			else cout << "Вы забыли ввести трубы!" << endl;
			break;
		}
		case 15:
		{
			if (cs_group.size() > 0)
				delete_cs(cs_group); 
			else cout << "Вы забыли ввести КС!" << endl;
			break;
		}
		case 16:
		{
			unsigned int k;
			k = 0;
			bool rep;
			cout << "Фильтр ремонта (1 или 0): ";
			rep = checking(0, 1, "Фильтр ремонта (1 или 0): ");
			if (pipe_group.size() != 0)
			{
				for (int& i : Find_PipeOrCS_ByFilter(pipe_group, CheckByRepair, rep))
				{
					k = k + 1;
					cout << "Редактирование " << k << "й найденной трубы" << endl;
					pipe_group[i].editing_pipe();
				}
			}
			else
				cout << "Не добалены трубы" << endl;
			system("pause");
			break;
		}
		}
	}
}