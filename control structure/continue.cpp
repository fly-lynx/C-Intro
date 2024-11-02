#include<iostream>
using namespace std;

int main() {

    for(int i=0; i<=10; i++) {
        
        if(i==4 | i==8){
            continue;
        }
        cout<<"Iteration number: "<<i<<endl;
    }

    return 0;
}