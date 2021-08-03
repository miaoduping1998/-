//	1、写一个菜单显示函数showMenu()
//	2、让main()调用showMenu()
#include<iostream>
#include<string>
#define MAX 1000

using namespace std;

//	通讯录中个人信息结构体
typedef struct Person
{
	string name;//	姓名
	int sex;	//	1--男，2--女
	int age;	//	年龄
	string Tel; //	电话号码
	string addr; // 家庭住址
}Person, *pPerson;

//通讯录结构体
typedef struct addrBook
{
	Person personArray[MAX];
	int size;
}addrBook, *paddrBook;

//	菜单显示函数
void showMenu() 
{
	cout << "****************************\n";
	cout << "*       1、添加联系人      *\n";
	cout << "*       2、显示联系人      *\n";
	cout << "*       3、查找联系人      *\n";
	cout << "*       4、删除联系人      *\n";
	cout << "*       5、修改联系人      *\n";
	cout << "*       6、清空联系人      *\n";
	cout << "*       0、退出通讯录系统  *\n";
	cout << "****************************\n";
}

//1、添加联系人
void addPerson(paddrBook abs) 
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满，不能再添加联系人了，请删除一些不常联系的人吧。\n";
		system("pause");
		return;
	}
	//姓名
	string name;
	cout << "请输入联系人的姓名：";
	cin >> name;
	abs->personArray[abs->size].name = name;
	//	1--男，2--女
	int sex = 0;
	cout << "请输入联系人的性别(1--男，2--女)：";
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
			cout << "性别输入错误，请重新输入:";
		}
	}
	//	年龄
	int age = 0;
	cout << "请输入联系人的年龄：";
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
			cout << "年龄输入错误，请重新输入:";
		}
	}
	//	电话号码
	string phone;
	cout << "请输入联系人电话号码：";
	cin >> phone;
	abs->personArray[abs->size].Tel = phone;
	// 家庭住址
	string addr1;
	cout << "请输入联系人家庭住址：";
	cin >> addr1;
	abs->personArray[abs->size].addr = addr1;
	// 通讯录人员加一
	abs->size += 1;
	//cout << "abs->size = " << abs->size << endl;
	cout << "联系人添加成功！\n";
	system("pause");
	system("cls");
}

//2、显示联系人
void showPerson(paddrBook abs) 
{
	//判断通讯录是否为空
	if (abs->size == 0)
	{
		cout << "通讯录为空。\n";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		//显示通讯录联系人的信息
		for (int i = 0; i < abs->size; i++)
		{
			
			cout << "姓名：" << abs->personArray[i].name << "\t";
			/*if (abs->personArray[i].sex == 1)
			{
				cout << "性别：男" << "\t";
			}
			else
			{
				cout << "性别：女" << "\t";
			}*/
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话号码：" << abs->personArray[i].Tel << "\t";
			cout << "家庭住址：" << abs->personArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//按姓名查询函数
int isExit(paddrBook abs, string name)
{
	int i = 0;
	//cout << "abs->size = " << abs->size << endl;
	//判断通讯录是否为空 空返回0
	if (abs->size == 0)
	{
		cout << "通讯录为空！\n";
		/*system("pause");
		system("cls");*/
		return 0;
	}
	//遍历整个文件 查到返回所在位置i，没查到返回-1
	for (i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i+1;
		}
	}
	return -1;
}

//3、按姓名删除函数
void deletePerson(paddrBook abs)
{
	int ret = 0;
	string name;

	//需要输入你要删除的联系人姓名
	cout << "请输入你要删除的联系人姓名：";
	cin >> name;

	//按名字找到此联系人
	ret = isExit(abs, name);
	//进行删除操作
	if (ret == 0 )
	{
		
	}
	else if (ret == -1)
	{
		cout << "查无此人。\n";
	}
	else
	{
		for (int i = ret - 1; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "删除成功！\n";
	}
	system("pause");
	system("cls");
}

//4、按姓名查找联系人
void findPerson(paddrBook abs, string name)
{
	int ret = 0;
	//输入要查找的联系人姓名
	/*string name;
	cout << "请输入要查找的联系人姓名：";
	cin >> name;*/
	//判断联系人是否存在
	ret = isExit(abs, name);
	//cout << "ret = " << ret << endl;
	if (ret != -1 && ret != 0)
	{
		ret--;
		cout << "联系人" << name << "的信息为：\n";
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话号码：" << abs->personArray[ret].Tel << "\t";
		cout << "家庭住址：" << abs->personArray[ret].addr << endl;
	}
	else
	{
		cout << "联系人" << name << "不存在。\n";
	}
	system("pause");
	system("cls");
}

//5、修改联系人
void modifyPerson(paddrBook abs, string name)
{
	int ret = 0;
	ret = isExit(abs, name);
	if (ret != -1 && ret != 0)
	{
		ret--;
		cout << "联系人" << name << "原来的信息为：\n";
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话号码：" << abs->personArray[ret].Tel << "\t";
		cout << "家庭住址：" << abs->personArray[ret].addr << endl;

		//姓名
		//string name;
		cout << "请输入联系人的姓名：";
		cin >> name;
		abs->personArray[ret].name = name;
		//	1--男，2--女
		int sex = 0;
		cout << "请输入联系人的性别(1--男，2--女)：";
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
				cout << "性别输入错误，请重新输入:";
			}
		}
		//	年龄
		int age = 0;
		cout << "请输入联系人的年龄：";
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
				cout << "年龄输入错误，请重新输入:";
			}
		}
		//	电话号码
		string phone;
		cout << "请输入联系人电话号码：";
		cin >> phone;
		abs->personArray[ret].Tel = phone;
		// 家庭住址
		string addr1;
		cout << "请输入联系人家庭住址：";
		cin >> addr1;
		abs->personArray[ret].addr = addr1;
	}
	else
	{
		cout << "查无此人。\n";
	}
	system("pause");
	system("cls");
}

//6、清空联系人
void cleanPerson(paddrBook abs)
{
	abs->size = 0;
	cout << "通讯录已经清空！\n";
	system("pause");
	system("cls");
}

//	主函数
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
		cout << "请输入指令（1~6或0）：";
		cin >> cmd;
		switch (cmd)
		{
		case 1:	
			addPerson(&abs); //1、添加联系人
			break;
		case 2:
			showPerson(&abs);//	2、显示联系人
			break;
		case 3:	
			cout << "请输入要查找的联系人姓名：";
			cin >> name;
			findPerson(&abs, name);
			////string name;	//	3、查找联系人
			////int ret = 0;
			//cout << "请输入你要查找的联系人姓名：";
			//cin >> name;
			//ret = isExit(&abs, name);
			//if (ret == 0)
			//{
			//	//cout << "通讯录为空。\n";
			//}
			//else if (ret == -1)
			//{
			//	cout << name << "不存在。\n";
			//}
			//else
			//{
			//	cout << name << "在通讯录中的第" << ret + 1 << "个位置。\n";
			//}
			break;
		case 4:	
			deletePerson(&abs);//	4、删除联系人
			break;
		case 5:	//	5、修改联系人
			cout << "请输入要修改的联系人姓名：";
			cin >> name;
			modifyPerson(&abs, name);
			break;
		case 6:	//	6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:	//	0、退出通讯录系统
			cout << "系统退出。\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "命令错误，请重新输入。\n";
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}