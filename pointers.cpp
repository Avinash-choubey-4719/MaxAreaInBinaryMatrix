#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 100;
    cout<<"value of a is "<<a<<endl;
    cout<<"adress of a is "<<&a<<endl;

    //pointer
    int * ptr = &a;
    cout<<"the value of ptr is "<<ptr<<endl;
    cout<<"the value at ptr is "<<*ptr<<endl;


    //pointer to pointer
    int **ptrptr = &ptr;

    cout<<"the value of ptrptr is "<<ptrptr<<endl;
    cout<<"the value at ptrptr is "<<*ptrptr<<endl;

    return 0;
}