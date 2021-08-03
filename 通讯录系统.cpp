//	1��дһ���˵���ʾ����showMenu()
//	2����main()����showMenu()
#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

//	ͨѶ¼�и�����Ϣ�ṹ��
typedef struct Person
{
	string name;//	����
	int sex;	//	1--�У�2--Ů
	int age;	//	����
	string Tel; //	�绰����
	string addr; // ��ͥסַ
}Person, *pPerson;

//ͨѶ¼�ṹ��
typedef struct addrBook
{
	Person personArray[MAX];
	int size;
}addrBook, *paddrBook;

//	�˵���ʾ����
void showMenu() 
{
	cout << "****************************\n";
	cout << "*       1�������ϵ��      *\n";
	cout << "*       2����ʾ��ϵ��      *\n";
	cout << "*       3��������ϵ��      *\n";
	cout << "*       4��ɾ����ϵ��      *\n";
	cout << "*       5���޸���ϵ��      *\n";
	cout << "*       6�������ϵ��      *\n";
	cout << "*       0���˳�ͨѶ¼ϵͳ  *\n";
	cout << "****************************\n";
}

//1�������ϵ��
void addPerson(paddrBook abs) 
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�����������������ϵ���ˣ���ɾ��һЩ������ϵ���˰ɡ�\n";
		system("pause");
		return;
	}
	//����
	string name;
	cout << "��������ϵ�˵�������";
	cin >> name;
	abs->personArray[abs->size].name = name;
	//	1--�У�2--Ů
	int sex = 0;
	cout << "��������ϵ�˵��Ա�(1--�У�2--Ů)��";
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].sex = sex;
			break;
		}
		else
		{
			cout << "�Ա������������������:";
		}
	}
	//	����
	int age = 0;
	cout << "��������ϵ�˵����䣺";
	while (true)
	{
		cin >> age;
		if (age >= 0)
		{
			abs->personArray[abs->size].age = age;
			break;
		}
		else
		{
			cout << "���������������������:";
		}
	}
	//	�绰����
	string phone;
	cout << "��������ϵ�˵绰���룺";
	cin >> phone;
	abs->personArray[abs->size].Tel = phone;
	// ��ͥסַ
	string addr1;
	cout << "��������ϵ�˼�ͥסַ��";
	cin >> addr1;
	abs->personArray[abs->size].addr = addr1;
	// ͨѶ¼��Ա��һ
	abs->size += 1;
	//cout << "abs->size = " << abs->size << endl;
	cout << "��ϵ����ӳɹ���\n";
	system("pause");
	system("cls");
}

//2����ʾ��ϵ��
void showPerson(paddrBook abs) 
{
	//�ж�ͨѶ¼�Ƿ�Ϊ��
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ�ա�\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		//��ʾͨѶ¼��ϵ�˵���Ϣ
		for (int i = 0; i < abs->size; i++)
		{
			
			cout << "������" << abs->personArray[i].name << "\t";
			/*if (abs->personArray[i].sex == 1)
			{
				cout << "�Ա���" << "\t";
			}
			else
			{
				cout << "�Ա�Ů" << "\t";
			}*/
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�绰���룺" << abs->personArray[i].Tel << "\t";
			cout << "��ͥסַ��" << abs->personArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//��������ѯ����
int isExit(paddrBook abs, string name)
{
	int i = 0;
	//cout << "abs->size = " << abs->size << endl;
	//�ж�ͨѶ¼�Ƿ�Ϊ�� �շ���0
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�\n";
		/*system("pause");
		system("cls");*/
		return 0;
	}
	//���������ļ� �鵽��������λ��i��û�鵽����-1
	for (i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i+1;
		}
	}
	return -1;
}

//3��������ɾ������
void deletePerson(paddrBook abs)
{
	int ret = 0;
	string name;

	//��Ҫ������Ҫɾ������ϵ������
	cout << "��������Ҫɾ������ϵ��������";
	cin >> name;

	//�������ҵ�����ϵ��
	ret = isExit(abs, name);
	//����ɾ������
	if (ret == 0 )
	{
		
	}
	else if (ret == -1)
	{
		cout << "���޴��ˡ�\n";
	}
	else
	{
		for (int i = ret - 1; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ���\n";
	}
	system("pause");
	system("cls");
}

//4��������������ϵ��
void findPerson(paddrBook abs, string name)
{
	int ret = 0;
	//����Ҫ���ҵ���ϵ������
	/*string name;
	cout << "������Ҫ���ҵ���ϵ��������";
	cin >> name;*/
	//�ж���ϵ���Ƿ����
	ret = isExit(abs, name);
	//cout << "ret = " << ret << endl;
	if (ret != -1 && ret != 0)
	{
		ret--;
		cout << "��ϵ��" << name << "����ϢΪ��\n";
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�绰���룺" << abs->personArray[ret].Tel << "\t";
		cout << "��ͥסַ��" << abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "��ϵ��" << name << "�����ڡ�\n";
	}
	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyPerson(paddrBook abs, string name)
{
	int ret = 0;
	ret = isExit(abs, name);
	if (ret != -1 && ret != 0)
	{
		ret--;
		cout << "��ϵ��" << name << "ԭ������ϢΪ��\n";
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�绰���룺" << abs->personArray[ret].Tel << "\t";
		cout << "��ͥסַ��" << abs->personArray[ret].addr << endl;

		//����
		//string name;
		cout << "��������ϵ�˵�������";
		cin >> name;
		abs->personArray[ret].name = name;
		//	1--�У�2--Ů
		int sex = 0;
		cout << "��������ϵ�˵��Ա�(1--�У�2--Ů)��";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			else
			{
				cout << "�Ա������������������:";
			}
		}
		//	����
		int age = 0;
		cout << "��������ϵ�˵����䣺";
		while (true)
		{
			cin >> age;
			if (age >= 0)
			{
				abs->personArray[ret].age = age;
				break;
			}
			else
			{
				cout << "���������������������:";
			}
		}
		//	�绰����
		string phone;
		cout << "��������ϵ�˵绰���룺";
		cin >> phone;
		abs->personArray[ret].Tel = phone;
		// ��ͥסַ
		string addr1;
		cout << "��������ϵ�˼�ͥסַ��";
		cin >> addr1;
		abs->personArray[ret].addr = addr1;
	}
	else
	{
		cout << "���޴��ˡ�\n";
	}
	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(paddrBook abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�Ѿ���գ�\n";
	system("pause");
	system("cls");
}

//	������
int main() 
{
	int cmd = 0;
	addrBook abs;
	abs.size = 0;
	string name;
	//int ret = 0;

	while (true)
	{
		showMenu();
		cout << "������ָ�1~6��0����";
		cin >> cmd;
		switch (cmd)
		{
		case 1:	
			addPerson(&abs); //1�������ϵ��
			break;
		case 2:
			showPerson(&abs);//	2����ʾ��ϵ��
			break;
		case 3:	
			cout << "������Ҫ���ҵ���ϵ��������";
			cin >> name;
			findPerson(&abs, name);
			////string name;	//	3��������ϵ��
			////int ret = 0;
			//cout << "��������Ҫ���ҵ���ϵ��������";
			//cin >> name;
			//ret = isExit(&abs, name);
			//if (ret == 0)
			//{
			//	//cout << "ͨѶ¼Ϊ�ա�\n";
			//}
			//else if (ret == -1)
			//{
			//	cout << name << "�����ڡ�\n";
			//}
			//else
			//{
			//	cout << name << "��ͨѶ¼�еĵ�" << ret + 1 << "��λ�á�\n";
			//}
			break;
		case 4:	
			deletePerson(&abs);//	4��ɾ����ϵ��
			break;
		case 5:	//	5���޸���ϵ��
			cout << "������Ҫ�޸ĵ���ϵ��������";
			cin >> name;
			modifyPerson(&abs, name);
			break;
		case 6:	//	6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:	//	0���˳�ͨѶ¼ϵͳ
			cout << "ϵͳ�˳���\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "����������������롣\n";
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}