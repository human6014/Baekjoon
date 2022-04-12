#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long int HurtFinger, HurtCheck;
	long long int count = 0;
	cin >> HurtFinger >> HurtCheck;
	if (HurtFinger == 1) {
		count = 1 + HurtCheck * 8;
	}
	else if (HurtFinger == 2) {
		if (HurtCheck % 2 == 1) {
			count = 4 + HurtCheck * 4;
		}
		else {
			count = 2 + HurtCheck * 4;
		}
	}
	else if (HurtFinger == 3) {
		count = 3 + HurtCheck * 4;
	}
	else if (HurtFinger == 4) {
		if (HurtCheck % 2 == 1) {
			count = 2 + HurtCheck * 4;
		}
		else {
			count = 4 + HurtCheck * 4;
		}
	}
	else {
		count = 5 + HurtCheck * 8;
	}
	cout << count - 1;
}
/*#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int HurtFinger, HurtCheck;
	int count = 0, i = 0, NowCheck = 0;
	bool Point = 0;
	cin >> HurtFinger >> HurtCheck;
	HurtCheck += 1;
	while (NowCheck != HurtCheck) {
		if (Point == 0) {
			if (i < 5) {
				i++;
				count++;
				if (HurtFinger == i) {
					NowCheck++;
				}
				if (i == 5)
					Point = 1;
			}
		}
		else {
			if (i > 0) {
				i--;
				count++;
				if (HurtFinger == i) {
					NowCheck++;
				}
				if (i == 1)
					Point = 0;
			}
		}
	}
	cout << count - 1;
}
*/
/*#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int HurtFinger = 0;
	int HurtCheck = 0;
	int count = -1, i = 1, NowCheck = 0;
	cin >> HurtFinger >> HurtCheck;
	HurtCheck += 1;
	while (NowCheck != HurtCheck)
	{
		if (i < 5) {
			for (i; i < 5; i++) {
				if (NowCheck == HurtCheck)
					break;
				if (HurtFinger == i) {
					NowCheck++;
				}
				count++;
			}
		}
		else {
			for (i; i > 1; i--) {
				if (NowCheck == HurtCheck)
					break;
				if (HurtFinger == i) {
					NowCheck++;
				}
				count++;
			}
		}
	}
	cout << count;
}
*/

