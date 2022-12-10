//OOPL Assignment B4

//Write a C++ program that creates an output file, writes information to it, closes the file, open 
//it again as an input file and read the information from the file.

# include <iostream>
# include <fstream>
# include <string.h>
using namespace std;

class file
{
    public:
    void write_data()
    {
        string s1;
        ofstream write("data.txt",ios::out);
        cout<<"\nFile opened successfully for writing data"<<endl;

        write<<"Welcome to my file";                              // =>writing data into the file
        write<<"\nThis file contains information about my city";
        write<<"\nPune was the capital city of Maratha empire for hundreds of years!!!";
        write<<"\nPune is the Cultural capital of Maharashtra";
        write<<"\nPune is also known as Oxford of the East";
        write<<"\nPune and PCMC are twin cities";

        write.close();
        cout<<"\nFile successfully closed after writing data"<<endl;
    }

    void read_data()
    {
        string s2;
        ifstream read;
        read.open("data.txt",ios::in);
        cout<<"\nFile successfully opened for reading data"<<endl;
        while (read.eof()==0)       //until end of file is not reached we will use the following code
        {
            getline(read,s2);          //reads the entire line in the file
            cout<<s2<<endl;
        }
        read.close();
        cout<<"\nFile successfully closed after reading data"<<endl;
    }
};

int main()
{
    file f;
    f.write_data();
    f.read_data();
    return 0;
}