#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<string.h>    
#include<process.h>    //for exit function
#include<iomanip.h>    //for setw function //for string characters
#include<dos.h>
#include<iostream.h>
#include<time.h>

//****************************************************************
// CLASS USED IN PROJECT
//****************************************************************
class consumer
		{ 
		protected:
		int cno;
		char cname[20];
		char adress[20];
		int a,b,c;
		float i;
		public:
 
      //FUNCTION TO ENTER THE VALUES
 	
      void entry()
		{
		clrscr();
	textcolor(YELLOW);
	textbackground(BLUE);
		
	clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
	textcolor(RED);
		gotoxy(26,4);
		cputs("COSTUMER DETAILS AND NEW ENTRY ");
		gotoxy(5,8);
		cputs("Customer ID :");
		gotoxy(5,10);
		cputs("Customer name :");
		gotoxy(5,12);
		cputs("Customer adress :");
		gotoxy(5,14);
		cputs("Customer Service number :");
		gotoxy(5,16);
		cputs("Costumer Smart card number :");
		gotoxy(5,18);
		cputs("Costumer Phone number :");
		gotoxy(5,20);
		cputs("Customer Bill number :");
		gotoxy(45,8);
		cin>>cno;
		gotoxy(45,10);
		gets(cname);
		gotoxy(45,12);
		gets(adress);
		gotoxy(45,14);
		cin>>a;
		gotoxy(45,16);
		cin>>b;
		gotoxy(45,18);
		cin>>c;
		gotoxy(45,20);
		cin>>i;
		}
 
      //FUNCTION TO DISPLAY THE VALUES
 
      void display()
		    {
		    
		    gotoxy(5,8);
		    cputs("Customer ID :");
		    cout<<cno;
		    gotoxy(5,10);
		    cputs("Customer name :");
		    puts(cname);
		    gotoxy(5,12);
		    cout<<"Customer adress :"<<adress;
		    gotoxy(5,14);
		    cout<<"Customer Service number :" <<a;
		    gotoxy(5,16);
		    cout<<"Costumer Smart card number :"<<b;
		    gotoxy(5,18);
		    cout<<"Costumer Phone number :"<<c;
		    gotoxy(5,20);
		    cout<<"Customer Bill number :"<<i;
		    }
      int rcno()
      {
      return cno;
      }
      }c;
 
      //FUNCTION TO WRITE THE VALUES
 
      void write()
		{
		char ch;
		consumer c;
		fstream f1;
		c.entry();
		f1.open("main.dat",ios::app|ios::binary);
gotoxy(5,22);	cout<<"DO you want to save the record(y/n)=";
		cin>>ch;
		if(ch=='y')
		{
		f1.write((char*)&c,sizeof(c));
		}
		f1.close();
		}
 
	  //FUNCTION TO READ THE VALUES
 
      void read()
		{
		clrscr();
	textcolor(YELLOW);
	textbackground(BLUE);
		consumer c;
		fstream f1;
		f1.open("main.dat",ios::in|ios::binary);
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		c.display();
		if(f1.eof())
		{
		cout<<"\n\n   End of the file reached\n\n";
		}
		}
		f1.close();

	
		}
 
      //FUNCTION FOR SEARCHING THE RECORD
 
      void search()
		{
		consumer c;
		int rn;
		char found='n';
		ifstream f1("main.dat",ios::in);
	gotoxy(5,5);	cout<<"Enter Customer ID you want to SEARCH :";
		cin>>rn;
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rn)
		{
		c.display();
		found='y';
		break;
		}
		}
		if(found=='n')
	gotoxy(19,10);	cout<<"RECORD NOT FOUND!!!!!!!!!!!!!"<<endl;
		f1.close();
	
		
		}
 
      //FUNCTION TO DELELTE THE RECORD
 
      void del()
		{
		ifstream f1("main.dat",ios::in);
		ofstream f2("temp.dat",ios::out);
		int rno;
		char found='f',confirm='n';
		cout<<"\n\n Enter Customer ID you want to DELETE :\t";
		cin>>rno;
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
		c.display();
		found='t';
		cout<<"\n\n Are you sure want to DELETE this record ? (y/n)\t";
		cin>>confirm;
		if(confirm=='n')
		f2.write((char*)&c,sizeof(c));
		}
		else
		f2.write((char*)&c,sizeof(c));
		}
		if(found=='f')
		cout<<"\n\n\tRECORD NOT FOUND\n";
		f1.close();
		f2.close();
		remove("main.dat");
		rename("temp.dat","main.dat");
		f1.open("main.dat",ios::in);
		clrscr();
		cout<<"\n\n\n Now the file contains\n\n\n";
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(f1.eof())
		c.display();
		}
		f1.close();
		
	
		}
 
      //FUNCTION TO MODIFY THE RECORD
 
      void update()
		{
		fstream f1("main.dat",ios::in | ios::out | ios::binary);
		int rno;
		long pos;
		char found='f';
		cout<<"\n\n Enter the Customer ID you want to MODIFY :\t";
		cin>>rno;
		while(!f1.eof())
		{
		pos=f1.tellg();
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
		c.entry();
		f1.seekg(pos);
		f1.write((char*)&c,sizeof(c));
		found='t';
		break;
		}
		}
		if(found=='f')
		cout<<"\n\n\tRECORD NOT FOUND\n";
		f1.seekg(0);
		clrscr();
		cout<<"\n Now the file contains\n\n";
		c.display();
		f1.close();
		
		getch();
		}
		/*
class detail : public consumer
{
void detail_shop()
{

 
		//TO DISPLAY THE CANTEEN DETAILS
 
	
	gotoxy(9,4);cout<<"****************";
gotoxy(9,5);	cout<<"* SHOP DETAILS *";
gotoxy(9,6);	cout<<"****************";
gotoxy(5,8);	cout<<"#   TIMING: 11 AM TO 02 PM & 03 PM TO 05 PM        ";
gotoxy(5,9);	cout<<"#   SHOP WILL CLOSED ON TUESDAY.      ";
gotoxy(5,10);	cout<<"#   GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED.      ";
gotoxy(5,11);	cout<<"#   TAKE YOUR SMART CARD WITH YOU.     ";
gotoxy(5,12);	cout<<"#   COLLECT YOUR SMART CARD & BILL AFTER PAYMENT.     ";
gotoxy(5,13);	cout<<"#   DO NOT BREAK ANY SHOP ITEMS.      ";
gotoxy(5,14);	cout<<"#   FOR ANY COMPLAINT CONTACT THE CHAIR PERSON.      ";
gotoxy(5,15);	cout<<"#   25 YEARS OF EXPERIENCE.       ";
gotoxy(5,16);	cout<<"#   CHAIR PERSON :- RUPESH BORSE    ";
gotoxy(5,17);	cout<<"#   AN ISO 9001-2000 CERTIFIED COMPANY.  ";
gotoxy(5,18);	cout<<"#   WELL QUALIFIED STAFF MEMBERS. ";
gotoxy(5,19);	cout<<"#   website :- www.rog_computers.com  ";
gotoxy(5,20);	cout<<"#   Email :- rog@gmail.com";
textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
		getch();
		clrscr();
		

}
}*/
void main()
{
consumer c;
unsigned int sum,add,d,j,e,f,g,h,k,l,w,x,y,z,choice;
		int abis=0,apep=0,aden=0,amun=0,aperk=0,acoc=0,atit=0,alux=0,atid=0,aree=0,ch3,seller;
		unsigned int m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u,v=0;
		int pend=0,print=0,graph=0,ram=0,hard=0,win=0,ant=0,p1=0,p2=0,g1=0,r1=0,h1=0,w1=0,an1=0,mo=0,mous=0,web=0,aweb=0,asc=0,scan=0,total=0;
		char pu,str[10],yes,et;

time_t now;
struct tm nowlocal;
char ch;
unsigned int ch1;
	textcolor(YELLOW);
	textbackground(BLUE);
	now=time(NULL);
	nowlocal=*localtime(&now);
	do{
	clrscr();pass:;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"";
		delay(5);
	}

	delay(500);
    /*	 ******************** W E L C O M E********************* */
	gotoxy(14,5);
cputs("******************************************************");
	gotoxy(14,6);
cputs("********** SHOP MANAGMENT SYSTEM (COMPUTER) **********");
	gotoxy(14,7);
cputs("******************************************************");
	gotoxy(30,9);
	cout<<"Today is ::"<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon+1<<"/"<<nowlocal.tm_year+1900;
    gotoxy(30,10);
	cout<<"Time.    ::"<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<":"<<nowlocal.tm_sec;
    gotoxy(28,15);
	cout<<"Enter your Password :: ";
	str[0]=getch();
	cout<<"*";
	str[1]=getch();
	cout<<"*";
	str[2]=getch();
	cout<<"*";
	str[3]=getch();
	cout<<"*";
	str[4]=getch();
	cout<<"*";
	str[5]=getch();
	cout<<"*";
	str[6]=getch();
	cout<<"*";
	str[7]='\0';
	cout<<"*";
	if(strcmp(str,"pass123")==0)
	{
	clrscr();
		gotoxy(22,5);
	cout<<"!!PLEASE WAIT WHILE LOADING THE PROJECT!!";
	int x;
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"*";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"*";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"*";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"*";
		delay(5);
	}
	delay(500);
	gotoxy(30,12);
	cout<<"LOADING....";
	int u=0;
	for(int i=1;i<=10;i++)
	{
		gotoxy(30+u,13);
		delay(500);
		cout<<"";
		u=u+2;
		gotoxy(52,13);
		cout<<i<<"0%";
	}
	gotoxy(35,14);
	cout<<"COMPLETE ";
	delay(200);
	cout<<"!";
	delay(200);
	cout<<"!";
	delay(300);
	gotoxy(50,22);
	cout<<"\n\n";
	textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
		textcolor(YELLOW);
	clrscr();
	for(x=2;x<80;x++)
	{
		gotoxy(x,1);
		if(x%2==0)
			cout<<"";
		else	cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(1,x);
		cout<<"";
		delay(5);
	}
	for(x=2;x<80;x++)
	{
		gotoxy(x,25);
		if(x%2==0)
			cout<<"";
		else    cout<<" ";
		delay(5);
	}
	for(x=2;x<25;x++)
	{
		gotoxy(80,x);
		cout<<"";
		delay(5);
	}


	textcolor(YELLOW);
	delay(500);
	gotoxy(13,5);
	cout<<"******************** W E L C O M E*********************";
	gotoxy(14,9);
	cout<<" S H O P  M A N A G E M E N T  S Y S T E M (Computer)";
	gotoxy(19,13);
	cout<<" D E V E L O P E D  B Y : ";
	gotoxy(44,13);
	cout<<" GOPAL BHARET PATIL ";
	gotoxy(45,14);
	cout<<"OM BALKRISHNA JADHAV";
	gotoxy(45,15);
	cout<<"RUPESH RANJEET BORSE";
	cout<<"\n\n";
	textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
	clrscr();


		again:;
		clrscr();

textcolor(YELLOW);
	textbackground(BLUE);
	do
	{
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(15,3);	cout<<"*************";
gotoxy(15,4);	cout<<"* MAIN MENU *";
gotoxy(15,5);	cout<<"*************";	

		gotoxy(12,8);cout<<"01. STOCK OF COMPUTER ITEMS.\n";
		gotoxy(12,10);cout<<"02. NEW ENTRY.\n";
		gotoxy(12,12);cout<<"03. DETAILS.\n";
	    gotoxy(12,14);cout<<"04. SELLER VIEW.\n";
		gotoxy(12,16);cout<<"05. QUANTITY AVAILABLE.\n";
		gotoxy(12,18);cout<<"06. EXIT.\n";
		gotoxy(12,21);cout<<"Select Your Option (1-6) : ";
	    ch=getch();
		switch(ch)
		{
			case '1':
		clrscr();
		int pi;
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}
gotoxy(9,4);    cout<<"**************";
gotoxy(9,5);	cout<<"* STOCK VIEW *";
gotoxy(9,6);	cout<<"**************";
gotoxy(5,8);	cout<<"#   TIMING: 11 AM TO 02 PM & 03 PM TO 05 PM        ";
gotoxy(5,9);	cout<<"#   SHOP WILL CLOSED ON TUESDAY.      ";
gotoxy(5,10);	cout<<"#   IN THIS MENU COSTUMER CAN SEE THE STOCK . ";
gotoxy(5,11);	cout<<"#   IF YOU WANT TO PURCHASE A PRODUCT YOU CAN SAY YES=Y OR NO=N. ";
gotoxy(5,12);	cout<<"#   website :- www.rog_computers.com  ";
gotoxy(5,13);	cout<<"#   Email :- rog@gmail.com";
textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
			goto items;


			case '2': 
				clrscr();
		// TO ENTER THE DETAILS OF THE COSTUMER
 
		write();
 
	// ITEMS AND THIER RATES
		start:
		gotoxy(5,24);cout<<"DO YOU WANT TO PURCHASE(Y/N):";
		cin>>pu;
		if(pu=='Y'||pu=='y')
		{
		
items:;
	// PURCHASE LIST
clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,2);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(20,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,24);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(60,x);
			cout<<"";
			delay(5);
		}
		
gotoxy(31,4);	cout<<"*****************";
gotoxy(31,5);	cout<<"* PURCHASE LIST *";
gotoxy(31,6);	cout<<"*****************";
gotoxy(33,9);	cout<<"1.PENDRIVE";
gotoxy(33,10);	cout<<"2.SCANNER";
gotoxy(33,11);	cout<<"3.PRINTER";
gotoxy(33,12);	cout<<"4.WEBCAM";
gotoxy(33,13);	cout<<"5.GRAPHIC CARD";
gotoxy(33,14);	cout<<"6.RAM";
gotoxy(33,15);	cout<<"7.HARD DISK";
gotoxy(33,16);	cout<<"8.WINDOWS ORIGINAL CD'S";
gotoxy(33,17);	cout<<"9.ANTIVIRUS";
gotoxy(33,18);	cout<<"10.MOUSE";
gotoxy(31,22);	cout<<"Enter your choice\t";
		cin>>choice;
		if(choice==1)
		{
bis:;
	//ITEMS AND RATES
	// PURCHASE LIST
clrscr();
int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}

gotoxy(31,4);	cout<<"*************";
gotoxy(31,5);	cout<<"* PENDRIVES *";
gotoxy(31,6);	cout<<"*************";
gotoxy(28,9);	cout<<"  Items----------RATE";
gotoxy(28,11);	cout<<" 1. 2GB     |      350";
gotoxy(28,12);	cout<<" 2. 4GB     |      500";
gotoxy(28,13);	cout<<" 3. 5GB     |      700";
gotoxy(28,14);	cout<<" 4. 8GB     |      500";
gotoxy(28,15);	cout<<" 5. 16GB    |      1800";
gotoxy(28,16);	cout<<" 6. 32GB    |      2400";
gotoxy(28,17);  cout<<" 7. 64GB    |      3000";
gotoxy(25,19);	cout<<"Which PENDRIVE you want to purchaset =";
		cin>>p1;
		if(p1==1)
		{
		pend=350;
		}
		else if(p1==2)
		{
		pend=500;
		}
		else if(p1==3)
		{
		pend=700;
		}
		else if (p1==4)
		{
		pend=800;
		}
		else if(p1==5)
		{
		pend=1800;
		}
		else if(p1==6)
		{
		pend=2400;
		}
		else if(p1==7)
		{
		pend=3000;
		}
		else if(p1==0)
		{
		goto items;
		}
		else if(p1!=1||p1!=2||p2!=3||p1!=4||p1!=5||p1!=6||p1!=7)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto bis;
		}
gotoxy(25,20);	cout<<"PENDRIVE(MAX 5): ";
		cin>>m;
		if(m>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
		goto items;
		}
		else
		abis=1000-m;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==2)
		{
		pep:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}

gotoxy(30,4);	cout<<"***********";
gotoxy(30,5);	cout<<"* SCANNER *";
gotoxy(30,6);	cout<<"***********";
gotoxy(28,9);	cout<<"    ITEMS-------------------RATE";
gotoxy(28,11);	cout<<"  1.FLATBED          |       5000";
gotoxy(28,12);	cout<<"  2.SHETFED          |       6000";
gotoxy(28,13);	cout<<"  3.PHOTO SCANNER    |       4500";
gotoxy(28,14);	cout<<"  4.FILM SCANNER     |       8000";
gotoxy(28,15);	cout<<"  5.PORTABLE SCANNER |       10000";
gotoxy(25,18);	cout<<"Which SCANNER do you want to purchase=";
            cin>>scan;
		if(scan==1)
		{
		asc=5000;
		}
		else if(scan==2)
		{
		asc=6000;
		}
		else if(scan==3)
		{
		asc=4500;
		}
		else if(scan==4)
		{
		asc=8000;
		}
		else if(scan==5)
		{
		asc=10000;
		}
		else if(scan==0)
		{
		goto items;
		}
		else if(scan!=1||scan!=2||scan!=3||scan!=4||p1!=5)
		{
	gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";	
		getch();
		goto pep;
		}
gotoxy(25,20);	cout<<"SCANNER(MAX 5):";
		cin>>n;
		if(n>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
      goto items;
		}
		else
		apep=1000-n;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==3)
		{
		den:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}

gotoxy(30,4);	cout<<"************";
gotoxy(30,5);	cout<<"* PRINTERS *";
gotoxy(30,6);	cout<<"************";	
gotoxy(28,9);	cout<<"    ITEMS----------------------RATE";
gotoxy(28,10);	cout<<"1. HP Laser jet          |     2000";
gotoxy(28,11);	cout<<"2. DOT Matrix Printe     |     5000";
gotoxy(25,17);	cout<<"Which PRINTER you want to purchase=";
		cin>>p2;
		if(p2==1)
		{
		print=2000;
		}
		else if(p2==2)
		{
		print=5000;
		}
		else if(p2==0)
		{
		goto items;
		}
		else if(p2!=1||p2!=2)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto den;
		}
gotoxy(25,20);cout<<"PRINTER(MAX 5): ";
		cin>>o;
		if(o>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
      goto items;
		}
		else
		aden=110-o;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==4)
		{
		mun:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(30,4);	cout<<"**********";
gotoxy(30,5);	cout<<"* WEBCAM *";
gotoxy(30,6);	cout<<"**********";	
gotoxy(28,9);	cout<<" ITEMS-------------------RATE";
gotoxy(28,10);	cout<<"1.5 PIXEL       |        1500\n";
gotoxy(28,11);  cout<<"2.8 PIXEL       |         6000";
gotoxy(28,12);  cout<<"3.12 PIXEL      |        12000\n";
gotoxy(25,17);	cout<<"Which WEBCAM you want to purchase=";
		cin>>web;
		if(web==1)
		{
		aweb=1500;
		}
		else if(web==2)
		{
		aweb=6000;
		}
		else if(web==3)
		{
		aweb=12000;
		}
		else if(web==0)
		{
		goto items;
		}
		else if(web!=1||web!=2||web!=3)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto mun;
		}
gotoxy(25,20);	cout<<"WEBCAM(MAX 5): ";
		cin>>p;
		if(p>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
		goto items;
       }
		else
		amun=1000-p;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==5)
		{
		park:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(30,4);	cout<<"****************";
gotoxy(30,5);	cout<<"* GRAPHIC CARD *";
gotoxy(30,6);	cout<<"****************";	
gotoxy(28,9);	cout<<" ITEMS------------------------RATE";
gotoxy(28,10);  cout<<"1.RX 5600  4gb           |    7000";
gotoxy(28,11);	cout<<"2.Nvidia gtx 1660 6GB    |    8000";
gotoxy(28,12);	cout<<"3.Nvidia gtx 1660ti 6gb  |    9000\n";
gotoxy(28,13);  cout<<"4.Nvidia gtx 1060ti 6gb  |   10000\n";
gotoxy(28,17);	cout<<"Which GRAPHIC CARD you want to purchase=";
		cin>>g1;
		if(g1==1)
		{
		graph=7000;
		}
		else if(g1==2)
		{
		graph=8000;
		}
	else if(g1==3)
		{
		graph=9000;
		}
	else if(g1==4)
		{
		graph=10000;
		}
		else if(g1==0)
		{
		goto items;
		}
		else if(g1!=1||g1!=2||g1!=3||g1!=4)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto park;
		}
gotoxy(25,20);	cout<<"GRAPHIC CARD(MAX 5): ";
		cin>>q;
		if(q>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
		goto items;
		}
		else
		aperk=500-q;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==6)
		{
		coco:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(30,4);	cout<<"*******";
gotoxy(30,5);	cout<<"* RAM *";
gotoxy(30,6);	cout<<"*******";	
gotoxy(28,9);	cout<<" ITEMS-------------------------------RATE";
gotoxy(28,10);	cout<<"1. DDR4 4GB                    |      2000\n";
gotoxy(28,11);	cout<<"2. DDR4 8GB                    |      4000\n";
gotoxy(28,12);	cout<<"3. DDR4 16GB(not Available)    |      6000\n";
gotoxy(28,13);	cout<<"4. DDR4 32GB(not Available)    |      8000\n";
gotoxy(28,14);	cout<<"5. DDR3 8GB(not Available)     |      4000\n";
gotoxy(25,17);	cout<<"Which RAM you want to purchase=";
	cin>>r1;
		if(r1==1)
		{
		ram=2000;
		}
		else if(r1==2)
		{
		ram=4000;
		}
		else if(r1==0)
		{
		goto items;
		}
		else if(r1!=1||r1!=2)
		{
	gotoxy(25,20);	cout<<"OOPS!!!!!!!  (Not Available)";
		getch();
		goto coco;
		}
gotoxy(25,20);		cout<<"RAM(MAX 2): ";
		cin>>r;
		if(r>2)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 2";
		getch();
      goto items;
		}
		else
		acoc=400-r;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==7)
		{
		titan:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(35,4);	cout<<"*************";
gotoxy(35,5);	cout<<"* HARD DISK *";
gotoxy(35,6);	cout<<"*************";	
gotoxy(28,9);	cout<<" ITEMS-------------------RATE";
gotoxy(28,10);	cout<<"1. 20GB       |          1500";
gotoxy(28,11);	cout<<"2. 50GB       |          2000";
gotoxy(28,12);	cout<<"3. 80GB       |          3000";
gotoxy(28,13);	cout<<"4. 160GB      |          5000";
gotoxy(28,14);	cout<<"5. 320GB      |          8000";
gotoxy(25,17);	cout<<"Which HARD DISK you want to purchase=";
		cin>>h1;
		if(h1==1)
		{
		hard=1500;
		}
		else if(h1==2)
		{
		hard=2000;
		}
		else if(h1==3)
		{
		hard=3000;
		}
		else if(h1==4)
		{
		hard=5000;
		}
		else if(h1==5)
		{
		hard=8000;
		}
		else if(h1==0)
		{
		goto items;
		}
		else if(h1!=1||h1!=2||h1!=3||h1!=4||h1!=5)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto titan;
		}
	gotoxy(25,20);cout<<"HARD DISK(MAX 5): ";
		cin>>s;
		if(s>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
      goto items;
		}
		else
		atit=100-s;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
 
		}
		if(choice==8)
		{
		lux:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(25,4);	cout<<"************************";
gotoxy(25,5);	cout<<"* WINDOWS ORIGINAL CD'S *";
gotoxy(25,6);	cout<<"************************";	
gotoxy(28,9);	cout<<" ITEMS----------------RATE";
gotoxy(28,10);	cout<<"1. 98           |       100";
gotoxy(28,11);	cout<<"2. 2000         |       200";
gotoxy(28,12);	cout<<"3. XP           |       400";
gotoxy(28,13);	cout<<"4. VISTA        |       800";
gotoxy(28,14);	cout<<"5. windows7     |       1000";
gotoxy(28,15);	cout<<"6. windows10    |       1100";
gotoxy(25,17);cout<<"Which WINDOWS CD you want to purchase=";
		cin>>w1;
		if(w1==1)
		{
		win=100;
		}
		else if(w1==2)
		{
		win=200;
		}
		else if(w1==3)
		{
		win=400;
		}
		else if(w1==4)
		{
		win=800;
		}
		else if(w1==5)
		{
		win=900;
		}
	else if(w1==6)
		{
		win=1000;
		}
		else if(w1==0)
		{
		goto items;
		}
		else if(w1!=1||w1!=2||w1!=3||w1!=4||w1!=5||w1!=6)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto lux;
		}
gotoxy(25,20);	cout<<"WINDOWS ORIGINAL CD(MAX 5): ";
		cin>>t;
		if(t>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
		goto items;
		}
		else
		alux=1000-t;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==9)
		{
		tid:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(30,4);	cout<<"*************";
gotoxy(30,5);	cout<<"* ANTIVIRUS *";
gotoxy(30,6);	cout<<"*************";	
gotoxy(28,9);	cout<<" ITEMS----------------RATE";
gotoxy(28,10);	cout<<"1. NORTON     |       1500";
gotoxy(28,11);	cout<<"2. AVIRA       |       1200";
gotoxy(28,12);	cout<<"3. QUICKHEAL   |       1300";
gotoxy(28,17);cout<<"Which ANTIVIRUS you want to purchase=";
	cin>>an1;
	if(an1==1)
		{
		ant=1500;
		}
		else if(an1==2)
		{
		ant=1200;
		}
		else if(an1==3)
		{
		ant=1300;
		}
		else if(an1==0)
		{
		goto items;
		}
		else if(an1!=1||an1!=2||an1!=3)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto tid;
		}
gotoxy(25,20);	cout<<"ANTI VIRUS(MAX 5): ";
		cin>>u;
		if(u>5)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 5";
		getch();
		goto items;
		}
		else
		atid=1000-u;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==10)
		{
		ree:;
		clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
gotoxy(35,4);	cout<<"*********";
gotoxy(35,5);	cout<<"* MOUSE *";
gotoxy(35,6);	cout<<"*********";	
gotoxy(28,9);	cout<<" ITEMS----------------RATE";
gotoxy(28,10);	cout<<"1.BALL MOUSE    |    150";
gotoxy(28,11);	cout<<"2.LASER MOUSE   |    300";
gotoxy(25,17);	cout<<"Which MOUSE do you want to purchase=";
		cin>>mous;
		if(mous==1)
		{
		mo=150;
		}
		else if(mous==2)
		{
		mo=300;
		}
		else if(mous==0)
		{
		goto items;
		}
		else if(mous!=1||mous!=2)
		{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice";
		getch();
		goto ree;
		}
gotoxy(25,20);	cout<<"MOUSE(MAX 2): ";
		cin>>v;
		if(v>2)
		{
gotoxy(25,22);	cout<<"Enter Quantity Smaller than 2";
		getch();
		goto items;
		}
		else
		aree=300-v;
gotoxy(25,23);	cout<<"DO you want to purchase more(y/n)=";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;   //GO BACK TO PURCHASE LIST
		}
		else
		{
		clrscr();
		goto cash;    //TO DISPLAY BILL
		}
		}
cout<<"\n\n\n";
clrscr();
cash:;
cout<<"\n\n\n\n\n\n\t\t\t\t R.O.G COMPUTERS\n";
cout<<"\n\n\t\t\t\t    CASH MEMO\n";
cout<<"\n\n\n\n\n\n\n\n";
 

	//TO DISPLAY THE CASH MEMO
       //TO DISPLAY THE INFORMATION OF THE CUSTOMER
 
		c.display();
 
	//TO DISPLAY THE CASH MEMO
 
		cout<<"\n\n\n\n";
		cout<<"===============================================================================";
		cout<<"\nITEMS"            <<setw(40)<<"QUANTITY"<<setw(35)<<"PRICE(Rs.)";
		cout<<"===============================================================================";
		if(m>0)
		cout<<"\n\nPENDRIVE"            <<setw(35)<<m<<setw(28)<<"Rs."<<m*pend;
		if(n>0)
		cout<<"\n\nSCANNER"             <<setw(36)<<n<<setw(28)<<"Rs."<<n*asc;
		if(o>0)
		cout<<"\n\nPRINTER"             <<setw(36)<<o<<setw(28)<<"Rs."<<o*print;
		if(p>0)
		cout<<"\n\nWEBCAM"              <<setw(37)<<p<<setw(28)<<"Rs."<<p*aweb;
		if(q>0)
		cout<<"\n\nGRAPHIC CARD"        <<setw(31)<<q<<setw(28)<<"Rs."<<q*graph;
		if(r>0)
		cout<<"\n\nRAM"                 <<setw(40)<<r<<setw(28)<<"Rs."<<r*ram;
		if(s>0)
		cout<<"\n\nHARD DISK"           <<setw(34)<<s<<setw(28)<<"Rs."<<s*hard;
		if(t>0)
		cout<<"\n\nWINDOWS ORIGINAL CD" <<setw(24)<<t<<setw(28)<<"Rs."<<t*win;
		if(u>0)
		cout<<"\n\nANTIVIRUS"           <<setw(34)<<u<<setw(28)<<"Rs."<<u*ant;
		if(v>0)
		cout<<"\n\nMOUSE"                <<setw(38)<<v<<setw(28)<<"Rs."<<v*mo;
			e=m*pend;
			f=n*asc;
			g=o*print;
			h=p*aweb;
			k=q*graph;
			l=r*ram;
			w=s*hard;
			x=t*win;
			y=u*ant;
			z=v*mo;
		   sum=e+f+g+h+k+l+w+x+y+z;     //TOTAL BILL
		   add=m+n+o+p+q+r+s+t+u+v;     //QUANTITY OF ITEMS
		cout<<"\n===============================================================================";
		cout<<"\nTOTAL:"<<setw(38)<<add<<setw(27)<<"Rs."<<sum;
		money:;
		cout<<"\n\n\n\n\t\t\tEnter the cash paid\t";
		cin>>total;
		cout<<"\n\n\n\t\t\tCASH RECIEVED :"<<total;
		if(total<sum)
		{
		cout<<"\n\n\tThe money you paid is less !!!! Please pay more money";
		getch();
		goto money;
		}
		clrscr();
gotoxy(20,6);  cout<<"NO CREDIT OF THE ADDITIONAL DUTY OF";
gotoxy(25,7);	cout<<"CUSTOMS LEVIED UNDER SECTION (5) OF";
gotoxy(25,8);	cout<<"SECTION-3 OF THE CUSTOMS TARIFF ACT";
gotoxy(25,9);	cout<<"1975 HAVE BEEN AVAILED/SHALL BE ADMISSABLE";
gotoxy(25,11);	cout<<"CASH RECEIVED :"<<total;
gotoxy(25,12);  cout<<"CASH AMOUNT :"<<sum;
gotoxy(25,13);	cout<<"BALANCE RETURNED :"<<total-sum;
gotoxy(25,16);	cout<<"THANK YOU .VISIT US AGAIN";
gotoxy(25,17);	cout<<"THANK YOU FOR USING OUR SERVICE";
		getch();
		goto again;
		}
		else
		{
		clrscr();
		getch();
		goto again;
		}

			case '3':
				clrscr();
		int x;
		for(x=2;x<80;x++)
		{
			gotoxy(x,1);
			if(x%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(1,x);
			cout<<"";
			delay(5);
		}
		for(x=2;x<80;x++)
		{
			gotoxy(x,25);
			if(x%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(x=2;x<25;x++)
		{
			gotoxy(80,x);
			cout<<"";
			delay(5);
		}
			gotoxy(9,4);cout<<"****************";
gotoxy(9,5);	cout<<"* SHOP DETAILS *";
gotoxy(9,6);	cout<<"****************";
gotoxy(5,8);	cout<<"#   TIMING: 11 AM TO 02 PM & 03 PM TO 05 PM        ";
gotoxy(5,9);	cout<<"#   SHOP WILL CLOSED ON TUESDAY.      ";
gotoxy(5,10);	cout<<"#   GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED.      ";
gotoxy(5,11);	cout<<"#   TAKE YOUR SMART CARD WITH YOU.     ";
gotoxy(5,12);	cout<<"#   COLLECT YOUR SMART CARD & BILL AFTER PAYMENT.     ";
gotoxy(5,13);	cout<<"#   DO NOT BREAK ANY SHOP ITEMS.      ";
gotoxy(5,14);	cout<<"#   FOR ANY COMPLAINT CONTACT THE CHAIR PERSON.      ";
gotoxy(5,15);	cout<<"#   25 YEARS OF EXPERIENCE.       ";
gotoxy(5,16);	cout<<"#   CHAIR PERSON :- RUPESH BORSE    ";
gotoxy(5,17);	cout<<"#   AN ISO 9001-2000 CERTIFIED COMPANY.  ";
gotoxy(5,18);	cout<<"#   WELL QUALIFIED STAFF MEMBERS. ";
gotoxy(5,19);	cout<<"#   website :- www.rog_computers.com  ";
gotoxy(5,20);	cout<<"#   Email :- rog@gmail.com";
textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
		getch();
		clrscr();
		   goto again;
			case '4':
			do{
			clrscr();
		
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}
gotoxy(9,4);cout<<"***************";
gotoxy(9,5);	cout<<"* SELLER VIEW *";
gotoxy(9,6);	cout<<"***************";
gotoxy(5,8);	cout<<"#   TIMING: 11 AM TO 02 PM & 03 PM TO 05 PM        ";
gotoxy(5,9);	cout<<"#   SHOP WILL CLOSED ON TUESDAY.      ";
gotoxy(5,10);	cout<<"#   IN SELLER VIEW ONLY SELLER CAN INTER INIT .      ";
gotoxy(5,11);	cout<<"#   SELLER VIEW MENU HAVE A PASSWORD ONLY SELLER NO IT. ";
gotoxy(5,12);	cout<<"#   website :- www.rog_computers.com  ";
gotoxy(5,13);	cout<<"#   Email :- rog@gmail.com";
textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
		clrscr();
	
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}
		textcolor(YELLOW);
		delay(500);
    /*	 ******************** W E L C O M E********************* */
	gotoxy(19,5);
cputs("*********************************************");
	gotoxy(19,6);
cputs("********** SELLER VIEW (COMPUTER) ***********");
	gotoxy(19,7);
cputs("*********************************************");
	gotoxy(30,9);
	cout<<"Today is ::"<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon+1<<"/"<<nowlocal.tm_year+1900;
    gotoxy(30,10);
	cout<<"Time.    ::"<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<":"<<nowlocal.tm_sec;
    gotoxy(28,15);
	cout<<"Enter your Password :: ";
	str[0]=getch();
	cout<<"*";
	str[1]=getch();
	cout<<"*";
	str[2]=getch();
	cout<<"*";
	str[3]=getch();
	cout<<"*";
	str[4]=getch();
	cout<<"*";
	str[5]=getch();
	cout<<"*";
	str[6]=getch();
	cout<<"*";
	str[7]='\0';
	cout<<"*";
	if(strcmp(str,"seller0")==0)
	{
	clrscr();
		gotoxy(22,5);
	cout<<"!!PLEASE WAIT WHILE LOADING THE PROJECT!!";

		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}
	delay(500);
	gotoxy(30,12);
	cout<<"LOADING....";
	int u=0;
	for(int i=1;i<=10;i++)
	{
		gotoxy(30+u,13);
		delay(500);
		cout<<"";
		u=u+2;
		gotoxy(52,13);
		cout<<i<<"0%";
	}
	gotoxy(35,14);
	cout<<"COMPLETE ";
	delay(200);
	cout<<"!";
	delay(200);
	cout<<"!";
	delay(300);
	gotoxy(50,22);
	cout<<"\n\n";
	textcolor(LIGHTCYAN+BLINK);
	gotoxy(42,23);
	cputs("PRESS ENTER TO CONTINUE!!!!!!");
	getch();
lic:;
textcolor(YELLOW);
	clrscr();

		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}


gotoxy(31,4);cout<<"***************";
gotoxy(31,5);	cout<<"* SELLER VIEW *";
gotoxy(31,6);	cout<<"***************";
gotoxy(28,8);	cout<<"1)READ      ";
gotoxy(28,9);	cout<<"2)DELETE   ";
gotoxy(28,10);	cout<<"3)UPDATE     ";
gotoxy(28,11);  cout<<"4) SEARCH";
gotoxy(28,12);  cout<<"5)EXIT TO MEUN";
gotoxy(27,14);	cout<<"INTER YOUR CHOICE SELLER  == ";
cin>>seller;
if(seller==1)
{
clrscr();//TO DISPLAY ALL SAVED RECORDS
		read();
		getch();
		
		goto lic;
}
else if(seller==2)
{
		//TO DELETE THE RECORDS
 
		clrscr();
		del();
		getch();
		goto lic;
}
else if(seller==3)
{
	//TO MODIFY THE RECORDS
 
		clrscr();
		update();
		getch();
		goto lic;
}
else if(seller==4)
{
	//TO SEARCH THE RECORDS
 
		clrscr();
		search();
		getch();
		goto lic;
}
else if(seller==5)
{ goto again;

}
else if(seller!=1||seller!=2||seller!=3||seller!=4||seller!=5)
		{
gotoxy(28,15);	cout<<"OOPS!!!!!!!  Wrong choice";
goto lic;
		}}
else
{
clrscr();
	gotoxy(12,5);
cputs("***************!!YOUR PASSWORD IS WRONG!!***************");
	gotoxy(32,7);
cputs("!!TRY AGAIN!!");
	gotoxy(20,10);
cputs(" PLEASE PRESS 1. TO TRY AGAIN.");
	gotoxy(20,12);
cputs(" PLEASE PRESS 2. TO GO BACK.");
	gotoxy(32,16);
cputs(" CHOICES=");
cin>>ch3;
if(ch3==2)
{
clrscr();
goto again;
}
else 
{
gotoxy(25,20);	cout<<"OOPS!!!!!!!  Wrong choice !!!!! EXIT";
}
}
}while(ch3==1);		

	case '5':
clrscr();

	for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,1);
			if(pi%2==0)
				cout<<"";
			else	cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(1,pi);
			cout<<"";
			delay(5);
		}
		for(pi=2;pi<80;pi++)
		{
			gotoxy(pi,25);
			if(pi%2==0)
				cout<<"";
			else    cout<<" ";
			delay(5);
		}
		for(pi=2;pi<25;pi++)
		{
			gotoxy(80,pi);
			cout<<"";
			delay(5);
		}
		if(m>0||n>0||o>0||p>0||q>0||r>0||s>0||t>0||u>0||v>0)
		{
gotoxy(15,5);		cout<<"Items Avaliable in shop.";
gotoxy(15,7);		cout<<"==============================================";
gotoxy(15,8);	    cout<<"ITEMS"            <<setw(40)<<"QUANTITY";
gotoxy(15,9);		cout<<"==============================================";
gotoxy(15,10);		cout<<"PENDRIVE"            <<setw(37)<<abis;
gotoxy(15,11);		cout<<"SCANNER"             <<setw(38)<<apep;
gotoxy(15,12);		cout<<"PRINTER"             <<setw(38)<<aden;
gotoxy(15,13);	    cout<<"WEBCAM"              <<setw(39)<<amun;
gotoxy(15,14);		cout<<"GRAPHIC CARD"        <<setw(33)<<aperk;
gotoxy(15,15);		cout<<"RAM"                 <<setw(42)<<acoc;
gotoxy(15,16);		cout<<"HARD DISK"           <<setw(35)<<atit;
gotoxy(15,17);		cout<<"WINDOWS ORIGINAL CD" <<setw(26)<<alux;
gotoxy(15,18);		cout<<"ANTIVIRUS"           <<setw(36)<<atid;
gotoxy(15,19);		cout<<"MOUSE"               <<setw(40)<<aree;
gotoxy(15,20); 		cout<<"***********************************************";
		getch();
		goto again;
		}
		else
		{
		
gotoxy(15,5);		cout<<"Items Avaliable in shop.";
gotoxy(15,7);		cout<<"=============================================";
gotoxy(15,8);		cout<<"ITEMS"            <<setw(40)<<"QUANTITY";
gotoxy(15,9);		cout<<"=============================================";
gotoxy(15,10);		cout<<"PENDRIVE"             <<setw(37)<<1000;
gotoxy(15,11);		cout<<"SCANNER"              <<setw(38)<<1000;
gotoxy(15,12);		cout<<"PRINTER"        	   <<setw(37)<<110;
gotoxy(15,13);		cout<<"WEBCAM"               <<setw(39)<<1000;
gotoxy(15,14);		cout<<"GRAPHIC CARD"         <<setw(32)<<500;
gotoxy(15,15);		cout<<"RAM"                  <<setw(41)<<400;
gotoxy(15,16);		cout<<"HARD DISK"            <<setw(35)<<100;
gotoxy(15,17);		cout<<"WINDOWS ORIGINAL CD"  <<setw(26)<<1000;
gotoxy(15,18);		cout<<"ANTIVIRUS"            <<setw(36)<<1000;
gotoxy(15,19);		cout<<"MOUSE"                <<setw(39)<<300;
gotoxy(15,20);		cout<<"***********************************************";
		getch();
		goto again;
		}
			case '6': exit(0);
		};
	}while(ch!='6');
}else
{
clrscr();
	gotoxy(12,5);
cputs("***************!!YOUR PASSWORD IS WRONG!!***************");
	gotoxy(32,7);
cputs("!!TRY AGAIN!!");
	gotoxy(20,10);
cputs(" PLEASE PRESS 1. TO TRY AGAIN.");
	gotoxy(20,12);
cputs(" PLEASE PRESS 2. TO GO BACK.");
	gotoxy(32,16);
cputs(" CHOICES=");
cin>>ch1;
}
}
while(ch1==1);
getch();
return;

}
//***************************************************************
//		END OF PROJECT
//***************************************************************
