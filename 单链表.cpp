#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType	data;
	LNode *		next;
}LNode, *Linklist;
Linklist L;
int main()
{
	void InitList(Linklist & L);
	void DestryList(Linklist & L);
	void ClearList(Linklist & L);
	int ListLength(Linklist L);
	int GetElem(Linklist L, int n);
	int LocateElem(Linklist L, int e);
	int PriorElem(Linklist L, int e);
	int NextElem(Linklist L, int e);
	void ListInsert(Linklist L, int n, int e);
	int ListDelete(Linklist L, int n);
	void ShowList(Linklist L);
	void InputList(Linklist & L);
	void MergeList1(Linklist La, Linklist Lb, Linklist & Lc);
	void MergeList2(Linklist & La, Linklist & Lb);
	Linklist La, Lb, Lc;

	InitList(La);
	InitList(Lb);
	InitList(Lc);
	Linklist p1 = La;

	for (int i = 1; i < 6; i++) {
		p1->next = (Linklist)malloc(sizeof(LNode));
		p1 = p1->next;
		p1->data = i;
		p1->next = NULL;
	}
	p1 = Lb;
	for (int i = 3; i < 8; i++) {
		p1->next = (Linklist)malloc(sizeof(LNode));
		p1 = p1->next;
		p1->data = i;
		p1->next = NULL;
	}

	while (1) {
		cout << "***************************************************" << endl;
		cout << "*              �������                           *" << endl;
		cout << "*              1 ��ʼ������                       *" << endl;
		cout << "*              2 ��������                         *" << endl;
		cout << "*              3 ������Ԫ�ظ���                   *" << endl;
		cout << "*              4 ��ָλ��Ԫ��ֵ                   *" << endl;
		cout << "*              5 �������Ѵ���Ԫ��λ��             *" << endl;
		cout << "*              6 ��ֱ��ǰ��                       *" << endl;
		cout << "*              7 ��ֱ�Ӻ��                       *" << endl;
		cout << "*              8 �ڵ�i��λ�ò���Ԫ��              *" << endl;
		cout << "*              9 ɾ����i��Ԫ��                    *" << endl;
		cout << "*              10 �����������Ԫ��                *" << endl;
		cout << "*              11 ��������Ԫ��                    *" << endl;
		cout << "*              12 �鲢1                           *" << endl;
		cout << "*              13 �鲢2(δ�����¿ռ�)             *" << endl;
		cout << "**************************************************" << endl;
		cout << "��ѡ��һ������" << endl;
		cout << endl;
		int x;
		cin >> x;
		switch (x) {
		case 1: {
			InitList(L);
			cout << "��ʼ���ɹ�" << endl;
			break;
		}
		case 2: {
			DestryList(L);
			cout << "���ٳɹ�" << endl;
			break;
		}
		case 3: {
			cout << "Ԫ�ظ���Ϊ" << ListLength(L) << endl;
			break;
		}
		case 4: {
			cout << "������λ��ֵ��";
			int i;
			cin >> i;
			cout << "��λ��Ԫ��Ϊ��" << GetElem(L, i) << endl;
			break;
		}
		case 5: {
			int e;
			cout << "������Ԫ��ֵ:";
			cin >> e;
			cout << LocateElem(L, e) << endl;
			break;
		}
		case 6: {
			int e;
			cout << "������Ԫ��ֵ:";
			cin >> e;
			cout << PriorElem(L, e) << endl;
			break;
		}
		case 7: {
			int e;
			cout << "������Ԫ��ֵ:";
			cin >> e;
			cout << NextElem(L, e) << endl;
			break;
		}
		case 8: {
			int i, e;
			cout << "������λ��";
			cin >> i;
			cout << "������Ԫ��";
			cin >> e;
			ListInsert(L, i, e);
			break;
		}
		case 9: {
			int i;
			cout << "������λ��";
			cin >> i;
			ListDelete(L, i);
			break;
		}
		case 10: {
			ShowList(L);
			cout << endl;
			break;
		}
		case 11: {
			InputList(L);
			break;
		}
		case 12: {
			ShowList(La);
			cout << endl;
			ShowList(Lb);
			cout << endl;
			MergeList1(La, Lb, Lc);
			ShowList(Lc);
			cout << endl;
			break;
		}
		case 13: {
			ShowList(La);
			cout << endl;
			ShowList(Lb);
			cout << endl;
			MergeList2(La, Lb);
			ShowList(La);
			cout << endl;
		}
		default: {
			return 0;
		}
		}
		system("pause");
		system("cls");
	}
}


void InitList(Linklist &L)
{
	L = (Linklist)malloc(sizeof(LNode));
	if (!L)
		exit(1);
	L->data = 0;
}
void DestryList(Linklist &L)
{
	Linklist p1, p2;

	p1 = p2 = L;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	L = NULL;
}
void ClearList(Linklist &L)
{
	Linklist p1, p2;

	p1 = p2 = L->next;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	L->next = NULL;
}
int ListLength(Linklist L)
{
	int i = 0;
	Linklist p = L->next;

	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
int GetElem(Linklist L, int n)
{
	int i = 0;
	Linklist p = L;

	while (n - i) {
		p = p->next;
		i++;
	}
	return p->data;
}
int LocateElem(Linklist L, int e)
{
	int i = 0;
	Linklist p = L;

	while ((p->data) - e) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		cout << "δ�ҵ�������" << endl;
		return 0;
	}
	return i;
}
int PriorElem(Linklist L, int e)
{
	Linklist p = L, p1 = L;

	while (p) {
		p = p->next;
		if (p->data == e && p1 != L->next)
			return p1->data;
		p1 = p;
	}
	cout << "δ�ҵ�ֱ��ǰ��" << endl;
	return 0;
}
int NextElem(Linklist L, int e)
{
	Linklist p = L->next;

	while (p) {
		if (p->data == e && p->next != NULL)
			return p->next->data;
		p = p->next;
	}
	cout << "δ�ҵ�ֱ�Ӻ��" << endl;
	return 0;
}
void ListInsert(Linklist L, int n, int e)
{
	int i = 0;
	Linklist p = L, p1;

	while (p && n - i - 1) {
		p = p->next;
		i++;
	}
	p1 = p->next;
	p->next = (Linklist)malloc(sizeof(LNode));
	p->next->data = e;
	p->next->next = p1;
}
int ListDelete(Linklist L, int n)
{
	int i = 0;
	Linklist p = L, p1;

	while (p && n - i - 1) {
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	p1 = p->next->next;
	int e = p->next->data;
	free(p->next);
	p->next = p1;
	return e;
}
void ShowList(Linklist L)
{
	Linklist p = L->next;

	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}
}
void InputList(Linklist &L)
{
	int e;
	Linklist p = L;

	while (cin >> e) {
		if (e == 0)
			return;
		p->next = (Linklist)malloc(sizeof(LNode));
		p = p->next;
		p->data = e;
		p->next = NULL;
	}
}
void MergeList1(Linklist La, Linklist Lb, Linklist &Lc)
{
	Linklist p = Lc;
	Linklist pa = La->next, pb = Lb->next;

	while (pa && pb) {
		if (pa->data >= pb->data) {
			p->next = (Linklist)malloc(sizeof(LNode));
			p = p->next;
			p->data = pb->data;
			p->next = NULL;
			pb = pb->next;
		} else {
			p->next = (Linklist)malloc(sizeof(LNode));
			p = p->next;
			p->data = pa->data;
			p->next = NULL;
			pa = pa->next;
		}
	}
	if (pa)
		p->next = pa;
	else
		p->next = pb;
}
void MergeList2(Linklist &La, Linklist &Lb)
{
	Linklist p1 = (La->next->data < Lb->next->data ? La->next : Lb->next);
	Linklist p2 = (La->next->data >= Lb->next->data ? La->next : Lb->next);

	while (p1->next && p2) {
		if (p2->data <= p1->next->data) {
			Linklist p3 = p1->next;
			p1->next = p2;
			p2 = p2->next;
			p1 = p1->next;
			p1->next = p3;
		} else {
			p1 = p1->next;
		}
	}
	if (p2)
		p1->next = p2;
}
