//OOPL Assignment 2

//Imagine a publishing company which does marketing for book and audio cassette versions. 
//Create a class publication that stores the title (a string) and price (type float) of publications. 
//From this class derive two classes: book which adds a page count (type int) and tape which 
//adds a playing time in minutes (type float).
//Write a program that instantiates the book and tape class, allows user to enter data and 
//displays the data members.


# include <iostream>
# include <string>
using namespace std;

class Publication 
{
    public:
    string  Book_title, Audio_title;
    float price;
    
};

class Book : public Publication
{
    public:
    int book_pages;
    public:
    string tbook;
    int pgs;
    void getdata() {

        cout<<"Enter the Title of book:";
        cin>>tbook;
        cout<<"Enter the pages of the book:";
        cin>>pgs;
        cout<<"Enter the price of the book:";
        cin>>price;
        Book_title=tbook;
        book_pages=pgs;
    }

    void putdata() {
        cout<<"Details for the book:"<<endl;
        cout<<"\nTitle of the book is:"<<Book_title<<endl;
        cout<<"\nPrice of the book:"<<" Rs. "<<price<<endl;
        cout<<"\nPages of the book are:"<<book_pages<<" pages "<<endl;

    }
};

class Tape : public Publication
{
    public:
    int minutes;
    int min;
    void getdata() {
         cout<<"\nEnter the title of audio:"<<endl;
        cin>>Audio_title;
        cout<<"\nEnter the time of Audio in minutes:"<<endl;
        cin>>min;
        minutes=min;
       
    }

    void putdata() {
        cout<<"Title of the Audio is : "<<Audio_title<<endl;
        cout<<"Time of Audio in minutes : "<<minutes<<" min"<<endl;
        }
};

int main() 
{
    Book obj1;
    obj1.getdata();
    obj1.putdata();
    Tape obj2;
    obj2.getdata();
    obj2.putdata();
    return 0;
}
