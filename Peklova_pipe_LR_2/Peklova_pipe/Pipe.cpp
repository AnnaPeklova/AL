#include "Pipe.h"
#include "Template.h"

using namespace std;

unsigned int Pipe::MaxID = 0;

Pipe::Pipe()
{
	id = ++MaxID;
}

int Pipe::GetId()
{
	return id;
}

unsigned int Pipe::GetMaxID()
{
	return MaxID;
}

bool Pipe::GetRepair()
{
	return repair;
}


void Pipe::editing_pipe()
{
	repair = !repair;
	cout << "Successful editing to " << repair << endl;
}

ostream& operator << (ostream& out, const Pipe& pipe)
{
	out << "�������������: " << pipe.id << endl;
	out << "�����: " << pipe.length << endl;
	out << "�������: " << pipe.diam << endl;
	out << "������: " << pipe.repair << endl;
	return out;
}

istream& operator >> (istream& in, Pipe& pipe)
{
	cout << "������� �����: ";
	pipe.length = checking(0, 200, "������� �����: ");
	cout << "������� �������: ";
	pipe.diam = checking(0, 200, "������� �������: ");
	cout << "������: ";
	pipe.repair = checking(0, 1, "������: ");
	return in;
}