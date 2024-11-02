#include<iostream>
using namespace std;

int main() {

    int mul=1;
    int i=1;
    while(i<=10) {
        mul=mul*i;
        cout<<i<<" -> "<<mul<<endl;
        i++;
    }

    return 0;
}
