#include<iostream>
using namespace std;

int main() {

    int a;
    cout<<"Please enter your age!"<<endl;
    cin>>a;
    if(a>18) {
        cout<<"You can come to the party."<<endl;
    }
    else if(a==18) {
        cout<<"Not eligible, Try next year. Goodluck"<<endl;
    }


    else {
        cout<<"You are not eligible for this party. Try on kids section."<<endl;
    }

    return 0;
}