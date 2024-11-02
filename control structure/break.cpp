#include<iostream>
using namespace std;

int main() {
    
    for(int i=0; i<=10; i++) {
        cout<<"Iteration number: "<<i<<endl;
        if(i==5) {
            break;
        }
    }

    return 0;
}