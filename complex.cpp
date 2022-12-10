// 1. OOPL Assignment 1


//. Implement a class Complex which represents the Complex Number data type. Implement the 
//following
//1. Constructor (including a default constructor which creates the complex number 0+0i).
//2. Overload operator+ to add two complex numbers.
//3. Overload operator* to multiply two complex numbers.
//4. Overload operators << and >> to print and read Complex Numbers.

# include <iostream>
using namespace std;

int num_1_real,num_1_imag,num_2_real,num_2_imag;


class complex
 {   
    public:
    int realp;                          
    int imagp;                          

    complex(int areal=0, int aimag=0 )  
    {
        realp=areal;      
        imagp=aimag;       
    }

    complex complex_addition(complex a1, complex a2)         
    {
        complex anum;                         

        anum.realp= a1.realp + a2.realp;    
        anum.imagp= a1.imagp + a2.imagp;     

        return anum; 
    }
    
    complex complex_multiplication(complex a1, complex a2)      
    {
        complex bnum;                       

        bnum.realp= a1.realp * a2.realp-a1.imagp*a2.imagp;        
        bnum.imagp= a1.realp * a2.imagp+a1.imagp*a2.realp;        

        return bnum;
    }

};

int main()
{

    cout<<"Enter the real part of 1st num : "<<endl;
    cin>>num_1_real;
    cout<<"Enter the imag part of 1st num : "<<endl;
    cin>>num_1_imag;
    cout<<"Enter the real part of 2nd num : "<<endl;
    cin>>num_2_real;
    cout<<"Enter the imag part of 2nd num : "<<endl;
    cin>>num_2_imag;
    complex a1(num_1_real,num_1_imag);                       
    complex a2(num_2_real,num_2_imag);                        

    cout<<"1st Complex number : "<<a1.realp<<" + i "<<a1.imagp<<endl;      
    cout<<"2nd Complex number : "<<a2.realp<<" + i "<<a2.imagp<<endl;      

    complex a3;                             
    a3=a3.complex_addition(a1,a2);          

    cout<<"Addition of 1st and 2nd Complex number : "<<a3.realp<<" + i "<<a3.imagp;     

    complex a4;                             
    a4=a4.complex_multiplication(a1,a2);   

    cout<<"\nMultiplication of 1st and 2nd Complex number : "<<a4.realp<<" + i "<<a4.imagp;
}
