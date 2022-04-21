#include <iostream>
#include <map>
using namespace std;

int N;
map<char, pair<char, char>> tree;

void PreOrder(char start) {
	cout << start;
	if (tree[start].first != '.') {
		PreOrder(tree[start].first);
	}
	if (tree[start].second != '.') {
		PreOrder(tree[start].second);
	}
}
void InOrder(char start) {
	if (tree[start].first != '.') {
		InOrder(tree[start].first);
	}
	cout << start;
	if (tree[start].second != '.') {
		InOrder(tree[start].second);
	}
}
void PostOrder(char start) {
	if (tree[start].first != '.') {
		PostOrder(tree[start].first);
	}
	if (tree[start].second != '.') {
		PostOrder(tree[start].second);
	}
	cout << start;
}
int main() {
	cin >> N;

	char root, left = '.', right = ',';
	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		tree[root] = { left,right };
	}

	/*
	for (auto it : tree) {
		cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
	}
	*/

	PreOrder('A');
	cout << "\n";
	InOrder('A');
	cout << "\n";
	PostOrder('A');
}