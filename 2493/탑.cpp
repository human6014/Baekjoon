//탑
#include <iostream>
#include <stack>
using namespace std;

int N; int answer[500001]; int main() {
    stack<pair<int, int>> s; cin >> N;

    int height;
    bool isEmpty;
    for (int i = 0; i < N; i++) {
        cin >> height;

        if (i == 0) {
            answer[0] = 0;
            s.push({ i + 1, height });
            continue;
        }

        while (!(isEmpty = s.empty()) && s.top().second < height) s.pop();

        answer[i] = isEmpty ? 0 : s.top().first;
        s.push({ i + 1, height });
    }

    for (int i = 0; i < N; i++) cout << answer[i] << " ";
} 
/* 
5 
6 9 5 7 4

6 진입 -> 첫번째라 그대로 stack Go! 
9 진입 -> stack top = 6 
       -> 자신보다 작기 때문에 계속 pop top 
       -> stack에 더 없으므로 0 저장 
       -> 자기 자신 stack push 
5 진입 -> stack top = 9 
       -> 자신보다 크기 때문에 해당 넘버 저장 
       -> 자기 자신 stack push 
7 진입 -> stack top = 5 
       -> 자신보다 작기 때문에 계속 pop top 
       -> 9를 만나고 자신보다 크기 때문에 해당 넘버 저장 
       -> 자기 자신 stack push

9 
10 6 5 4 3 2 7 5 9 
 0 1 2 3 4 5 1 7 1

*/