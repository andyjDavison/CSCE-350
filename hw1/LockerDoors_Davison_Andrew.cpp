#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main() {

    int numLockers, numOpened = 0;

    cout << "Enter the number of lockers: " << endl;
    cin >> numLockers;

    int lockers[numLockers] = {};
    for(int i=1;i<=numLockers;i++) {
        for(int j=0;j<numLockers;j++) {
            if((j+1)%i == 0) {
                if(lockers[j] == 0) lockers[j] = 1;
                else if(lockers[j] == 1) lockers[j] = 0;
            }
        }
    }

    //print lockers
    for(int i=0;i<numLockers;i++) {
        if(lockers[i] == 0) cout << "locker " << i+1 << " is closed." << endl;
        else if(lockers[i] == 1) {
            cout << "locker " << i+1 << " is open." << endl;
            numOpened++;
        }
    }

    cout << "Total open locks: " << numOpened << endl;

    return 0;
}