// OOPL Assignment 4

/*
 
Develop a program in C++ to create a database of student’s information system containing the 
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact 
address, Telephone number, Driving license no. and other. Construct the database with 
suitable member functions. Make use of constructor, default constructor, copy constructor, 
destructor, static member functions, friend class, this pointer, inline code and dynamic 
memory allocation operators-new and delete as well as exception handling.

*/


# include <iostream>
# include <string.h>
using namespace std;

class personalinfo 
{
	string license,dob,bloodgrp;
	public:
	personalinfo();         //default constructor
	personalinfo(personalinfo &);       //copy constructor 

	~personalinfo()         //destructor called
	{
	cout<<"The destructor for class personalinfo is called"<<endl<<"Record are deleted successfully!"<<endl;
	}
	friend class student;
};

class student 
{
	string name,address,year,division;
	int roll_no;
    long long mob_no;
    static int count;
    public:
    void create (personalinfo &);       //func taking obj as an argument

    void display(personalinfo &);
    inline static void incount()        //improves the exexcution time 
    {
        count++;
    }

    inline static void displaycnt()
    {
        cout<<"******************"<<endl;
        cout<<"The total no. of records are :"<<count<<endl;
    }

    student();          //default constructor
    student(student &);     //copy constructor with argument as obj
    ~student()          //destructor
    {
        cout<<"Destructor for class student successfully called"<<endl;
    }
};

int student::count;
student::student()          //default const assigning default values to variables
{
    name="AYUSH ACHARYA";
    address="PUNE";
    year="SE COMP";
    division='A';
    roll_no=35;
    mob_no=9423299990;
}
personalinfo::personalinfo()            //default const assigning default values to variables
{
    license="ABCD11136";
    dob="15/12/2003";
    bloodgrp="A+";

}

student::student(student &obj)              //copy const having an argument as obj of same class
{
    this->name=obj.name;
    this->address=obj.address;
    this->year=obj.year;
    this->division=obj.division;
    this->roll_no=obj.roll_no;
    this->mob_no=obj.mob_no;
}

personalinfo::personalinfo(personalinfo &obj)           //copy const having an argument as obj of same class
{
    license=obj.license;
    dob=obj.dob;
    bloodgrp=obj.bloodgrp;
}

void student::create(personalinfo &obj)             //taking inputs where variables of other class are included using obj
{
    cout<<"****************************"<<endl;
    cout<<"ENTER THE NAME :"<<endl;
    cin>>name;
    cout<<"ENTER THE ADDRESS :"<<endl;
    cin>>address;
    cout<<"ENTER THE YEAR :"<<endl;
    cin>>year;
    cout<<"ENTER THE DIVISION :"<<endl;
    cin>>division;
    cout<<"ENTER THE ROLL NO. :"<<endl;
    cin>>roll_no;
    cout<<"ENTER THE MOBILE NO. :"<<endl;
    cin>>mob_no;
    int total=0;
    int tmob;
    tmob=mob_no;
    
    
    while (tmob>0)                    
    {
        total++;
        tmob=tmob/10;
    }
    cout<<"\nthe count of the mobile no."<<total;       

    try                 //exception handling case -> checking whether the mobile no. count is 10 or not
    {
        if (total==10)
        {
            cout<<"\nMobile no. is correct"<<endl;
        } else {
            throw(tmob);
        }
    }
    catch( int num)
    {
        cout<<"\nMobile no. is incorrect"<<endl;
        while (total>10 | total<10)
        {
            long long next_mob;
            cout<<"\nEnter a correct mobile no. of 10 digits : "<<endl;
            cin>>next_mob;
            mob_no=next_mob;
            break;
        }

    }

    
    
    cout<<"ENTER THE DATE OF BIRTH :"<<endl;
    cin>>obj.dob;
    cout<<"ENTER THE LICENSE NUMBER :"<<endl;
    cin>>obj.license;
    cout<<"ENTER THE BLOOD GROUP :"<<endl;
    cin>>obj.bloodgrp;

}

void student::display(personalinfo &obj)
{
    cout<<endl;
    cout<<"***************STUDENT INFO***************"<<endl;
    cout<<"Name of student is :"<<name<<endl;
    cout<<"Address of student is :"<<address<<endl;
    cout<<"DOB of student is :"<<obj.dob<<endl;
    cout<<"Year of student is :"<<year<<endl;
    cout<<"Division of student is :"<<division<<endl;
    cout<<"Roll no.  of student is :"<<roll_no<<endl;
    cout<<"Blood Group of student is :"<<obj.bloodgrp<<endl;
    cout<<"License no. of student is :"<<obj.license<<endl;
    cout<<"Mobile no. of student is :"<<mob_no<<endl;
    cout<<"********************************"<<endl;
    cout<<endl;

}

int main()
{
    int ch,n,i=0;
    char m;
    cout<<"ENTER THE NO. OF STUDENT DATA YOU WANT TO ENTER :"<<endl;
    cin>>n;
    student *ptr1=new student [n];
    personalinfo *ptr2=new personalinfo[n];

    do{
        
        cout<<"***MENU****"<<endl;
        cout<<"1.Create Database\n2.Display Database\n3.Copy Constructor\n4.Default Constructor\n5.Delete Database"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
            {
                for (int j=0;j<n;j++)
                {
                    ptr1[i].create(ptr2[i]);
                    ptr1[i].incount();
                }
            }
            break;
            case 2:
            {
                ptr1[0].displaycnt();
                for (i=0;i<n;i++)
                {
                    ptr1[i].display(ptr2[i]);
                }
            }
            break;
            case 3:
            {
                student obj1;
                personalinfo obj2;
                student obj3(obj1);
                personalinfo obj4(obj2);

                cout<<"Copy Constructor is called"<<endl;
            }
            break;
            case 4:
            {
                student obj1;
                personalinfo obj2;
                cout<<"Default constructor is called"<<endl;
                obj1.display(obj2);
            }  
            break;
            case 5:
            {
                delete[] ptr1;              //using delete to free the allocated memory
                delete[] ptr2;
            }   

            cout<<endl;

        }cout<<"\n Do you want to continue : (y/n) ";
    cin>>m;
    }while (m=='y');
        
   if (m=='n')
   {
        cout<<"Exited successfully!!!";
   } 
   
   return 0;
    
}
