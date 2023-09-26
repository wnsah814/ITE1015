#include <iostream>
#include <vector>
#include "clock_time.h"
#include "clocks.h"

using namespace std;
int main() {
    int second;
    cin >> second;

    vector<Clock*> clocks;
    clocks.push_back(new SundialClock(0, 0, 0));
    clocks.push_back(new CuckooClock(0, 0, 0));
    clocks.push_back(new GrandFatherClock(0, 0, 0));
    clocks.push_back(new WristClock(0, 0, 0));
    clocks.push_back(new AtomicClock(0, 0, 0));

    vector<Clock*>::iterator it;
    
    for (it = clocks.begin(); it != clocks.end(); it++) {
        (*it) -> reset();
    }
    
    cout << "Reported clock times after resetting:\n";
    for (it = clocks.begin(); it != clocks.end(); it++) {
        (*it) -> displayTime();   
    }
    cout << "\nRunning the clocks...\n\n";

    for (int i = 0; i < second; i++) {
        for (it = clocks.begin(); it != clocks.end(); it++) {
            (*it) -> tick();
        }
    }

    cout << "Reported clock times after running:\n";
    for (it = clocks.begin(); it != clocks.end(); it++) {
        (*it) -> displayTime();
    }

    for (it = clocks.begin(); it != clocks.end(); it++) {
        delete *it;
    }
    return 0;
}