#include <iostream>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;

typedef int SElemType;
typedef struct {
	SElemType *	base;
	SElemType *	top;
	int		stacksize;
}SqStack;


void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
void ClearStack(SqStack &S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack S, int &e);
void Push(SqStack &S, int e);
int Pop(SqStack &S, int &e);
int StackTraverse(SqStack S);
void conversion();

int main()
{
	int q, i;
	SqStack S;

	while (1) {
		cout << "**********           ջ               ***************" << endl;
		cout << "**********      1  ��ʼ��ջ           ***************" << endl;
		cout << "**********      2  ����ջ             ***************" << endl;
		cout << "**********      3  ���ջ             ***************" << endl;
		cout << "**********      4  ����Ƿ�Ϊ��       ***************" << endl;
		cout << "**********      5  ջ�ĳ���           ***************" << endl;
		cout << "**********      6  �õ�ջ��Ԫ�ص�ֵ   ***************" << endl;
		cout << "**********      7  ��ջ               ***************" << endl;
		cout << "**********      8  ��ջ               ***************" << endl;
		cout << "**********      9  ����ջ������Ԫ��   ***************" << endl;
		cout << "**********      10 ʮ����ת���˽���   ***************" << endl;
		cout << "**********      11 �˳�               ***************" << endl;
		cin >> i;
		if (i < 1 || i > 11) {
			cout << "���Ϸ����룬������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (i) {
		case 1:
			InitStack(S);
			cout << "��ջ�ɹ�" << endl;
			system("pause");
			break;
		case 2:
			DestroyStack(S);
			cout << "����ջ�ɹ�" << endl;
			system("pause");
			break;
		case 3:
			ClearStack(S);
			cout << "���ջ�ɹ�" << endl;
			system("pause");
			break;
		case 4:
			if (!StackEmpty(S))
				cout << "ջΪ��" << endl;
			else
				cout << "ջ��Ϊ��" << endl;
			system("pause");
			break;
		case 5:
			if (!StackLength(S))
				cout << "ջΪ��" << endl;
			else
				cout << "ջ�ĳ���Ϊ��" << StackLength(S) << endl;
			system("pause");
			break;
		case 6:
			if (!GetTop(S, q))
				cout << "ջΪ��" << endl;
			else
				cout << "ջ��Ԫ�ص�ֵΪ��" << q << endl;
			system("pause");
			break;
		case 7:
			cout << "������Ҫ��ջԪ�ص�ֵ��" << endl;
			cin >> q;
			Push(S, q);
			cout << "��ջ�ɹ�" << endl;
			system("pause");
			break;
		case 8:
			if (!Pop(S, q))
				cout << "ջΪ��" << endl;
			else
				cout << "��ջԪ�ص�ֵΪ��" << q << endl;
			system("pause");
			break;
		case 9:
			if (!StackTraverse(S))
				cout << "ջΪ��" << endl;
			else
				StackTraverse(S);
			system("pause");
			break;
		case 10:
			conversion();
			system("pause");
			break;
		case 11:
			return 0;
		}
		;
		system("cls");
	}
	return 0;
}

void InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.base = NULL;
	S.top = S.base;
	S.stacksize = 0;
}

void ClearStack(SqStack &S)
{
	S.top = S.base;
}

int StackEmpty(SqStack S)
{
	if (S.base == S.top && S.base != NULL)
		return 0;
	return 1;
}

int StackLength(SqStack S)
{
	return S.stacksize;
}

int GetTop(SqStack S, int &e)
{
	if (S.base == S.top) return 0;
	e = *(S.top - 1);
	return 1;
}

void Push(SqStack &S, int e)
{
	if (S.top - S.base > S.stacksize) {
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
		if (!S.base) exit(1);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INIT_SIZE;
	}
	*(S.top) = e;
	S.top++;
}

int Pop(SqStack &S, int &e)
{
	if (S.top == S.base) return 0;
	S.top--;
	e = *(S.top);
	return 1;
}

int StackTraverse(SqStack S)
{
	if (S.top == S.base) return 0;
	while (S.top != S.base) {
		S.top--;
		cout << *(S.top) << "\t";
	}
	return 0;
}

void conversion()
{
	SqStack S;

	InitStack(S);
	int m;
	cout << "������һ��������" << endl;
	cin >> m;
	while (m >= 8) {
		Push(S, m % 8);
		m = m / 8;
	}
	Push(S, m);
	cout << "�õ��İ˽�����Ϊ��";
	while (S.top != S.base) {
		S.top--;
		cout << *(S.top);
	}
	cout << endl;
}
