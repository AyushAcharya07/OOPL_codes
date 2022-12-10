// OOPL Assignment 3

/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and 
a float array.

*/


# include <iostream>
using namespace std;

int n;

template <class S>
void selection_sort(S a[50]) 
{
    int i,j,k;
    S temp;

    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    cout<<"\nArray sorted :"<<endl;           //for displaying the array after sorting
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\n";
    }
}

int main()
{
    int i;
    int A[50];
    float B[50];
    cout<<"Enter the no. of elements for integer array:\n";
    cin>>n;
    cout<<"Enter the elements in the integer array:"<<endl;
        
    for(i=0;i<n;i++)            //for appending the input to the integer array
    {
        cin>>A[i];          
    }

    selection_sort(A);
    cout<<"\nEnter the no. of elements for float array:\n";
    cin>>n;
    cout<<"Enter the elements in the float array:"<<endl;
        
    for(i=0;i<n;i++)
    {
        cin>>B[i];          //for appending the input to the float array
    }
    selection_sort(B);
    cout<<"\n\n";
    return 0;
}