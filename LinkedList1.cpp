#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    *p = 13; // a value change from 10 to 13
    cout<<"a: "<<a<<endl;
    int **q;
    q = &p;   //*q value of 'p' **q is the value of 'a'
    **q = 15; // a value will be change from 13 to 15
    int*** r;
    r = &q; // r will store the address of q
    cout << "a: " << a << endl;
    cout << "*p: value of a " << *p << endl;
    cout << "p: address of a " << p << endl;
    cout << "&a: address of a " << &a << endl;
    cout << "q: address of p " << q << endl;
    cout << "*q: value of p and p means address of a: " << *q << endl;
    cout << "*(*q): value of a " << *(*q) << endl;
    cout << r << endl;        //  r=&q i.e address of q
    cout << *r << endl;       //  r=&q => *r=q i.e value of q, q=&p
    cout << *(*r) << endl;    // from previous *r=&p Now **r= p i.e value of p
    cout << *(*(*r)) << endl; // from previous **r=value of p Now ***r=*p i.e value of a
    ***r = 786;
    cout << a << endl; //a value is change from 15 to 786

    // ***r=a, **q=a, *p=a;
    ***r = **q + 1; //a=a+1
    cout << a << endl;

    **q = *p + 2; //a=a+2
    cout << a << endl;

    *p = a + 3; //a=a+3
    cout << a << endl;
    return 0;
}

//this is the shortcut of screencast ctrl+alt+shift+r
