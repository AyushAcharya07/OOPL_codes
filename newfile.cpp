# include <iostream>
# include <fstream>
# include <string.h>
using namespace std;

class data
{
    
    ofstream out;
    ifstream in;
    public:
    void file1()
    {
        string s1;
        int age;
        string year;
        out.open("file1.txt",ios::out|ios::trunc);
        cout<<"Enter your age : "<<endl;
        cin>>age;
        cout<<"Enter year in which you are currently : "<<endl;
        cin>>year;
        s1="\nThis is my 1st file\n1st file is opened successfully!";
        out<<s1<<endl;
        out<<age<<endl;
        out<<year<<endl;
        out.close();
        cout<<"\n1st file closed successfully!!"<<endl;
    }

    void file2()
    {
        string s2;
        int date;
        cout<<"Enter only today's date only DD : "<<endl;
        cin>>date;
        out.open("file2.txt",ios::out|ios::trunc);
        s2="This is my 2nd file\n2nd file is opened successfully!!";
        out<<s2<<endl;
        out<<date<<endl;
        out.close();
        cout<<"\n2nd file closed successfully!!"<<endl;
    }

    void read_both()
    {
        string f1,f2;
        in.open("file1.txt",ios::in);

       while(in.eof()==0)
       {
            getline(in,f1);
            cout<<f1<<endl;
       }
        in.close();
        cout<<"\n1st file is read and closed successfully!!"<<endl;

        in.open("file2.txt",ios::in);
        while(in.eof()==0)
        {
            getline(in,f2);
            cout<<f2<<endl;
        }
        in.close();
        cout<<"\n2nd file is read and closed successfully!!!"<<endl;

    }

    void append()
    {
        out.open("file1.txt",ios::app);
        char name[10];
        cout<<"Enter your name : "<<endl;
        cin>>name;
        out<<name<<endl;
        out.close();
        cout<<"1st file closed after appending successfully!!!"<<endl;

    }

};

int main()
{
    data d;
    int ch,ans;
    do
    {
        cout<<"***********MENU************"<<endl;
        cout<<"1.Write in 1st file\n2.Write in 2nd file\n3.Read both the files\n4.Append to 1st file"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;

        switch (ch)
        {
            case 1:
                d.file1();
                break;
            case 2:
                d.file2();
                break;
            case 3:
                d.read_both();
                break;
            case 4:
                d.append();
                break;
            default:
                cout<<"Wrong choice entered!!"<<endl;
                break;
        }
        cout<<"\nDo you want to continue?"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;

    } while (ans==1);

    if (ans>=2)
    {
        cout<<"\nExited successfully"<<endl;
    }

    return 0;
}
