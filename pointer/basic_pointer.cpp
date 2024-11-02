#include <iostream>
using namespace std;

int main() {
    int num = 10;       // A regular integer variable
    int *ptr = &num;    // A pointer variable that holds the address of num

    cout << "Value of num: " << num << endl;           // Print value of num
    cout << "Address of num: " << &num << endl;        // Print address of num
    cout << "Value of ptr (address stored): " << ptr << endl; // Print address stored in ptr
    cout << "Value pointed to by ptr: " << *ptr << endl;      // Print value at the address

    *ptr = 20;  // Modify the value of num through the pointer
    cout << "New value of num after modification: " << num << endl; // Check the updated value of num

    return 0;
}
