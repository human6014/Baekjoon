#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> tree;
int main() {
	string temp;
	float all=0;
	while (getline(cin, temp)) {
		all++;
		tree[temp]++;
	}

	for (auto i : tree) {
		printf("%s %.4f\n", i.first.c_str(), (i.second / all) * 100);
	}
}