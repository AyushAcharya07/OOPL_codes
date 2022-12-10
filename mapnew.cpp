// OOPL Expt 7

/*
Write a program in C++ to use map associative container. The keys will be the names of states 
and the values will be the populations of the states. When the program runs, the user is 
prompted to type the name of a state. The program then looks in the map, using the state 
name as an index and returns the population of the state.
*/

# include <iostream>
# include <map>
# include <string.h>


using namespace std;

class state
{
    public:
    string state;
    map<string,string>mymap;
    map<string,string>::iterator itr;

    void data_states()
    {
        mymap["Uttar_Pradesh"]="20 billion";
        mymap["Maharashtra"]="11 billion";
        mymap["Tamilnadu"]="10 billion";
        mymap["Bengal"]="9 billion";
        mymap["Gujarat"]="6 billion";
        mymap["Arunachal_Pradesh"]="1 billion";
        mymap["Sikkim"]="6 million";
        mymap["Goa"]="1.4 billion";
        mymap["Andaman_&_Nicobar_islands"]="3 million";
    }

    void see_states()
    {
        for (itr=mymap.begin();itr!=mymap.end();itr++)
        {
            cout<<"States which are registered are : "<<itr->first<<endl;
        }cout<<endl;
    }

    void searching()
    {
        cout<<"Enter the state for which you want to see the population : "<<endl;
        cin>>state;
        if (mymap.count(state)!=0)
        {
            itr=mymap.find(state);
            cout<<"Population of "<<state<<" is : "<<itr->second;
        }
        else
        {
            cout<<"Sorry!!\nState not found in the map\nPlease try again!!"<<endl;
        }
    }



};
int main()
{
    state s;
    int ch,ans;
    do
    {
        cout<<"**********MENU**********"<<endl;
        cout<<"1.Create data for states\n2.See the states in the map\n3.Check the Population"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                s.data_states();
                cout<<"Data for the states added successfully"<<endl;
                break;
            case 2:
                s.see_states();
                break;

            case 3:
                s.searching();
                break;

            default:
                cout<<"You have entered a wrong choice"<<endl;
                break;
        }
        cout<<"\nDo you want to continue?"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;       
    }while (ans==1);

    if (ans>=2)
        cout<<"\nExited successfully !!!"<<endl;
    return 0;
}