#include<iostream>
using namespace std;
int i=0,j=0,p=0,q=0,n=0,g=0,h=0;
struct addr{
	string name;
	string fathername;
	string place;
	string phoneno;
	string gender;
	string email; 
};
struct addr record[1000];
int addrecord()
{
	char c;
				cout<<"                 ********************************\n";
				cout<<"                 ******WELCOME TO ADD MENU*******\n";
				cout<<"                 ********************************\n\n\n";
				cout<<"enter name: ";
				cin.get();
				getline(cin,record[i].name);
				for(int k=0;k<i;k++)
				{
					if(record[k].name==record[i].name)
					{
						cout<<"name already exists\ntry another name....\n";
						addrecord();
					}
				}	
				cout<<"enter father name : ";
				getline(cin,record[i].fathername);
				cout<<"enter place : ";
				getline(cin,record[i].place);
				cout<<"enter phone number : ";
				getline(cin,record[i].phoneno);
				cout<<"enter gender : ";
				getline(cin,record[i].gender);
				cout<<"enter email : ";
				getline(cin,record[i].email);
				cout<<"    your record is added  :)\n";
				i++;
				cout<<"do you want to add another record? (y/n) : ";
				cin>>c;
				if(c=='y')
				{
					addrecord();
				}
				return 0;
}
int view()
{
	if(i==0)
	{
		cout<<"no records to view\n";
		return 0;
	}
	char a;
	string name_p;
	cout<<"enter name :  ";
	cin>>name_p;
	for(int k=0;k<=i;k++)
	{
		if(record[k].name==name_p)
		{
			cout<<"\nwhole record of  "<<record[k].name<<" is :";
			cout<<"\nFATHER NAME : "<<record[k].fathername<<endl;
			cout<<"PLACE : "<<record[k].place<<endl;
			cout<<"PHONE NUMBER : "<<record[k].phoneno<<endl;
			cout<<"GENDER : "<<record[k].gender<<endl;
			cout<<"E-MAIL ADDRESS : "<<record[k].email<<endl;
			h=1;
		}
	}			
	if(!h)
	cout<<"no such record\n";
	cout<<"WOULD YOU LIKE TO VIEW AGAIN : {y/n} ";
	cin>>a;	
	if(a=='y')
	view();
	else
	return 0;
}
int edit()
{
		if(i==0)
	{
		cout<<"no records to edit\n";
		return 0;
	}
	int choice,c=0;
	string name_p,newly;
	cout<<"enter name of the record you want to edit :";
	cin>>name_p;
	for(int k=0;k<=i;k++)
	{
		if(record[k].name==name_p)
		{
			cout<<"\nwhole record of  "<<record[k].name<<" is :";
			cout<<"\nFATHER NAME : "<<record[k].fathername<<endl;
			cout<<"PLACE : "<<record[k].place<<endl;
			cout<<"PHONE NUMBER : "<<record[k].phoneno<<endl;
			cout<<"GENDER: "<<record[k].gender<<endl;
			cout<<"E-MAIL : "<<record[k].email<<endl;
			cout<<"which aspect you would like to change : \n1.name\n2.fathername\n3.place\n4.phone number\n5.genner\n6.e-mail\n7.quit\n";
			cout<<"enter your choice : ";
			cin>>choice;
			switch(choice)
			{
				case 1:{
					cout<<"enter name : ";
					cin>>newly;
					record[k].name=newly;
					break;
				}
				case 2:{
					cout<<"enter father name ";
					cin>>newly;
					record[k].fathername=newly;
					break;
				}
				case 3:{
					cout<<"enter place : ";
					cin>>newly;
					record[k].place=newly;
					break;
				}
				case 4:{
					cout<<"enter phone number : ";
					cin>>newly;
					record[k].phoneno=newly;
					break;
				}
				case 5:{
					cout<<"enter gender : ";
					cin>>newly;
					record[k].gender=newly;
					break;
				}
				case 6:{
					cout<<"enter e-mail : ";
					cin>>newly;
					record[k].email=newly;
					break;
				}
				case 7:{
					
					return 0;
				}
				default:
					cout<<"invalid input\n";
				
			}
			c=1;	
		}
	}
	if(!c)
	cout<<"no such record"<<endl;
	cout<<"WOULD YOU LIKE TO EDIT ANY OTHER RECORD : {y/n} : ";
	char a;
	cin>>a;
	if(a=='y')
	edit();
	else 
	return 0;
}
int deleter()
{
		if(i==0)
	{
		cout<<"no records to delete\n";
		return 0;
	}
	int v,c=0;
	char a;
	string name_p;
					cout<<"enter name : ";
					cin>>name_p;
					for(int k=0;k<=i;k++)
					{
						if(record[k].name==name_p)
						{
							for(int l=k;l<i;l++)
							{
								record[l].name=record[l+1].name;
								record[l].fathername=record[l+1].fathername;
								record[l].place=record[l+1].place;
								record[l].phoneno=record[l+1].phoneno;
								record[l].gender=record[l+1].gender;
								record[l].email=record[l+1].email;
								cout<<"record is deleted\n";
								c=1;
							}
							i--;
						}
					}	
				if(!c)
				cout<<"no such record"<<endl;
				cout<<"WOULD YOU LIKE TO DELETE ANY OTHER FILE : {y/n} ";
				cin>>a;	
				if(a=='y')
				deleter();
				else
				return 0;	
}
int main()
{
	int ch;
	cout<<"\n\n\n                             ************************\n";
	cout<<"                             -------PHONE BOOK-------\n";
	cout<<"                             ************************\n\n\n";
	do
	{
	
		cout<<"MAIN MENU\n\n";
		cout<<"1.ADD RECORD\n2.VIEW RECORD\n3.EDIT RECORD\n4.DELETE RECORD\n5.VIEW ALL RECORDS\n6.QUIT\n";
		cout<<"enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
			{
				addrecord();
				break;
			}
			case 2:{
				view();
				break;
			}
			case 3:{
				edit();
				break;
			}
			case 4:{
				deleter();
				break;
			}
			case 5:{
				if(i==0)
				cout<<"no records to view\n";
				else
				{
					for(int b=0;b<i;b++)
					{
						cout<<"\nNAME : "<<record[b].name<<" is :";
						cout<<"\nFATHER NAME : "<<record[b].fathername<<endl;
						cout<<"PLACE : "<<record[b].place<<endl;
						cout<<"PHONE NUMBER : "<<record[b].phoneno<<endl;
						cout<<"GENDER : "<<record[b].gender<<endl;
						cout<<"E-MAIL ADDRESS : "<<record[b].email<<endl;
					}
				}
				break;
			}
			case 6:{
				return 0;
			}
			default:
				cout<<"INVALID INPUT\n";
		}
		
	}while(ch!=6);
	return 0;
}
