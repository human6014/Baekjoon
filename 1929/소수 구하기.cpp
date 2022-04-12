#include <iostream>
using namespace std;

bool arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int Min, Max;
	cin >> Min >> Max;
	

	for (int i = 2; i <= Max; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j <= Max; j += i) {
			arr[j] = true;
		}
		if (!arr[i] && i>=Min && i<=Max) cout << i << "\n";
	}

	//위		내		제출
	
	//아레		좋은	제출

	/*
	for (int i = 2; i * i <= Max; i++) {
		if (arr[i]) continue;
		for (int j = i * i; j <= Max; j += i) {
			arr[j] = true;
		}
	}
	for (int i = Min; i <= Max; i++) {
		if (!arr[i]) cout << i << "\n";
	}
	*/
}