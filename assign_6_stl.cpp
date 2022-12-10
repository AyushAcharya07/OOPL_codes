//OOPL EXPT6
/*
Write C++ program using STL for sorting and searching user defined records such as personal 
records (Name, DOB, Telephone number etc) using vector container.   
*/

# include <iostream>
# include <vector>
# include <string.h>
# include <algorithm>
using namespace std;

class data
{
    public:
    string name;
    string year;
    string roll_no;
    string DOB;
    string mobile_no;

    void get_data()
    {
        cout<<"Enter your name : "<<endl;
        cin>>name;
        cout<<"Enter your class name : "<<endl;
        cin>>year;
        cout<<"Enter your Roll no. : "<<endl;
        cin>>roll_no;
        cout<<"Enter your DOB : "<<endl;
        cin>>DOB;
        cout<<"Enter your mobile no. : "<<endl;
        cin>>mobile_no;
    }

    void put_data()
    {
       

        cout<<"Roll no.\t\tName\t\tClass\t\tDOB\t\tMobile No."<<endl;
        cout<<roll_no<<"\t\t\t"<<name<<"\t\t"<<year<<"\t\t"<<DOB<<"\t"<<mobile_no<<endl;
    }

};

int main()
{
    
    int n,ch,ans;
    string key;
    cout<<"Enter the no. of students in the class : "<<endl;
    cin>>n;
    vector<data>v(n);
    vector<string>name(n);
    vector<string>Roll(n);

    do
    {
        cout<<"***************MENU***************"<<endl;
        cout<<"1.Writing the data\n2.Displaying the data\n3.Sorting the data\n4.Searching for any student"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                 for (int i=0;i<n;i++)
                {
                    v[i].get_data();
                }
                break;

            case 2:
                for (int i=0;i<n;i++)
                {
                    v[i].put_data();
                }
                break;

            case 3:
                for (int i=0;i<n;i++)
                {
                    Roll[i]=v[i].roll_no;
                }

                sort(Roll.begin(),Roll.end());
                for (int i=0;i<n;i++)
                {
                    for (int j=0;j<n;j++)
                    {
                        if (Roll[i]==v[j].roll_no)
                        {
                            v[j].put_data();
                        }

                    }
                
                }

                break;

            case 4:
                 for (int i=0;i<n;i++)
                {
                    name.push_back(v[i].name);
                }
                sort(name.begin(),name.end());

                cout<<"Enter the name you want to search : "<<endl;
                cin>>key;
                if (binary_search(name.begin(),name.end(),key))
                {
                    cout<<"Present in the data"<<endl;
                }
                else
                {
                    cout<<"Not present in the data"<<endl;
                }
                break;

            default:
                cout<<"\nYou have entered a wrong choice"<<endl;
                break;

        }
        cout<<"\nDo you want to continue?"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    }while (ans==1);

    if (ans>=2)
        cout<<"Successfully exited !!!"<<endl;

    return 0;
}