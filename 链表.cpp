#include <iostream>
#include <stdlib.h>
using namespace std;

int showmenu(){
	int index=0;
	system("cls"); 
	cout<<"********************************************************"<<endl;
	cout<<"**************           �˵�ѡ��           ************"<<endl; 
	cout << "*********************************************************" << endl;
	cout << "***************  1.��ʼ������������      ****************" << endl;
	cout << "***************  2.��������              ****************" << endl;
	cout << "***************  3.����������Ԫ�ظ���    ****************" << endl;
	cout << "***************  4.��ָλ���Ԫ��ֵ      ****************" << endl;
	cout << "***************  5.�����Ѵ���Ԫ�ص�λ��  ****************" << endl;
	cout << "***************  6.������Ԫ��,��ֱ��ǰ�� ****************" << endl;
	cout << "***************  7.������Ԫ��,��ֱ�Ӻ�� ****************" << endl;
	cout << "***************  8.�ڵ�i��λ�ò���Ԫ��   ****************" << endl;
	cout << "***************  9.ɾ����i��Ԫ��         ****************" << endl;
	cout << "***************  10.��������������Ԫ�� ****************" << endl;
	cout << "***************  11.��ʼ������������Ԫ�� ****************" << endl;
	cout << "***************  12.�˳�                 ****************" << endl;
	cout << "*********************************************************" << endl;
	cout<<"������"<<endl;
	cin>>index;
	return index;
}
struct lnote{
	int data;
	lnote *next;
}; 

lnote* head;
int charu(int location)
{
	lnote *pt=head;
	lnote *temp=(lnote*) malloc(sizeof(lnote));
	cout<<"������Ҫ�������ֵ:";
	cin>>temp->data;
	for(int i=1;i<location;i++)
	pt=pt->next;
	temp->next=pt->next;
	pt->next=temp;
	return 0;
}
void csh(){
	head = (lnote*) malloc(sizeof(lnote));
	head->data = 0; 
	head->next=NULL;
	cout<<"��ʼ���ɹ�"<<endl; 
} 
void createlist(){
	head = (lnote*) malloc(sizeof(lnote));
	head->data = 0; 
	head->next=NULL;
	
	lnote* pt = head;
	
	for(int i = 1;i<=10;i++){
		lnote* temp;
		temp = (lnote*) malloc(sizeof(lnote));
		temp->data = i*10 + i;
		temp->next = NULL;
		pt->next = temp;
		pt = pt->next;
	}
	
}
void printlist(){
	lnote* pt = head;
	int len = 1;
	while(pt->next!=NULL){
		pt=pt->next;
		cout<<"��Ϊ��"<<len<<"������"<<pt->data<<endl;
		len++;
	}
	
}

int countlist(){
	lnote* pt = head;
	int len = 0;
	while(pt->next!=NULL){
		pt=pt->next;
		len++;
		
	}
	return len;
}
int getlocationbydata(int data){
	lnote* pt = head;
	int index = 0; 
	int flag = 1;
	while(pt->next!=NULL){
		index++;
		pt = pt->next;
		if(data==pt->data){
			return index;
			flag = 2;
		}
	}
	if(flag!=2){
		return 0;
	}
} 
int getdatabylocation(int location){
	if(location<=0){
		cout<<"�����λ����������ȷ�����������룡"<<endl;
		return 0;
	}
	if(location>countlist()){
		cout<<"�����λ����������������ĳ��ȣ����������룡"<<endl;
		return 0;
	}
	lnote* pt = head;
	int index = 0; 
	for(int i = 0;i<location;i++){
		pt=pt->next;
	}
	cout<<"��ǰ��"<<location<<"��Ԫ�ص�ֵΪ��"<<pt->data<<endl;
	return 0;
} 
int getprobydata(int data){
	int getindex = getlocationbydata(data);
	if(getindex==0){
		cout<<"��ǰԪ��"<<data<<"û���������в�ѯ��������û��ǰ������"<<endl;
		return 0;
	}
	if(getindex==1){
		cout<<"��ǰԪ��"<<data<<"��������ĵ�һ��Ԫ�أ�û��ǰ������"<<endl;
		return 0;
	}
	lnote* pt = head;
	for(int i = 1;i<getindex;i++){
		pt = pt->next;	
	}
	cout<<"��Ԫ��"<<data<<"��ֱ��ǰ��Ϊ:"<<pt->data<<endl;
}
int getnextbydata(int data){
	int getindex = getlocationbydata(data);
	if(getindex==0){
		cout<<"��ǰԪ��"<<data<<"û���������в�ѯ��������û�к������"<<endl;
		return 0;
	}
	if(getindex==countlist()){
		cout<<"��ǰԪ��"<<data<<"������������һ��Ԫ�أ�û�к������"<<endl;
		return 0;
	}
	lnote* pt = head;
	for(int i = 1;i<getindex+2;i++){
		pt = pt->next;	
	}
	cout<<"��Ԫ��"<<data<<"��ֱ��ǰ���Ϊ:"<<pt->data<<endl;
}
int deletebylocation(int location){
	int getindex = getlocationbydata(location);
	lnote* pt = head;
	if(getindex==0)
	{
		cout<<"ɾ��ʧ��"<<endl;
		return 0; 
	}
	for(int i = 1;i < getindex;i++){
		pt = pt->next;
	}
	pt->next = pt->next->next;
	cout<<"ɾ���ɹ�"<<endl;
	return 0; 
}
int main(){
	while(1){
		int index = showmenu(); 
		switch(index){
			case 1:{
				csh();
				system("pause");
				break;
			}
			case 2:{
				cout<<"ɾ���ɹ�"<<endl;
				system("pause");
				break;
			}
			
			case 3:{
			cout<<"����"<<countlist()<<"������"<<endl;
				system("pause");
				break;
			}
			case 4:{
				int location;
				cout<<"������Ҫ���ҵ�Ԫ������:";
				cin>>location;
				int getdata = getdatabylocation(location);
				system("pause");
				break;
			}
			case 5:{
				int data;
				cout<<"������Ҫ���ҵ�ֵ:";
				cin>>data;
				int getindex = getlocationbydata(data);
				 if(getindex!=0){
				 	cout<<"��ֵΪ��"<<getindex<<"��"<<endl;
				 }
				 else{
				 	cout<<"����û�и�ֵ"<<endl;	
				 }
				system("pause");
				break;
			}
			case 6:{
				int data;
				cout<<"������Ҫ���ҵ�Ԫ��:";
				cin>>data;
				int getdata = getprobydata(data);
				system("pause");
				break;
			}
			case 7:{
				int data;
				cout<<"������Ҫ���ҵ�Ԫ��:";
				cin>>data;
				int getdata = getnextbydata(data);
				system("pause");
				break;
			}
			case 8:{
				int loc;
				cout<<"������Ҫ�����λ��:";
				cin>>loc;
				charu(loc);
				system("pause");
				break;
			}
			case 9:{
				int location;
				cout<<"������Ҫɾ����Ԫ��:";
				cin>>location;
				deletebylocation(location);
				system("pause");
				break;
			}
			case 10:{
				printlist();
				system("pause");
				break;
			}
			case 11:{
				createlist();
				cout<<"�����ɹ�"<<endl;
				system("pause");
				break;
			}
			case 12:{
				exit(10);
				break;
			}
		}
	}	
	return 0;
}
