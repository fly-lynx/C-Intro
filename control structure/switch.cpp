#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter a number (1-7) for the day of the week: ";
    cin >> day;

    switch (day) {
        case 1:
            cout << "Today's Sunday" << endl;
            break;
        case 2:
            cout << "Today's Monday" << endl;
            break;
        case 3:
            cout << "Today's Tuesday" << endl;
            break;
        case 4:
            cout << "Today's Wednesday" << endl;
            break;
        case 5:
            cout << "Today's Thursday" << endl;
            break;
        case 6:
            cout << "Today's Friday" << endl;
            break;
        case 7:
            cout << "Today's Saturday" << endl;
            break;
        default:
            cout << "Invalid input! Please enter a number between 1 and 7." << endl;
    }

    return 0;
}
