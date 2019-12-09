//제목 : 큐
//목적 : 큐 기본 명령어 쓰기

#include <queue>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;
	queue<int> numque;
	string first;
	int second;

	map<string, int> m;
	
	m["push"] = 1;
	m["pop"] = 2;
	m["size"] = 3;
	m["empty"] = 4;
	m["front"] = 5;
	m["back"] = 6;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> first;
		if (m[first] == 1) cin >> second;

		switch (m[first])
		{
		case 1: numque.push(second); break;
		case 2:
			if (!numque.empty())
			{
				cout << numque.front() << '\n';
				numque.pop();
			}
			else cout << -1 << '\n';
			break;
		case 3: cout << numque.size() << '\n'; break;
		case 4: cout << (numque.empty() ? 1 : 0) << '\n'; break;
		case 5: if (!numque.empty()) cout << numque.front() << '\n';
				else cout << -1 << '\n';
				break;
		case 6: if (!numque.empty()) cout << numque.back() << '\n';
				else cout << -1 << '\n';
				break;

		}
	}
}