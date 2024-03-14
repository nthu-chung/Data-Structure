#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int N;
    string command;

    cin >> N ;
    
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "99") {
            cout << "99 PLTR"<< "\n";
            cout << "99 NFLX"<< "\n"; 
        } 
        else if (command == "Fucking") {
            cout << "Fucking All In" << "\n";
        } 
        else if (command == "GG") {
            cout << "GG help me!" <<"\n";
        } 
        else if (command == "Buy") {
            cout << "Buy and Sleep" <<"\n";
        }
       // ALL IN DA FA HOW
    }
    return 0;
}