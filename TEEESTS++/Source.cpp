#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include "My_date.h"

class food;

bool str_comp(string, string);
void menu();
void search(vector<food>, int);
void type(vector<food>, int);
void sort(vector<food>&, int);

class food
{
private:
	string fam;//�������� �������
	int   type;//��� ������� (1- �������, 2-�������, 3-��������)
	double weight;// ���
	date end_life;
	bool shelf_life;

	friend void type(vector<food>, int);
	friend void sort(vector<food>&, int);
	friend ostream& operator <<(ostream& os, food& right);
	friend bool operator !(food& f);

public:

	int quant;// ����������
	double cost;//���������

	food()//����������� �� ���������
	{
		fam = "none";
		type = 0;
		weight = 0;
		quant = 0;
		cost = 0;
		shelf_life = true;
	}

	food(string fam, int type, double weight, int quant, double cost, date end_life)
	{
		this->fam = fam;
		this->type = type;
		this->weight = weight;
		this->quant = quant;
		this->cost = cost;
		this->end_life = end_life;
		shelf_life = true;
	}

	void set()
	{
		cout << "������� �������� �������" << endl;
		cin.ignore(32767, '\n');//������ ������
		getline(cin, fam);

		cout << "������� ��� ������� (1- �������, 2-�������, 3-��������)" << endl;
		checkenter(type);
		while (type > 3 || type < 1)
		{
			cout << "������������ ���, ��������� �������" << endl;
			checkenter(type);
		}

		cout << "������� ��� ������� (� �������)" << endl;
		checkenter(weight);

		cout << "������� ���������� �������" << endl;
		checkenter(quant);

		cout << "������� ���� �������" << endl;
		checkenter(cost);

		cout << "������� ���� ��������� ����� ��������" << endl;
		end_life.set();
	}

	void lock_fam()
	{
		for (int i = 0; i < fam.length(); i++)
		{
			if (fam[i] == ' ')
			{
				fam[i] = '_';
			}
		}
	}

	void unlock_fam()
	{
		for (int i = 0; i < fam.length(); i++)
		{
			if (fam[i] == '_')
			{
				fam[i] = ' ';
			}
		}
	}

	string str()
	{
		return fam + " " + to_string(type) + " " + to_string(weight) + " " + to_string(quant) + " " + to_string(cost) + " " + to_string(end_life.get_day()) + " "
			+ to_string(end_life.get_month()) + " " + to_string(end_life.get_year());
	}

	bool operator >(date d1)
	{
		return end_life > d1;
	}

	bool operator <(date d1)
	{
		return end_life < d1;
	}

	bool search(string srch)
	{
		if (str_comp(fam, srch))
			return true;
		else
			return false;
	}

	food operator =(food right)
	{
		this->fam = right.fam;
		this->type = right.type;
		this->weight = right.weight;
		this->quant = right.quant;
		this->cost = right.cost;
		this->end_life = right.end_life;
		this->shelf_life = right.shelf_life;

		return *this;
	}
};

ostream& operator <<(ostream& os, food& right)
{
	os << right.fam << "\t\t" << right.type << "\t\t\t\t\t" << right.weight << "\t\t" << right.quant << "\t\t" << right.cost;
	return os;
}

bool operator !(food& f)
{
	return f.shelf_life = false;
}


int main()
{
	system("chcp 1251>nul");
	vector <food> dynamic;
	int menu_search = 0, quantity = 0;
	date day;
	ofstream wdatabase;
	ifstream rdatabase("database.txt");

	food buff;//������ ��� ������ �� �����
	string buff_fam;
	int buff_type;
	double buff_weight;
	int buff_quant;
	double buff_cost;
	date buff_date;

	//======�������� �������� ����� � ������===================
	if (rdatabase.is_open())
	{
		cout << "���� ������" << endl;
		for (int i = 0; !rdatabase.eof(); i++)
		{
			rdatabase >> buff_fam >> buff_type >> buff_weight >> buff_quant >> buff_cost >> buff_date;
			food buff(buff_fam, buff_type, buff_weight, buff_quant, buff_cost, buff_date);
			buff.unlock_fam();
			dynamic.push_back(buff);
			quantity++;
		}
		rdatabase.close();
	}
	else
	{
		cout << "���� �� ������. ������������ �����..." << endl;
		wdatabase.open("database.txt", ios_base::out);
		wdatabase.close();
	}

	//================�������� ���������================
	do
	{
		menu();
		checkenter(menu_search);

		switch (menu_search)
		{
		case 1:
			buff.set();
			dynamic.push_back(buff);
			quantity++;
			sort(dynamic, quantity);
			system("cls");
			break;
		case 2:
			cout << "��������\t��� �������\t\t\t\t��� �������\t����������\t����" << endl;
			cout << "�������\t\t(1- �������, 2-�������, 3-��������)\t(�����)\t\t�������\t\t�������" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < quantity; i++)
			{
				cout << dynamic[i] << endl;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			search(dynamic, quantity);
			system("pause");
			system("cls");
			break;
		case 4:
			type(dynamic, quantity);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "������� ����, ������������ ������� ����� ����������� ��������." << endl;
			day.set();

			cout << "��������\t��� �������\t\t\t\t��� �������\t����������\t����\t\t���� �������� " << endl;
			cout << "�������\t\t(1- �������, 2-�������, 3-��������)\t(�����)\t\t�������\t\t�������\t\t�����?" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < quantity; i++)
			{
				if (dynamic[i] < day)
				{
					!dynamic[i];
				}
				cout << dynamic[i] << "\t\t";
				if (dynamic[i] < day)
				{
					cout << "��" << endl;
				}
				else
				{
					cout << "���" << endl;
				}
			}
			cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			break;
		default:
			cout << "������ ������ ���� �� ����������. �� ������ ���������� �� ��������� �����." << endl;
			break;
		}

	} while (menu_search != 6);


	wdatabase.open("database.txt");
	for (int i = 0; i < quantity; i++)
	{
		dynamic[i].lock_fam();
		wdatabase << dynamic[i].str();
	}
	wdatabase.close();

	dynamic.clear();
	return 0;
}

bool str_comp(string s1, string s2)//�������� ���� ����� �� ������� ����� ��� ����� ��������
{
	int counter = 0;

	for (int i = 0; s1[i] != '\n' && s1[i] != '\0' && s2[i] != '\n' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i] && (s1[i] - 32) != s2[i] && (s1[i] + 32) != s2[i])
		{
			counter++;
		}
	}

	if (counter != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void menu()//������� ���� ����������� ����������
{
	cout << "==================================" << endl;
	cout << "�������� ����� �������   �� 1" << endl;
	cout << "����������� ���� ������� �� 2" << endl;
	cout << "����� ������ �� �������� �� 3" << endl;
	cout << "������ �� ����       ����   4" << endl;
	cout << "�������� �� ���� ��������.� 5" << endl;
	cout << "����� �� ���������     ���� 6" << endl;
	cout << "��������������.." << endl;
	cout << "������� ����� �������" << endl;
}

void search(vector<food> database, int quantity)//����� ������� �� ��������
{
	string search;

	cout << "==================================" << endl;
	cout << "������� �������� �������" << endl;
	cin.ignore(32767, '\n');//������ ������
	getline(cin, search);

	cout << "��������\t��� �������\t\t\t\t��� �������\t����������\t����" << endl;
	cout << "�������\t\t(1- �������, 2-�������, 3-��������)\t(�����)\t\t�������\t\t�������" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < quantity; i++)
	{
		if (database[i].search(search))
		{
			cout << database[i] << endl;
		}
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void type(vector<food> database, int quantity)
{
	int search;

	cout << "������� ��� ������� (1- �������, 2-�������, 3-��������)" << endl;
	checkenter(search);
	while (search > 3 || search < 1)
	{
		cout << "������������ ���, ��������� �������" << endl;
		checkenter(search);
	}
	cout << "��������\t��� �������\t\t\t\t��� �������\t����������\t����" << endl;
	cout << "�������\t\t(1- �������, 2-�������, 3-��������)\t(�����)\t\t�������\t\t�������" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < quantity; i++)
	{
		if (search == database[i].type)
		{
			cout << database[i] << endl;
		}
	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void sort(vector<food>& database, int quantity)
{
	food buff;
	int switches;
	do
	{
		switches = 0;
		for (int i = 0; i < quantity - 1; i++)
		{
			if (database[i].cost < database[i + 1].cost)
			{
				switches++;
				buff = database[i];
				database[i] = database[i + 1];
				database[i + 1] = buff;
			}
		}

	} while (switches != 0);
}