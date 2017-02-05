#include<stdio.h>
#include<iostream>
#include <bitset>
#include <limits>
#include <string>
#include<conio.h>
#include<dos.h>
//#include<string.h>
#define L 16
using namespace std;


void print_bool (bitset<8> bs)    //This function runs through the bitsets passed to it writing them to the screen
{                                                     //with an endl at the end it.
    for ( int i = (int) bs.size()-1; i >= 0; i--)
        {cout << bs[i] ;}
        cout<<endl;
}


void adder_()
{

    int int_a=0, int_b=0, final= 0;

    cout <<"Eneter two positive integer values seperated by a space"<<endl;    //Askes for the input and takes in the input as intagers
    cout<<endl;
    cin >>int_a>>int_b;

    bitset<8> bool_a (int_a);    //These bitset statemens creates the binary values I will work with two to represnt the integers to be added
    bitset<8> bool_b (int_b);    //as well as a sum and carry all intialized to 0
    bitset<8> sum, carry = 0;

    cout <<endl;
    cout<<endl;
    //******************************************Computations are performed here*****************************************
    sum = bool_a ^ bool_b;        //Gets the starting sum by using exclusive or s = a xor b
    carry = bool_a & bool_b;    //The starting carry is c = a and b
    carry = carry <<1;        //YOU HAVE TO SHIFT THE BITS IN THE CARRY TO MAKE THEM LINE UP
                    //THIS INSURES THAT THE FIRST ONE ON THE RIGHT IS ALWAYS A ZERO
                    //This is also know as a half adder

    for (int i  = 0; i < 7; i++)    //Sets up the loop to iterate through the bits for the full adder
    {
        carry[i+1] = bool_a[i] & bool_b[i] | carry[i] & (bool_a[i] ^bool_b[i]);    //  c = x and y or z and (x xor y)
        sum[i] = (bool_a[i] ^ bool_b[i]) ^ carry[i];                // s = (x xor y) xor z
    }

//The key there is that z needs to be your c from the previous itteration
//hence having to establish starting values the full adder must be feed by
//an half adder
//*************************************Printing and formating**************************************
    cout<<"c ";
    print_bool(carry);
    cout<<"  ^^^^^^^^"<<endl;
    cout<<"  ";
    print_bool(bool_a);
    cout<<"+ ";
    print_bool(bool_b);
    cout <<"----------"<<endl;
    cout<<"  ";
    print_bool(sum);
    cout<<endl;
    cout<<endl;
    final = sum.to_ulong();    //This converts the bitset back to an interger value to printed to the screen
    cout<<int_a<<" + "<<int_b<<"  = "<<final<<endl;
}
void increment_numerical_string(std::string& s)
{
    std::string::reverse_iterator iter = s.rbegin(), end = s.rend();
    int carry = 1;
    while (carry && iter != end)
    {
        int value = (*iter - '0') + carry;
        carry = (value / 10);
        *iter = '0' + (value % 10);
        ++iter;
    }
    if (carry)
        s.insert(0, "1");
}
void incrementor_()
{
    cout<<"enter a number"<<endl;
    string a;
    cin>>a;
    std::string big_number =a;
    std::cout << "before increment: " << big_number << "\n";
    increment_numerical_string(big_number);
    std::cout << "after increment:  " << big_number << "\n";
}

void print_bin(int n)
 {
 std::string str = "0";

  if (n > 0) {
    str = std::bitset<std::numeric_limits<unsigned int>::digits>(n).to_string();
    str = str.substr(str.find('1'));
    }

  std::cout << str << '\n';
}

void not_op()
{
int a[4],b[4];
int i;
cout<<"enter the binary number"<<endl;
for(i=0;i<4;i++)
{cin>>a[i];}
cout<<"RESULT OF BITWISE NOT OPERATION "<<endl;
for(i=0;i<4;i++)
{
    if(a[i]==1)
    {cout<<"0 ";
    }
    else if(a[i]==0)
    {cout<<"1 ";
    }
}
}
void xor_op()
{
int a[4],b[4];
int i;
cout<<"enter the first binary number"<<endl;
for(i=0;i<4;i++)
{cin>>a[i];}
cout<<"enter the second binary number"<<endl;
for(i=0;i<4;i++)
{cin>>b[i];}
cout<<"RESULT OF BITWISE XOR OPERATION "<<endl;
for(i=0;i<4;i++)
{
cout<< (a[i] ^ b[i])<<" ";
}
}
void or_op()
{
int a[4],b[4];
int i;
cout<<"enter the first binary number"<<endl;
for(i=0;i<4;i++)
{cin>>a[i];}
cout<<"enter the second binary number"<<endl;
for(i=0;i<4;i++)
{cin>>b[i];}
cout<<"RESULT OF BITWISE OR OPERATION "<<endl;
for(i=0;i<4;i++)
{
cout<< (a[i] | b[i])<<" ";
}
}
void and_op()
{
int a[4],b[4];
int i;
cout<<"enter the first binary number"<<endl;
for(i=0;i<4;i++)
{cin>>a[i];}
cout<<"enter the second binary number"<<endl;
for(i=0;i<4;i++)
{cin>>b[i];}
cout<<"RESULT OF BITWISE AND OPERATION "<<endl;
for(i=0;i<4;i++)
{
cout<< (a[i] & b[i])<<" ";
}
}
void logic_()
{
    int xy;
    cout<<"1.AND OPERATION\n";
    cout<<"2.OR OPERATION\n";
    cout<<"3.NOT OPERATION\n";
    cout<<"4.XOR OPERATION\n";
    cout<<"ENTER YOUR CHOICE\t\n";
    cin>>xy;
    switch(xy)
    {
            case 1:and_op();
                   break;
            case 2:or_op();
                   break;
            case 3:not_op();
                   break;
            case 4:xor_op();
                   break;
            default:cout<<"INVALID CHOICE\n";
                    break;
    }
}
int main()
{

    char choice;
    int xx;
    do
    {
    cout<<"\t\t MENU\n";

    cout<<"1.CORRESPONDING_BINARY_EQUIVALENT\n";
    cout<<"2.8_BIT_ADDER\n";
    cout<<"3.INCREMENTOR\n";
    cout<<"4.LOGIC_OPERATIONS\n";
    cout<<"ENTER_YOUR_CHOICE\t\n";
    cin>>xx;
    switch(xx)
    {
            case 1:
                cout<<"enter a number"<<endl;
                int a;
                cin>>a;
                print_bin(a);
                    break;
            case 2:adder_();
                    break;
            case 3:incrementor_();
                    break;
            case 4:
                    logic_();
                    break;
            default:cout<<"INVALID CHOICE\n";
                    break;
    }
    cout<<"DO YOU WANT TO GO BACK TO MAIN MENU(Y/N)\t";
    cin>>choice;
    }while(choice=='y');
    return 0;
}
