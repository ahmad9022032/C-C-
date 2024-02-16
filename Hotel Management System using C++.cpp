#include<iostream>
#include<cmath>
#include<fstream>
#include<stdlib.h>
#include<ctime>

using namespace std;
double addition (int checkin)
{

	string cancel,pay;
	double bed, breakfast;
	
	cout<<"\nNo. of extra bed(1 bed = RM50/night): ";
	cin>>bed;
	cout<<endl;
	cout<<"no. of pax for breakfast(RM15/pax): ";
	cin>>breakfast;
	cout<<endl;
	cout<<"do you want free cancelation policy? (RM50) (yes/no): ";
      cin>>cancel;
	cout<<endl;
	cout<<"do you want to pay now or anytime between the current date and 3 days before the check in date? "<< endl;
	cout<<"if you pay 3 day before check in date,you will be charged a total of RM30 (yes/no)"<<endl;
	cin>>pay;
	double total= 0;
	bed = bed *50*checkin;
	if(cancel=="yes")
	{
		total+=50;
		//price 1 night
	}
	else if(cancel == "no")
	{
		total+=0;
	}
	
	if (pay == "yes")
	{
		total+=0;
	}
	else if (pay == "no")
	{
		total +=30;
	}
	
	total = total+bed+breakfast;
	return total;
}

void payment(double sum,double addf,string name,string address,string hpnum,int room,int people,int day1,int month1,int year1,int day2,int month2,int year2,int days)
{
	double tax = 0;
	double total = 0;
	tax = (sum+addf)*0.1;
	total=tax+sum+addf;
	
	string room_type;
	if(room == 1)
	{
		room_type="standard";
	}
	else if (room == 2)
	{
		room_type="deluxe";
	}
	
	
	cout <<"\t\t\t\t*************************\n"<<endl;
	cout <<"\t\t\t\t   SERENA HOTEL"<<endl;
	cout <<"\n\t\t\t\t*************************"<<endl<<endl;
	cout <<"name :"<<name<<endl;
	cout <<"address :"<<address<<endl;
	cout << "handphone number :"<<hpnum<<endl<<endl;
	cout<<"room \t\t\t: "<<room_type<<endl;
	cout<<"tenants \t\t: "<<people<<" people"<<endl;
	cout<<"check in \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
	cout<<"check out \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
	cout<<"duration stayed \t: "<<days<<endl<<endl;
	cout<<"room price \t\t: RM"<<sum<<endl;
	cout<<"additional fees \t: RM"<<addf<<endl;
	cout<<"service tax(10%)\t: RM"<<tax<<endl;
	cout<<"final total \t\t: RM"<<total<<endl<<endl;
	cout<<"thank you for booking with us! enjoy your stay!"<<endl;
	cout<<"for more informstion contact with me "<< endl;
	
	
	fstream myfile;
	myfile.open ("receipt.txt");
	myfile <<"\t\t\t\t*************************\n"<<endl;
	myfile <<"\t\t\t\t  SERENA HOTEL "<<endl;
	myfile <<"\n\t\t\t\t*************************"<<endl<<endl;
	myfile <<"name :"<<name<<endl;
	myfile <<"address :"<<address<<endl;
	myfile << "handphone number :"<<hpnum<<endl<<endl;
	myfile <<"room \t\t\t: "<<room_type<<endl;
	myfile <<"tenants \t\t: "<<people<<" people"<<endl;
	myfile <<"check in \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
	myfile <<"check out \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
	myfile <<"duration stayed \t: "<<days<<endl<<endl;
	myfile <<"room price \t\t: RM"<<sum<<endl;
	myfile <<"additional fees \t: RM"<<addf<<endl;
	myfile <<"service tax(10%)\t: RM"<<tax<<endl;
	myfile <<"final total \t\t: RM"<<total<<endl<<endl;
	myfile <<"thank you for booking with us! enjoy your stay!"<<endl;
	myfile <<"for more informstion contact with me "<< endl;
	
}

double date (int day1, int month1, int year, int day2, int month2, int year4)
{
	int i;
	double diffrence;
	month1-=1;
	month2-=1;
	struct tm a = {0,0,0,day1,month1,year};
	struct tm b = {0,0,0,day2,month2,year4};
	time_t x = mktime(&a);
	time_t y = mktime(&b);
	double days;
	if(x!= (time_t) (-1) && y!=(time_t) (-1) )
	{
		double diffrence = difftime(y,x)/ (60 * 60 * 24);
		//getting the diffrence in days
		cout<<ctime(&x);
		//convert time_t value to string(function)                                                    
		cout<<ctime(&y);
		cout<<"diffrence = " << diffrence << "days" << endl;
		days = diffrence;
	}
	cout<<days<<endl;
	return days;
}
int main()
{
	string name;
	string address;
	string hpnum;
	string add;
	int room;
	int people;
	int day1,month1,year1;
	int day2,month2,year2;
	int i,year,year4;
	
	start:
		
		cout<<"\n\t\t\t\t*************************";
		cout<<"\n\t\t\t\t HOTEL BOOKING SERVICE ";
		cout<<"\n\t\t\t\t      * MAIN MENU *";
		cout<<"\n\t\t\t\t*************************";
		
		cout<<"\nEnter the check in date:\n"<<endl;
		cin>>day1>>month1>>year1;
		year=year1-1900;
		system("cls");
		
		cout<<day1<<"/"<<month1<<"/"<<year1<<endl;
		cout<<"Enter your name"<<endl;
		cin>>name;
		cout<<"Enter your address"<<endl;
		cin>>address;
		cout<<"Enter your handphone number"<<endl;
		cin>>hpnum;
		cout<<"Enter the number of tenants , ( we only allow a maximum number of 6 tenants per room ) "<<endl;
            p1:
		cin>>people;
		if (people >=7)
		goto p1;
		cout<<"choose your preferred room"<<endl;
		cout<<"press '1' for standard room"<<endl;
		cout<<"press '2' for deluxe room"<<endl;
		cin>>room;
		cout<<"Enter your check out date"<<endl;
		cin>>day2>>month2>>year2;
		year4=year2-1900;
		double days = date (day1,month1,year,day2,month2,year4);
		
		double sum = 0;
		double addf = 0;
		
		if (people <=2 && people>0)
		{
			if(room==1)
			{
				sum+=100;
				for(i=2;i<=days;i++)
				{
					sum+=70;
				}
			}
			
			else if(room == 2)
			{
				sum+=200;
				for(i=2;i<days;i++)
				{
					sum +=150;
				}
			}
		}
		
		else if(people<=4&&people>2)
		{
			if(room == 1)
			{
				sum+=150;
				for(i=2;i<=days;i++)
				{
					sum+=120;
				}
			}
			
			else if (room==2)
			{
				sum+=300;
				for(i=2;i<=days;i++)
				{
					sum+=200;
				}
			}
		}
		else if (people<=6&&people>4)
		{
			if(room == 1)
			{
				sum+=250;
				for(i=2;i<days;i++)
				{
					sum+=150;
				}
			}
			
			else if (room == 2)
			{
				sum+=400;
				for(i=2;i<=days;i++)
				{
					sum+=250;
				}
			}
		}
		
		cout << sum << endl;
		
		cout<<"do you want an addition of extra bed or any other services ? type yes or no"<<endl;
		cin>>add;
		if (add == "yes")
		{
			addf=addition(days);
		}
		cout<<addf<<endl;
		system("cls");
		payment(sum,addf,name,address,hpnum,room,people,day1,month1,year1,day2,month2,year2,days);
		string choice;
		
		cout<<"do you want to book another room.. (yes/no)"<<endl;
		if(choice == "yes")
		{
			goto start;
		}
		else if(choice == "no")
		{
			return 0;
		}
}
