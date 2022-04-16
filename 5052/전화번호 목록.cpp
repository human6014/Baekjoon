#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<vector<string>> numberList;

string answers[51];
int main() {
	fill_n(answers, 51, "YES");
	cin >> T;
	int n;
	string tempNum;
	vector<string> phoneNumbers;
	for (int i = 0; i < T; i++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> tempNum;
			phoneNumbers.push_back(tempNum);
		}
		sort(phoneNumbers.begin(), phoneNumbers.end());

		numberList.push_back(phoneNumbers);
		phoneNumbers.clear();
	}
	
	/*
	cout << "\n";
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < list[i].size(); j++) {
			cout << list[i][j] << endl;
		}
	}
	*/
	
	for (int i = 0; i < T; i++) {

		for (int j = 0; j < numberList[i].size() - 1; j++) {
			if (numberList[i][j] == numberList[i][j + 1].substr(0, numberList[i][j].size())) {
				answers[i] = "NO";
				break;
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cout << answers[i] <<"\n";
	}
}
//4
//1
//1
//1
//1

/*
4
2
1
1
3
1
12
145
2
12
13
1
1
*/
