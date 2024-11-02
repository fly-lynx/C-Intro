#include<iostream>
using namespace std;

int main() {

    int a=34;
    float s=45.67;

    float d = float(a);          //Type casting of int a, changing it into float
    int f = int(s);              //Type casting of float s, changing it into int

    cout << "Float d: "<<d<<endl;
    cout<<"int f :" <<f<<endl;

    return 0;
}