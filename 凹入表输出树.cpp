#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct Tree {
	char	data = 0;
	Tree *	child = NULL;
	Tree *	brother = NULL;
} *BTree;       //��������ṹ��
BTree T;        //������ڵ㣻
char c[50];     //��Ž���ַ�����
BTree a[50];    //��Ž���ַ��
int b[50];      //���ÿ���ڵ�Ķ�
int main()
{
	void NewTree(BTree & T);//��������
	void Show(BTree T, int n);

	cout << "�밴����������Ԫ�أ�";
	cin >> c;
	cout << "������ÿ�����Ķȣ�";
	for (int i = 0; i < (int)strlen(c); i++)
		cin >> b[i];
	NewTree(T);
	Show(T, 0);

	return 0;
}
void NewTree(BTree &T)//������
{
	for (int i = 0; c[i]; i++) {
		BTree p = (BTree)malloc(sizeof(Tree));
		p->child = NULL;
		p->brother = NULL;
		p->data = c[i];
		a[i] = p;
	}//���ɽ�㣻
	for (int i = 0, k = 0; i < (int)strlen(c) - 1; k++)
		if (b[k]) {
			a[k]->child = a[++i];//��һ��Ϊ���ӣ���ַ�����child�У�
			b[k]--;
			while (b[k]) {
				a[i]->brother = a[i + 1];       //������Ϊ�ֵܽڵ㣬�����brother��
				i++;
				b[k]--;                         //ÿ���һ������ֵ��һ��ֱ�����꣬��ֵΪ0λ��
			}
		}
	T = a[0];               //�Ѹ��ڵ��ַ����T
}
void Show(BTree T, int n)       //���������ʽ�����
{
	if (T) {
		for (int k = 0; k < n; k++)
			cout << " ";            //���������׼���ڵڼ�����������ո�
		cout << T->data << endl;        //���dataֵ
		Show(T->child, n + 1);          //�ݹ���ã����Һ��ӵ�ֵ����Ϊ��ȼ�һ������Ϊn+1
		Show(T->brother, n);            //�����������ֵܣ���Ϊ��ͬ�㣬����Ϊn��
	}
}
