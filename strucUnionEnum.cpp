#include<bits/stdc++.h>
using namespace std;

struct student{
    int age;
    string rollNo;
    string name;
};

union custormer{
    int rice;
    char biscuit;
    double wheet;
};

int main(){
    struct student s;
    union custormer c;

    //below is the usage of struct
    s.age = 20;
    s.rollNo = "ra111";
    s.name = "avinash";

    cout<<s.age<<endl;
    cout<<s.name<<endl;
    cout<<s.rollNo<<endl;


    //below is the usage of union
    c.biscuit = 'b';
    cout<<c.biscuit<<endl;
    c.rice = 2;
    cout<<c.biscuit<<endl;
    cout<<c.rice<<endl;

    return 0;
}