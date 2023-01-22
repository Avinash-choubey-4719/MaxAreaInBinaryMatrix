#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    //accessing elements using pointer

    for(int i = 0;i<5;i++){
        cout<<"the value in array at position "<<i + 1<<" is "<<*(arr + i)<<endl;   // *(ptr + 1) = currrentAdressofptr + sizeof(datatype)
    }

    return 0;
}