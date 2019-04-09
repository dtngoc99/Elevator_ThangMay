#include <iostream>
#include"myLib.h"
using namespace std;
#define size 10
#include<math.h>
#include<string.h>
#include<windows.h>


struct QUEUE
{
	int ds[size];
	int n;
};

//ham ve khung chuong trinh
void Draw();
//khoi tao QUEUE
void Init(QUEUE &q);
//kiem tra QUEUE co rong hay khong
bool IsEmpty(QUEUE q);
//them node vao QUEUE
void Insert(QUEUE &q,int x);
//ham lay ra phan tu dau cua QUEUE va xoa
int Delete(QUEUE &q,int &x);
//sap xep
void Sap_Xep_Tang_Dan(QUEUE &q);
void Sap_Xep_Giam_Dan(QUEUE &q);
//sap xep QUEUE
void Sap_Xep_Di_Len(QUEUE &q1,QUEUE p1,QUEUE p2,int tang);
void Sap_Xep_Di_Xuong(QUEUE &q2,QUEUE p1,QUEUE p2,int tang);
//tim toa do cua so tang
void Luachon(int tang);
void Luachon1(int tang);
void Luachon2(int tang);
//thang may di len
void Di_Len(QUEUE &q1,QUEUE &q2,int &tang,int &toado);
//thang may di xuong
void Di_Xuong(QUEUE &q2,QUEUE &q1,int &tang,int &toado);

 
 
int main()
{
	QUEUE q1;
	Init(q1);
	
	QUEUE q2;
	Init(q2);
	QUEUE p1,p2;
	Init(p1);
	Init(p2);
	ShowCur(false);//an con tro nhap nhay
	int tang=0;
	int toado=17;
	Draw();
	while(1)
	{
		int x;
		if(IsEmpty(q1)==false)
		{
			Delete(q1,x);
			Insert(q1,x);
			Sap_Xep_Di_Len(q1,p1,p2,tang);
			if(tang>x)
			{
				if(IsEmpty(q2))
				{
					Insert(q2,x);
					Sap_Xep_Di_Xuong(q2,p1,p2,tang);
				}
				Di_Xuong(q2,q1,tang,toado);
			}
			Di_Len(q1,q2,tang,toado);
		}
		if(IsEmpty(q2)==false)
		{
			Delete(q2,x);
			Insert(q2,x);
			Sap_Xep_Di_Xuong(q2,p1,p2,tang);
			if(tang<x)
			{
				if(IsEmpty(q1))
				{
					Insert(q1,x);
					Sap_Xep_Di_Len(q1,p1,p2,tang);
				}
				Di_Len(q1,q2,tang,toado);
			}
			Di_Xuong(q2,q1,tang,toado);
		}
		if(kbhit())
		{
			char nut=getch();
			if((int)nut==113)//ky tu 'q' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di lennnn: ";
				vitri=getch ();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                       ";
				if(vitri>='0'&& vitri<'8')
				{
					if(vitri=='0')
					{
						Luachon1(vitri-48);
						cout<<'G';
					}
					else
					{
						Luachon1(vitri-48);
						cout<<vitri;
					}
					Insert(q1,vitri-48);
					Sap_Xep_Di_Len(q1,p1,p2,tang);
				}
			
					
			}
			else if((int)nut==112)//ky tu 'p' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di xuong: ";
				vitri=getch();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                      ";
				if(vitri>'0'&& vitri<='8')
				{
					Luachon2(vitri-48);
					cout<<vitri;
					Insert(q2,vitri-48);
					Sap_Xep_Di_Xuong(q2,p1,p2,tang);
				}
					
			}
			else if((int)nut==27)
			{
				break;
			}
		}
	}	

	return 0;
}
//ham ve khung chuong trinh
void Draw()
{
	char x=219;
	//ve 2 cot doc
	for(int i=1;i<=20;i++)
	{
		gotoXY(30,i);
		cout<<x;
		gotoXY(80,i);
		cout<<x;
	}
	//ve 2 cot ngang
	for(int i=30;i<=80;i++)
	{
		gotoXY(i,1);
		cout<<x;
		gotoXY(i,20);
		cout<<x;
	}
	
	gotoXY(50,2);
	SetBGColor(2);
	SetColor(4);
	cout<<"THANG MAY";
	gotoXY(35,4);
	SetColor(8);
	SetBGColor(0);
	cout<<"q.Di len";
	gotoXY(50,4);
	cout<<"p.Di xuong";
	gotoXY(65,4);
	cout<<"ESC.Thoat";
	gotoXY(65,8);
	cout<<"UP";
	gotoXY(70,8);
	cout<<"DOWN";
}
//khoi tao QUEUE
void Init(QUEUE &q)
{
	q.n=0;
}
//kiem tra QUEUE co rong hay khong
bool IsEmpty(QUEUE q)
{
	if(q.n==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//them node vao cuoi QUEUE
void Insert(QUEUE &q,int x)
{
	for(int i=0;i<q.n;i++)
	{
		if(x==q.ds[i])
		{
			return;
		}
	}
	q.ds[q.n++]=x;	
}
//ham lay ra phan tu dau cua QUEUE va xoa
int Delete(QUEUE &q,int &x)
{
	if(IsEmpty(q)==true)
	{
		x=-1;
		return 0;
	}
	else
	{
		x=q.ds[0];
		for(int i=0;i<q.n-1;i++)
		{
			q.ds[i]=q.ds[i+1];
		}
		q.n--;
	}
	return 1;
}
//sap xep QUEUE
void Sap_Xep_Tang_Dan(QUEUE &q)
{
	
	for(int i=0;i<q.n-1;i++)
	{
		for(int j=i+1;j<q.n;j++)
		{
			if(q.ds[i]>q.ds[j])
			{
				int temp=q.ds[i];
				q.ds[i]=q.ds[j];
				q.ds[j]=temp;
			}
		}
	}

}
void Sap_Xep_Giam_Dan(QUEUE &q)
{
	for(int i=0;i<q.n-1;i++)
	{
		for(int j=i+1;j<q.n;j++)
		{
			if(q.ds[i]<q.ds[j])
			{
				int temp=q.ds[i];
				q.ds[i]=q.ds[j];
				q.ds[j]=temp;
			}
		}
	}
}
void Sap_Xep_Di_Len(QUEUE &q1,QUEUE p1,QUEUE p2,int tang)
{
	p1.n=p2.n=0;
	for(int i=0;i<q1.n;i++)
	{
		if(q1.ds[i]>=tang)
		{
			p1.ds[p1.n++]=q1.ds[i];
		}
		else
		{
			p2.ds[p2.n++]=q1.ds[i];
		}
	}
	Sap_Xep_Tang_Dan(p1);
	Sap_Xep_Tang_Dan(p2);
	int i=0,j=0;
	while(p1.n!=0)
	{
		q1.ds[i]=p1.ds[i];
		p1.n--;
		i++;
	}
	while(p2.n!=0)
	{
		q1.ds[i++]=p2.ds[j++];
		p2.n--;
	}
}
void Sap_Xep_Di_Xuong(QUEUE &q2,QUEUE p1,QUEUE p2,int tang)
{
	p1.n=p2.n=0;
	for(int i=0;i<q2.n;i++)
	{
		if(q2.ds[i]<=tang)
		{
			p1.ds[p1.n++]=q2.ds[i];
		}
		else
		{
			p2.ds[p2.n++]=q2.ds[i];
		}
	}
	Sap_Xep_Giam_Dan(p1);
	Sap_Xep_Giam_Dan(p2);
	int i=0,j=0;
	while(i<p1.n)
	{
		q2.ds[i]=p1.ds[i];
		i++;
	}
	while(j<p2.n)
	{
		q2.ds[i++]=p2.ds[j];
		j++;
	}
}
//tim toa do cua tang
void Luachon(int tang)
{
	switch(tang)
	{
		case 8:
			gotoXY(35,10);
			break;
		case 7:
		
			gotoXY(36,10);
			break;
		case 6:
		
			gotoXY(35,11);
			break;
		case 5:
		
			gotoXY(36,11);
			break;
		case 4:
		
			gotoXY(35,12);
			break;
		case 3:
		
			gotoXY(36,12);
			break;
		case 2:
		
			gotoXY(35,13);
			break;
		case 1:
		
			gotoXY(36,13);
			break;
		case 0:
			gotoXY(35,14);
			break;

	}

}
void Luachon1(int tang)
{
	switch(tang)
	{
		case 8:
			gotoXY(65,10);
			break;
		case 7:
		
			gotoXY(65,11);
			break;
		case 6:
		
			gotoXY(65,12);
			break;
		case 5:
		
			gotoXY(65,13);
			break;
		case 4:
		
			gotoXY(65,14);
			break;
		case 3:
		
			gotoXY(65,15);
			break;
		case 2:
		
			gotoXY(65,16);
			break;
		case 1:
		
			gotoXY(65,17);
			break;
		case 0:
			gotoXY(65,18);
			break;

	}
}
void Luachon2(int tang)
{
	switch(tang)
	{
		case 8:
			gotoXY(70,10);
			break;
		case 7:
		
			gotoXY(70,11);
			break;
		case 6:
		
			gotoXY(70,12);
			break;
		case 5:
		
			gotoXY(70,13);
			break;
		case 4:
		
			gotoXY(70,14);
			break;
		case 3:
		
			gotoXY(70,15);
			break;
		case 2:
		
			gotoXY(70,16);
			break;
		case 1:
		
			gotoXY(70,17);
			break;
		case 0:
			gotoXY(70,18);
			break;

	}	
}
//thang may di len
void Di_Len(QUEUE &q1,QUEUE &q2,int &tang,int &toado)
{

	QUEUE p1,p2;
	Init(p1);
	Init(p2);
	while(1)
	{
		int x;
		Delete(q1,x); //lay ra phan tu dau QUEUE va xoa
		if(x<tang && x>-1)
		{
			Insert(q1,x);
			Sap_Xep_Di_Len(q1,p1,p2,tang);
			return;
		}
		while((tang<x && !kbhit()))
		{
			if(tang==0)
			{
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<'G';
			}
			else
			{
				gotoXY(50,toado); 
				SetBGColor(4);
				cout<<tang;
			}
			Sleep(2000);
			gotoXY(50,toado);
			SetBGColor(0);
			cout<<' ';
			tang++;
			toado--;
		}
		if(kbhit())
		{
			if(tang<x)
			{
				Insert(q1,x );
				Sap_Xep_Di_Len(q1,p1,p2,tang);
			}
			char nut=getch();
			if((int)nut==113)//ky tu 'q' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di lennn:";
				vitri=getch();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                     ";
				if(vitri>='0'&& vitri<'8')
				{
					if(vitri=='0')
					{
						Luachon1(vitri-48);
						cout<<'G';
					}
					else
					{
						Luachon1(vitri-48);
						cout<<vitri;
					}
					Insert(q1,vitri-48);
					Sap_Xep_Di_Len(q1,p1,p2,tang);
				}		
			}
			else if((int)nut==112)//ky tu 'p' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di xuong:";
				vitri=getch();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                     ";
				if(vitri>'0'&& vitri<='8')
				{
					Luachon2(vitri-48);
					cout<<vitri;
					Insert(q2,vitri-48);
					Sap_Xep_Di_Xuong(q2,p1,p2,tang);
				}			
			}
			else if(nut>='0'&& nut<='8')
			{
				if(nut=='0')
				{
					Luachon(nut-48);
					cout<<'G';
				}
				else
				{
					Luachon(nut-48);
					cout<<nut;
				} 
				Insert(q1,nut-48);
				Sap_Xep_Di_Len(q1,p1,p2,tang);
			}
		}
		if(tang==x)
		{
			if(tang==0)
			{
				Beep(1232,400);
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<'G';
			}
			else
			{
				Beep(1232,400);
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<tang;
			}
			SetBGColor(0);
			Luachon(tang);
			cout<<' ';
			Luachon1(tang);
			cout<<' ';
			Sleep(4000);
			gotoXY(50,toado);
			cout<<' ';
		}
		if(IsEmpty(q1) && !kbhit())
		{
			Sleep(2000);
			return;
		}
	}

}
//thang may di xuong
void Di_Xuong(QUEUE &q2,QUEUE &q1,int &tang,int &toado)
{
	QUEUE p1,p2;
	Init(p1);
	Init(p2); 
	while(1)
	{
		int x; 
		Delete(q2,x); //lay ra phan tu dau QUEUE va xoa
		if(x>tang)
		{
			Insert(q2,x);
			Sap_Xep_Di_Xuong(q2,p1,p2,tang);
			return;
		}
		while((tang>x && x>-1 && !kbhit()))
		{
			if(tang==0)
			{
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<'G';
			}
			else
			{
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<tang;
			}
			Sleep(2000);
			gotoXY(50,toado);
			SetBGColor(0);
			cout<<' ';
			tang--;
			toado++;
		}
		if(kbhit())
		{
			if(tang>x)
			{
				Insert(q2,x);
				Sap_Xep_Di_Xuong(q2,p1,p2,tang);
			}
			char nut=getch();
			if((int)nut==112)//ky tu 'p' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di xuong:";
				vitri=getch();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                     ";
				if(vitri>'0'&& vitri<='8')
				{
					Luachon2(vitri-48);
					cout<<vitri;
					Insert(q2,vitri-48);
					Sap_Xep_Di_Xuong(q2,p1,p2,tang);	
				}				
			}
			else if((int)nut==113)//ky tu 'q' nhan nut nhan ngoai thang may lua chon di len
			{
				char vitri;
				gotoXY(32,6);
				cout<<"Vi tri nguoi nhan thang may di lennn:";
				vitri=getch();
				SetBGColor(0);
				gotoXY(32,6);
				cout<<"                                     ";
				if(vitri>='0'&& vitri<'8')
				{
					if(vitri=='0')
					{
						Luachon1(vitri-48);
						cout<<vitri;
					}
					else
					{
						Luachon1(vitri-48);
						cout<<vitri;
					}
					Insert(q1,vitri-48);
					Sap_Xep_Di_Len(q1,p1,p2,tang);
				}			
			}
			else if(nut>='0'&& nut<='8')
			{
				if((nut-48)==0)
				{
					Luachon(nut-48);
					cout<<'G';
				}
				else
				{
					Luachon(nut -48);
					cout<<nut;
				}
				Insert(q2,nut-48);
				Sap_Xep_Di_Xuong(q2,p1,p2,tang);
			}
		}
		if(tang==x)
		{
			if(tang==0)
			{
				Beep(1232,400);
				SetBGColor(4);
				gotoXY(50,toado);
				cout<<'G';
			}
			else
			{
				Beep(1232,400);
				gotoXY(50,toado);
				SetBGColor(4);
				cout<<tang;
			}
			SetBGColor(0);
			Luachon(tang);
			cout<<' ';
			Luachon2(tang);
			cout<<' ';
			Sleep(4000);
			gotoXY(50,toado);
			cout<<' ';
		}
		if(IsEmpty(q2) && !kbhit())
		{
			Sleep(2000);
			return;
		}

	}

}
