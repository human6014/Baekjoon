#include <iostream>
#include <vector>
using namespace std;

int H, W;
int height[501];
int main() {
	cin >> H >> W;
	int answer = H * W;
	for (int i = 1; i <= W; i++) {
		cin >> height[i];
		answer -= height[i];
	}

	int left, right;
	int noWaterZone = 0;
	for (int i = H; i > 0; i--) {
		left = 1;
		right = W;
		while (left <= right) {
			if (height[left] >= i && height[right] >= i) break;
			if (height[left] < i) {
				noWaterZone++;
				left++;

			}
			if (left > right) break;
			if (height[right] < i) {
				noWaterZone++;
				right--;

			}
		}
	}
	cout << answer - noWaterZone;
}
/*
int main() {
	cin >> H >> W;
	vector<int> height;
	int answer = 0;
	height.resize(W);
	for (int i = 0; i < W; i++) {
		cin >> height[i];
	}

	int start = height[0];
	int end;
	int count = 0;
	int temp = 0;
	int min;
	for (int i = 1; i < height.size(); i++) {
		if (i == height.size() - 1) {
			end = height[i];

			if (start > end) {
				temp -= (start - end) * count;
			}
			answer += temp;
			break;
		}
		if (height[i] < start) {
			count++;
			temp += start - height[i];
		}
		else if (height[i] >= start) {
			end = height[i];

			if (start > end) {
				temp -= (start - end) * count;
			}

			start = height[i];
			answer += temp;
			temp = 0;
			count = 0;
		}
	}
	cout << answer;
}
*/
/*
4 4
3 1 2 4
= 3

4 8
3 1 2 3 4 1 1 2
= 5

100 18
28 100 43 33 37 100 87 15 52 35 54 86 60 24 99 56 4 40
= 602

5 5
1 0 3 2 4
= 2

* * * * *
* * * * #
* * # * #
* * # # #
# * # # #
*/
