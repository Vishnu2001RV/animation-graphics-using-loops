
      


#include<graphics.h>
#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include “BIT.cpp”

int g=0;
  void intro1()
 {
	/* request auto detection */
	int gdriver = DETECT, gmode;
	int  radius = 5, k = 0;
	/* initialize graphic mode */
	initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
  
	setcolor(BLUE);
	while (k <= 90) {
		/* creating waves using arcs with specific angles */
		arc(0, 0, 270, 360, radius);
		arc(getmaxx(), 0, 180, 270, radius);
		arc(0, getmaxy(), 0, 90, radius);
		arc(getmaxx(), getmaxy(), 90, 180, radius);
		radius = radius + 5;
		delay(50);
		k++;
	}
  }
void intro2()
{ clrscr();
 int gd = DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 int x = 300;int i=0;
 setfillstyle(2,RED);
 for(i=0;i<100;i++)
 {
    delay(50);
    setfillstyle(2,i);
    bar(x-i,230-i,x+30-i,200-i);//vishnu up -
    bar(x+i,230-i,x+30+i,200-i);//vishnu down +
    bar(200-i,x+i,200-i,x+20);//for the 3d split
    i++;
    if(i==99)
    {  settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
    outtextxy(100,50,"   Bank Management Program ");
    outtextxy(190,300,"1-Vishnu-RV");

    getch();
    }
 }
}
void loading1()
{
 clrscr();
 textcolor(RED);
 clrscr();
 gotoxy(30,12);
 cout<<"LOADING....";
 int x=0;
 for(int i=1;i<=10;i++)
 {
  gotoxy(30+x,13);
  delay(400);
  textcolor(GREEN);
  cprintf("%c",178);
  x=x+2;
  gotoxy(52,13);
  cout<<i<<"0%";
  }
  gotoxy(35,14);
  cout<<" ACCOUNT CREATED";
  delay(200);
  cout<<"!!!!";
  delay(200);
  delay(300) ;
  gotoxy(55,21);
  cout<<"PRESS ANY KEY TO CONTINUE";
  getch();
  clrscr();

  }
void loading2()
{
 int x,y,i;
 int g=DETECT, d;
 initgraph(&g, &d,"C:\\TC\\BGI");
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 int c=150;
 for(int e=0;e<15;e++) //Change 15 to your desired value
 {
     for(int i=50;i<65;i++)
    {  delay(11);
      cleardevice();
      setcolor(i);
      settextstyle(SMALL_FONT, HORIZ_DIR, 10);
      delay(5);
      outtextxy(x,y,"Loading...");
      delay(5);
      settextstyle(SMALL_FONT, HORIZ_DIR, 5);
      outtextxy(x+5,y+5,"Please Wait... ");
      circle(x,y,i);
      circle(x,y,c);
      c--;
    }
  }
 outtextxy(400,400,"PRESS ENTER");
 getch();
 }
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	int deposit;
	char type;
public:
		 char name[25],address[25],dob[25];
		 struct date d,e;
		 struct time t;
          int hour,min,sec,year,mon,day;
          void create_account();//function to get data from user
	void show_account();	//function to show data on screen
	void modify();   //function to get new data from user
	void dep(int);	  //function to accept amount and add to balance amount
	void draw(int);  //function to accept amount and subtract from balance amount:
	void report();	  //function to show data in tabular format
	int retacno();	  //function to return account number
	int retdeposit(); //function to return balance amount
	char rettype();
	int retdate(int p);//function to return type of account
	char retname();
	char *retdob();
};          //class ends here
char *account::retdob()
{return dob;
}
void account::create_account()
{   		         playagain:
		       	acno=-350;
                             int gd = DETECT,gm;  
 			 initgraph(&gd,&gm,"C:\\TC\\BGI");
			 int x = 300;int i=0;
			 for(i=2;i<100;i+=1)
			   { 	setfillstyle(2,i);
				 bar(x-i-50,100-i,x-50+30-i,150-i);//vishnu up -
				 bar(x+i-50,100-i,x-50+30+i,150-i);//vishnu down +
				 bar(300-i,x+i,300-i,x+20);//for the 3d split
			 }
				  outtextxy(210,10,"CREATING A ACCOUNT");
				  outtextxy(10,150,"Enter The account No                   ::");

			          see:
				 gotoxy(70,10);
				 cin>>acno;
				 if(acno==-350)
				 goto see;
			          account ac0;
			          ifstream inFile0;
							    inFile0.open("account.dat",ios::binary|ios::in|ios::out);


 while(inFile0.read((char *) &ac0, sizeof(account)))
   {     if(ac0.retacno()==acno)
         {clrscr();
	outtextxy(30,400,"Enter new acc no which is not used");
         goto playagain;
  }
  }
   inFile0.close();
   outtextxy(10,180,"Enter The Name of The account Holder                  ::");
   gotoxy(70,12);
   scanf("%s",name);
   outtextxy(10,210,"Enter Type of The account (C-current/S-savings)       :: ");
   gotoxy(70,14);
   cin>>type;
   outtextxy(10,245,"Enter the address                                     ::");
   gotoxy(70,16);
   scanf("%s",address);
   outtextxy(10,275,"Enter The date of birth                               :: ");
   gotoxy(70,18);
   scanf("%s",dob);
   outtextxy(10,310,"Enter The  amount to be deposited (>=1000 & <99999)   ::");
   vishnu:
   gotoxy(70,20);
   cin>>deposit;
    if(deposit<1000)
	      { gotoxy(70,20);
                  cout<<"      " ;
	        goto vishnu;
                }
	    getdate(&d);
	    gettime(&t);
	    getdate(&e);
              getch();
   closegraph();
  loading1();
}
void account::show_account()
{				  int gd = DETECT,gm;
				  initgraph(&gd,&gm,"C:\\TC\\BGI");
				  char arr[50];
				  int x = 300;int i=0;
				  for(i=2;i<100;i+=1)
				  {


				 setfillstyle(2,i);
				 bar(x-i-50,100-i,x-50+30-i,150-i);//vishnu up -
				 bar(x+i-50,100-i,x-50+30+i,150-i);//vishnu down +
				 bar(300-i,x+i,300-i,x+20);//for the 3d split


				 }
				  outtextxy(230,10,"BANK INFO");
				  outtextxy(10,140,"Account No                          ::");
				  sprintf(arr,"%d",acno);
				  outtextxy(400,140,arr);
               			  outtextxy(10,160,"Account Holder Name                 ::");
          			  outtextxy(400,160,name);
			           outtextxy(10,180,"Type of Account                     ::");
				  gotoxy(51,12);
			           cout<<type;
				 outtextxy(10,200,"The address of Account Holder       :: ");
			           outtextxy(400,200,address);
			           outtextxy(10,220,"The date of birth of Account Holder ::");
			           outtextxy(400,220,dob);
			           outtextxy(10,240,"Balance amount                      ::");
			 	 sprintf(arr,"%d",deposit);
				 outtextxy(400,240,arr);
			 	 outtextxy(10,260,"Account created on                  :: ");
				 sprintf(arr,"%d:%d:%d",d.da_day,d.da_mon,d.da_year);
				 outtextxy(400,260,arr);
				 outtextxy(10,280,"LAST SEEN ON                        :: ");
				 sprintf(arr,"%d:%d:%d",e.da_day,e.da_mon,e.da_year);
				 outtextxy(400,280,arr);
				 outtextxy(10,300,"TIME                                :: ");
				 sprintf(arr,"%d:%d:%d",t.ti_hour,t.ti_min,t.ti_sec);
				 outtextxy(400,300,arr);
                   			 getch();
				closegraph();
}

void account::modify()
{

				  int gd = DETECT,gm;
				  initgraph(&gd,&gm,"C:\\TC\\BGI");
				  char arr[50];
				  int x = 300;int i=0;
			           for(i=2;i<100;i+=1)
				  {
				 setfillstyle(2,i);
				 bar(x-i-50,100-i,x-50+30-i,150-i);//vishnu up -
				 bar(x+i-50,100-i,x-50+30+i,150-i);//vishnu down +
				 bar(300-i,x+i,300-i,x+20);//for the 3d split
				 }
	  outtextxy(10,100,"THE ACCOUNT NO IS                                              :: ");
	  gotoxy(70,7);
	  scanf("%d",&acno);
           outtextxy(10,132,"ENTER THE NAME OF ACCOUNT HOLDER                   :: ");
	  gotoxy(70,9);
	  scanf("%s",name);
	  outtextxy(10,164,"Enter Type of The account (CURRENT/SSAVINGS)           :: ");
	  gotoxy(70,11);
	  cin>>type;
	  type=toupper(type);
	  outtextxy(10,196,"Enter The amount                                               :: ");
	  gotoxy(70,13);
	  cin>>deposit;
	  outtextxy(10,228," enter the new address                                         :: ");
	  gotoxy(70,15);
	  cin>>address;
	  outtextxy(10,260,"Enter The new date of birth                                    :: ");
	  gotoxy(70,17);
	  cin>>deposit;

		 gettime(&t);
		 getdate(&e);
		 closegraph();
}


void account::dep(int x)
{
		gettime(&t);
		getdate(&e);
	         deposit+=x;
}

void account::draw(int x)
{                gettime(&t);
	       getdate(&e);
	       deposit-=x;
}

void account::report()
{
  char arr5[50];
  sprintf(arr5,"%d",acno);
  outtextxy(10,120+g,arr5);
  outtextxy(100,120+g,name);
  outtextxy(190,120+g,address);
  sprintf(arr5,"%d ",deposit);
  outtextxy(380,120+g,"$");
  outtextxy(310,120+g,arr5);
  sprintf(arr5,"%s",dob);
  outtextxy(445,120+g,arr5);
}

int account::retacno()
{
	return acno;
}
int account::retdeposit()
{
	return deposit;
}
char account::rettype()
{
	return type;
}
int  account::retdate(int p)
{ switch(p)
 { case 1 :
	       return e.da_day;
   case 2 :
	       return e.da_mon;
   case 3 :
		return d.da_year;
   
  case 4 :  return t.ti_hour;
 
   case 5 :  return t.ti_min;

   case 6 :   return t.ti_sec;

 }

 return 0;
}



//***************************************************************
//    	function declaration
//****************************************************************
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
	                                                    char ch;
	                                                    int num;
	                                                    clrscr();
	                                                    intro1();
                                                              intro2();
                                                              star();
	                                                    imp:


				  int gd = DETECT,gm;
				  initgraph(&gd,&gm,"C:\\TC\\BGI");
				  int x = 300;int i=0;
				  for(i=0;i<100;i+=1)
				  {
				 delay(25);
				 setfillstyle(2,i);
				 bar(x-i,130-i,x+30-i,100-i);//vishnu up -
				 bar(x+i,130-i,x+30+i,100-i);//vishnu down +
				 bar(100-i,x+i,100-i,x+20);//for the 3d split
				 }
				  settextstyle(2,HORIZ_DIR,6);
				  setcolor(WHITE);
				  outtextxy(10,115,"MAIN MENU");
				  outtextxy(10,130,"***************");
				  outtextxy(10,160,"01.NEW ACCOUNT");
				  outtextxy(10,180,"02. DEPOSIT AMOUNT");
				  outtextxy(10,200,"03. WITHDRAW AMOUNT");
				  outtextxy(10,220,"04. BALANCE ENQUIRY AND ACCOUNT INFORMATION");
				  outtextxy(10,240,"05. ALL ACCOUNT HOLDER LIST");
				  outtextxy(10,260,"06. CLOSE AN ACCOUNT");
				  outtextxy(10,280,"07. MODIFY AN ACCOUNT");
				  outtextxy(10,300,"08. EXIT");
				  outtextxy(200,330,"Select Your Option (1-8) ");
                             	  gotoxy(10,25);
				  scanf("%c",&ch);
		clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			  int gd8 = DETECT,gm8;
			  initgraph(&gd8,&gm8,"C:\\TC\\BGI");
		 int x = 600; i=0;
		for(i=2;i<100;i+=1)
			 {
			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
			  }
            	 outtextxy(50,390,"Enter The account No. ::");
		 gotoxy(50,25);
		 cin>>num;
		 deposit_withdraw(num, 1);
		break;
		case '3':

		            int gd5 = DETECT,gm5;
			  initgraph(&gd5,&gm5,"C:\\TC\\BGI");
		            x = 600; i=0;
	             	  for(i=2;i<100;i+=1)
			 {


			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
			  }
		outtextxy(50,390,"Enter The account No. : :");
	         gotoxy(50,25);
	         cin>>num;
		deposit_withdraw(num, 2);
		break;
		case '4':
	                   int gd12 = DETECT,gm12;
                 		initgraph(&gd12,&gm12,"C:\\TC\\BGI");
		         x = 600; i=0;
		         for(i=2;i<100;i+=1)
			 {
			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
			  }
	                          outtextxy(50,390,"Enter The account No. : :");
			       gotoxy(50,25);
			       cin>>num;
			       display_sp(num);
			       break;
		case '5':
			display_all();
			break;
		case '6':
				   int gd13 = DETECT,gm13;
			            initgraph(&gd13,&gm13,"C:\\TC\\BGI");
				  x = 600; i=0;
				  for(i=2;i<100;i+=3)
			 {
			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
			  }
			       outtextxy(50,390,"Enter The account No. : :");
			       gotoxy(50,25);
			       cin>>num;

			    delete_account(num);
			   getch();
			   break;
		 case '7':
				   int gd14 = DETECT,gm14;
	 		            initgraph(&gd14,&gm14,"C:\\TC\\BGI");
				  x = 600; i=0;
				  for(i=2;i<100;i+=1)
			 {
			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
			  }
				outtextxy(50,390,"Enter The account No. : :");
				gotoxy(50,25);
				cin>>num;
				modify_account(num);
			break;
		 case '8':
                                          star();
				   int gd16 = DETECT,gm16;
           			  initgraph(&gd16,&gm16,"C:\\TC\\BGI");
				  x = 600; i=0;
				  for(i=2;i<100;i+=1)
			 {
			 setfillstyle(2,i);
			 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
			 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
			 bar(300-i,x+i,300-i,x+20);//for the 3d split
 			  }
		     cout<<"\n\n\tThanks for using bank managemnt system";
           	     break;
		 default :cout<<"\a";
		}
	 if(ch!='8')
	goto imp;//loop
		 getch();
		 closegraph();
		 getch();
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
       //	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{       loading2();
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	File.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
		if(ac.retacno()==n)
		{gotoxy(66,15);
		 cout<<"account deleted";
		}
	}

	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");

}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{                                                                      bank1:

				  int gd = DETECT,gm;
				  initgraph(&gd,&gm,"C:\\TC\\BGI");
				  int x = 300;int i=0;
				   for(i=0;i<100;i+=1)
				  {


				 setfillstyle(2,i);
				 bar(x-i,130-i,x+30-i,100-i);//vishnu up -
				 bar(x+i,130-i,x+30+i,100-i);//vishnu down +
				 bar(100-i,x+i,100-i,x+20);//for the 3d split


				 }

				  setcolor(WHITE);
				  outtextxy(10,115,"SUB MENU");
				  outtextxy(10,130,"***************");
				  outtextxy(10,160,"@@@@      DO YOU WISH TO CHEK THE ACCOUNT REGISTERED      @@@");
				  outtextxy(10,180,"1-WITHIN THE GIVEN DATES");
				  outtextxy(10,200,"2-AT THE GIVEN DATES");
				  outtextxy(10,220,"3-BY ACCOUNT HOLDER NAME");
				  outtextxy(10,240,"4-BY DATE OF BIRTH");
				  outtextxy(10,260,"5-OR DISPLAY THE BANK RECORDS");
				  outtextxy(10,300,"6-  EXIT");
				  outtextxy(200,330,"Select Your Option (1-8) ");
		gotoxy(10,25);
				  int o;
				  cin>>o;
				  if(o==6)
				  {goto bank;}

      switch(o)
      {

      case 1:
		 int y1,y2,m1,m2,d1,d2;
		 int gd3 = DETECT,gm3;
		 initgraph(&gd3,&gm3,"C:\\TC\\BGI");
		 int  x = 600;int  i=0;
		for(i=2;i<100;i+=1)
	  {
	 setfillstyle(2,i);
	 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
	 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
	 bar(300-i,x+i,300-i,x+20);//for the 3d split
	 }
		 outtextxy(50,390,"Enter the dates within which the account  was updated");
		 gotoxy(70,25);
		 cin>>y1;
	          outtextxy(570,388,"/");
		gotoxy(73,25);
		cin>>m1;
	         outtextxy(595,388,"/");
		gotoxy(76,25);
		cin>>d1;
		gotoxy(70,25);cout<<"  ";
		gotoxy(73,25);cout<<"  ";
		gotoxy(76,25);cout<<"    ";
		gotoxy(70,25);
		cin>>y2;
           	gotoxy(73,25);
		cin>>m2;
		gotoxy(76,25);
		cin>>d2;
		account ac1;
	ifstream inFile1;
	inFile1.open("account.dat",ios::binary);
	if(!inFile1)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
		 outtextxy(0,50,"==========================================================");
		 outtextxy(0,100,"==========================================================");
		 outtextxy(10,75,"A/C no.     NAME       ADDRESS       BALANCE         DOB");
		 outtextxy(520,200,"BANK DETAILS") ;
	while(inFile1.read((char *) &ac1, sizeof(account)))
	{                 if(ac1.retdate(1)>y1&&ac1.retdate(1)<y2||ac1.retdate(1)==y1||ac1.retdate(1)==y2)
{
if(ac1.retdate(2)>m1&&ac1.retdate(2)<m2||ac1.retdate(2)==m1||ac1.retdate(2)==m2)
 {
if(ac1.retdate(3)>d1&&ac1.retdate(3)<d2||ac1.retdate(3)==d1||ac1.retdate(3)==d2)
				     { ac1.report();
				      g+=25;}
  }
}

	}
                  g=0;
                  inFile1.close();
                  getch();
		 closegraph();
   		 break;
      case 2:
		 int gd4 = DETECT,gm4;
		 initgraph(&gd4,&gm4,"C:\\TC\\BGI");
		  x = 600; i=0;
		for(i=2;i<100;i+=1)
	  {
	 setfillstyle(2,i);
	 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
	 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
	 bar(300-i,x+i,300-i,x+20);//for the 3d split
	 }
		 int ay1,am1,ad1;
		 outtextxy(50,390,"Enter the date  to find the account accessed  that day:");
		 gotoxy(70,25);
 		 cin>>ay1;
		 outtextxy(570,388,"/");
		 gotoxy(73,25);
		 cin>>am1;
		 outtextxy(595,388,"/");
		 gotoxy(76,25);
		 cin>>ad1;
		 account ac2;
	          ifstream inFile3;
	inFile3.open("account.dat",ios::binary);
	if(!inFile3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
		 outtextxy(0,50,"==========================================================");
		 outtextxy(0,100,"==========================================================");
outtextxy(10,75,"A/C no.     NAME       ADDRESS       BALANCE         DOB");
outtextxy(520,200,"BANK DETAILS") ;
	while(inFile3.read((char *) &ac2, sizeof(account)))
	{              if(ac2.retdate(1)==ay1)
			{if(ac2.retdate(2)==am1)
			{if(ac2.retdate(3)==ad1)
				     ac2.report();
				     g+=25;
		       }
  		       }

	 }
	g=0;
	inFile3.close();
		   getch();
		   closegraph();
		   break;
 case 3 :

          int gd1 = DETECT,gm1;
	initgraph(&gd1,&gm1,"C:\\TC\\BGI");
	x = 600; i=0;
	for(i=2;i<100;i+=1)
	  {
	 setfillstyle(2,i);
	 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
	 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
	 bar(300-i,x+i,300-i,x+20);//for the 3d split
	 }
	char name1[25];
	account ac6;
	ifstream inFile6;
   outtextxy(50,390,"ENTER THE NAME WHOSE ACCOUNT IS TO BE SEARCHED:");
   gotoxy(70,25);
   cin>>name1;
   inFile6.open("account.dat",ios::binary|ios::in);
   if(!inFile6)
   {
		cout<<"File could not be open !! Press any Key...";
		return;
   }
		 outtextxy(0,50,"==========================================================");
		 outtextxy(0,100,"==========================================================");
outtextxy(10,75,"A/C no.     NAME       ADDRESS       BALANCE         DOB");
outtextxy(520,200,"BANK DETAILS") ;

while(inFile6.read((char *) &ac6, sizeof(account)))
	{
		if(strcmp(ac6.name,name1)==0)
		ac6.report();

	}
	inFile6.close();
				   getch();
				   closegraph();
		 break;
     case 4:

	 int gd2 = DETECT,gm2;
	initgraph(&gd2,&gm2,"C:\\TC\\BGI");
         x = 600;i=0;
	for(i=2;i<100;i+=1)
	  {
	 setfillstyle(2,i);
	 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
	 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
	 bar(300-i,x+i,300-i,x+20);//for the 3d split
	 }

         char dob1[25];
	account ac7;
	ifstream inFile7;
	outtextxy(50,390,"Enter the date of birth of the account holder to be searched");
	gotoxy(70,25);
	cin>>dob1;
	inFile7.open("account.dat",ios::binary|ios::in);
	if(!inFile7)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
		 outtextxy(0,50,"==========================================================");
		 outtextxy(0,100,"==========================================================");
		 outtextxy(10,75,"A/C no.     NAME       ADDRESS       BALANCE         DOB");
		 outtextxy(520,200,"BANK DETAILS") ;
	while(inFile7.read((char *)&ac7, sizeof(account)))
	{          if(strcmpi(ac7.retdob(),dob1)==0)
		  { ac7.report();
		     g+=25;
		  }
       }g=0;
    inFile7.close();
              getch();
              closegraph();
              break;
     case 5:
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
		x = 600; i=0;
		for(i=2;i<100;i+=1)
	  {
	 setfillstyle(2,i);
	 bar(x-i-50,300-i,x-50+30-i,350-i);//vishnu up -
	 bar(x+i-50,300-i,x-50+30+i,350-i);//vishnu down +
	 bar(300-i,x+i,300-i,x+20);//for the 3d split
	 }
		 outtextxy(0,50,"==========================================================");
		 outtextxy(0,100,"==========================================================");
		 outtextxy(10,75,"A/C no.     NAME       ADDRESS       BALANCE         DOB");
		 outtextxy(520,200,"BANK DETAILS") ;
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		outtextxy(400,400,"File could not be open !! Press any Key...");
		return;
	}

	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
		 g+=25;
	}
	inFile.close();
		 g=0;
		 getch();
		 closegraph();
		 break;
       }
       goto bank1;
       bank :
       closegraph();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{

			if(option==1)
			{

          		       outtextxy(520,200,"DEPOSITE AMOUNT") ;
			       outtextxy(50,100,"Enter The amount to be deposited:");
  			         gotoxy(70,15);
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
			outtextxy(520,200,"WITHDRAW AMOUNT") ;
			outtextxy(50,100,"Enter The amount to be withdraw:");


				gotoxy(70,15);
				cin>>amt;
		int bal=ac.retdeposit()-amt;
		if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
 	         outtextxy(50,410,"Insufficience balance:");
		else
		ac.draw(amt);
		}
		int pos=(-1)* sizeof(ac);
		File.seekp(pos,ios::cur);
		File.write((char *) &ac, sizeof(account));
		outtextxy(50,430," Record Updated:");
		getch();
		found=1;
	       }
	}
	File.close();
	if(found==0)
	outtextxy(50,50,"record ot found");

}
//***************************************************************
//    			END OF PROJECT
//********************************************************
