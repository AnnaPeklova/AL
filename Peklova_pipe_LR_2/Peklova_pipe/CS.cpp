#include "CS.h"
#include "Template.h"
#include <string>

using namespace std;

unsigned int CS::MaxID = 0;

ostream& operator << (ostream& out, const CS& cs)
{
	out << "Идентификатор: " << cs.id << endl;
	out << "Название: " << cs.name << endl;
	out << "Количество цехов: " << cs.amount << endl;
	out << "Количество цехов в работе: " << cs.amount_work << endl;
	out << "Эффективность: " << cs.perfomance << endl;
	return out;
}


istream& operator >> (istream& in, CS& cs)
{
	cout << "Введите название: ";
	cin.ignore(1, '\n');
	getline(cin, cs.name);
	cout << "Введите количество цехов: ";
	cs.amount = checking(0, 1000, "Введите количество цехов: ");
	cout << "Введите количество цехов в работе: ";
	cs.amount_work = checking(0, cs.amount, "Введите количество цехов в работе: ");
	cout << "Введите эффективность: ";
	cs.perfomance = checking(0, 1, "Введите эффективность: ");
	return in;
}