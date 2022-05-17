#include <iostream>
#include <algorithm>
using namespace std;

string AB, target;
int main() {
    cin >> AB >> target;

    //bool isReversed = false;
    while (true) {
        if (target[target.length() - 1] == 'A') {
            target.erase(target.length() - 1);
            //cout << target << "\n";
        }
        else if (target[target.length() - 1] == 'B') {
            target.erase(target.length() - 1);
            reverse(target.begin(), target.end());
            //cout << target << "\n";
        }
        if (AB.length() == target.length()) {
            if (AB == target) cout << 1;
            else cout << 0;
            break;
        }
    }
}
/*
B
ABBA
B
BA
ABB
ABBA

B
ABBAB
B
BA
ABB
ABBA
ABBAB

*/