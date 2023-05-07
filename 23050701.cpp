#include<iostream>
#include <iomanip>
#include "string"
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef struct
{
	char no[20];
	char name[50];
	char author[20];
 
}Book;
typedef struct
{
	Book* elem;
	int length;
 
}SqList;
 
 
 
 
void Printf(SqList& L);
 
 
int InitList(SqList& L)
{
	L.elem = new Book[MAXSIZE];
	if (!L.elem)  exit(OVERFLOW);
	L.length = 0;
	return OK;
}
int GetElem(SqList L, int i, Book& e)      
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}
void LocateElem(SqList L)   
{
	Book e;
	int i;
	char n = 0;
	while (1)
	{
		cout << "����1����Ų��ң�����2���������ң�����3�����������ң�����4����Ų���,����#������һ����" << endl;
		cin >> n;
		if (n == '#')
			break;
		if (n == '1')
		{
			cout << "������Ҫ���ҵ���ţ�";
			cin >> e.no;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].no, e.no) == 0)
				{
					cout << L.elem[i].no << "    " << L.elem[i].name << "   " << L.elem[i].author << endl;
					break;
				}
 
			}
			if (i >= L.length)
				cout << "���޴��飡��鿴�����Ƿ���ȷ" << endl;
 
 
		}
		if (n == '2')
		{
			cout << "������Ҫ���ҵ�������";
			cin >> e.name;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].name, e.name) == 0)
				{
					cout << L.elem[i].no << "    " << L.elem[i].name << "   " << L.elem[i].author << endl;
					break;
				}
 
 
			}
			if (i >= L.length)
				cout << "���޴��飡��鿴�����Ƿ���ȷ" << endl;
		}
		if (n == '3')
		{
			cout << "������Ҫ���ҵ����ߣ�";
			cin >> e.author;
			for (i = 0; i < L.length; i++)
			{
				if (strcmp(L.elem[i].author, e.author) == 0)
				{
					cout << L.elem[i].no << "    " << L.elem[i].name << "   " << L.elem[i].author << endl;
					break;
				}
 
 
			}
			if (i >= L.length)
				cout << "���޴��飡��鿴�����Ƿ���ȷ" << endl;
		}
		if (n == '4')
		{
			cout << "������Ҫ���ҵ���ţ�";
			cin >> i;
			if (i <= L.length)
			{
				cout << L.elem[i - 1].no << "    " << L.elem[i - 1].name << "   " << L.elem[i - 1].author << endl;
 
 
			}
			if (i > L.length)
				cout << "���޴��飡��鿴�����Ƿ���ȷ" << endl;
		}
 
 
 
	}
 
}
int ListInsert(SqList& L, int i)       
{
	int j = 0;
	if ((i < 1) || (i > L.length + 1)) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
 
	cout << "��������š�����������" << endl;
	cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].author;
	++L.length;
	Printf(L);
 
	return OK;
}
 
 
void ListDelete(SqList& L)              
{
	int i;
	int j;
	char s = 0;
	cout << "����Ҫɾ���鱾����ţ�" << endl;
	cin >> i;
	if ((i < 1) || (i > L.length)) cout << "�������Ų���ȷ" << endl;
	else
	{
		cout << "�Ƿ�ɾ������  ����1ȷ��������0�񶨣�";
		cin >> s;
		if (s == '1')
		{
			for (j = i; j <= L.length - 1; j++)
				L.elem[j - 1] = L.elem[j];
			--L.length;
			Printf(L);
		}
	}
 
 
 
 
}
 
 
void Update(SqList& L)
{
	Book e;
	int i;
	char  n;
	while (1)
	{
		cout << "������Ҫ�޸ĵ������� ,����0������һ��:";
		cin >> i;
		if (i == 0) break;
		else if ((i < 1) || (i > L.length)) cout << "�������Ų���ȷ" << endl;
		else
		{
			cout << L.elem[i - 1].no << "    " << L.elem[i - 1].name << "   " << L.elem[i - 1].author << endl;
			cout << "��ѡ��Ҫ�޸ĵĶ���1����ţ�2��������3������ ,����#������һ��" << endl;
			cin >> n;
			if (n == '#')
				break;
			switch (n)
			{
			case '1':cout << "�����޸�Ϊ��";
				cin >> L.elem[i - 1].no;
				cout << L.elem[i - 1].no << "    " << L.elem[i - 1].name << "   " << L.elem[i - 1].author << endl; break;
			case '2':cout << "�����޸�Ϊ��";
				cin >> L.elem[i - 1].name;
				cout << L.elem[i - 1].no << "    " << L.elem[i - 1].name << "   " << L.elem[i - 1].author << endl; break;
			case '3':cout << "�����޸�Ϊ��";
				cin >> L.elem[i - 1].author;
				cout << L.elem[i - 1].no << "    " << L.elem[i - 1].name << "   " << L.elem[i - 1].author << endl; break;
			default:break;
			}
 
 
 
 
		}
	}
 
}
 
 
void Create(SqList& L, int n)           
{
	int i;
 
	for (i = 0; i < n; i++)
	{
		cout << "��ֱ������" << i + 1 << "�������š�����������" << endl;
		cin >> L.elem[i].no >> L.elem[i].name >> L.elem[i].author;
		L.length++;
	}
}
void Printf(SqList& L)
{
	int i;
	cout << "/---------------------  ��������ͼ��  ----------------------------------/" << endl;
	cout << "       " << setw(10) << left << "���" << setw(10) << left << "���" << setw(30) << left << "����" << setw(10) << left << "����" << endl << endl;
	for (i = 0; i < L.length; i++)
	{
		cout << "        " << setw(10) << left << i + 1 << setw(10) << left << L.elem[i].no << setw(30) << left << L.elem[i].name << setw(10) << left << L.elem[i].author << endl;
	}
	cout << "/-----------------------------------------------------------------------/" << endl;
}
int main()
{
	SqList L;
	Book B;
	char n[20];
	int m = 0;
	char s = 0;
	InitList(L);
	cout << "/------------------------��ӭ����ͼ�����ϵͳ---------------------------/" << endl;
	cout << "����ͼ����Ϣ" << endl;
	cout << "�������鱾��Ŀ��";
	cin >> m;
	Create(L, m);
	Printf(L);
	while (1)
	{
		cout << "��ѡ��Ҫ���еĲ��� �� 1������     2�� ����     3�� ɾ��     4���޸�    0: ��ʾ��   ��" << endl;
		cin >> s;
		switch (s)
		{
		case '0':  Printf(L); break;
		case '1':  LocateElem(L); break;
		case '2':  ListInsert(L, L.length); break;
		case '3':  ListDelete(L); break;
		case '4':  Update(L); break;
		}
	}
 
	system("pause");
	return 0;
}