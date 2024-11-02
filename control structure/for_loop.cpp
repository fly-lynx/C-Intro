#include<iostream>
using namespace std;

int main() {

    int sum;
    for(int i=0; i<=10;i++) {
        sum=i+sum;
        cout<<i<<" and respective sum: "<<sum<<endl;
    }
    cout<<"Total sum is: "<< sum<<endl;


    return 0;
}