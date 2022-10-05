#include "CS.h"
#include "Template.h"
#include <string>

using namespace std;

unsigned int CS::MaxID = 0;

ostream& operator << (ostream& out, const CS& cs)
{
	out << "�������������: " << cs.id << endl;
	out << "��������: " << cs.name << endl;
	out << "���������� �����: " << cs.amount << endl;
	out << "���������� ����� � ������: " << cs.amount_work << endl;
	out << "�������������: " << cs.perfomance << endl;
	return out;
}


istream& operator >> (istream& in, CS& cs)
{
	cout << "������� ��������: ";
	cin.ignore(1, '\n');
	getline(cin, cs.name);
	cout << "������� ���������� �����: ";
	cs.amount = checking(0, 1000, "������� ���������� �����: ");
	cout << "������� ���������� ����� � ������: ";
	cs.amount_work = checking(0, cs.amount, "������� ���������� ����� � ������: ");
	cout << "������� �������������: ";
	cs.perfomance = checking(0, 1, "������� �������������: ");
	return in;
}