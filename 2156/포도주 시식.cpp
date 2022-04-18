#include <iostream>
using namespace std;

int N;

/*
int wines[10001];
int maxQuantity;
int Drink(int drinkingNum, int continuity, int quantity) {
	if (drinkingNum >= N) {
		return quantity;
	}
	if (continuity >= 2) {
		drinkingNum++;
		continuity = 0;
	}
	return max(Drink(drinkingNum + 1, continuity + 1, quantity + wines[drinkingNum]),
			   Drink(drinkingNum + 1, continuity, quantity));
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wines[i];
	}
	
	cout << Drink(0, 0, 0);
}
*/

int wines[10001];
int maxQuantity[10001];
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> wines[i];
	}
	maxQuantity[1] = wines[1];
	maxQuantity[2] = maxQuantity[1] + wines[2];

	//? OOX ?1
	//? OXX ?1
	//? XOX ?1
	//? OXO ?2
	//? XOO ?3
	//? XXO out
	//? XXX out
	int max1;//,max2,max3;
	for (int i = 3; i <= N; i++) {
		max1 = max(maxQuantity[i - 3] + wines[i - 1] + wines[i], maxQuantity[i - 2] + wines[i]);
		//max2 = max(maxQuantity[i - 3] + wines[i - 1], maxQuantity[i - 2]);
		//max3 = max(max2, maxQuantity[i - 1]);
		maxQuantity[i] = max(max1, maxQuantity[i-1]);
	}
	cout << maxQuantity[N];
}

/*
6
6
10
13
9
8
1
*/