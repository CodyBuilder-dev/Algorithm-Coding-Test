//제목 : 덱
//목적 : STL 쓸줄 아는가 or 스스로 구현할 줄 아는가

#include <iostream>
#include <deque>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> command;
	command["push_front"] = 1;
	command["push_back"] = 2;
	command["pop_front"] = 3;
	command["pop_back"] = 4;
	command["size"] = 5;
	command["empty"] = 6;
	command["front"] = 7;
	command["back"] = 8;

	int N;
	cin >> N;

	string first;
	int second;
	deque<int> numque;

	for (int i = 1; i <= N; i++)
	{
		cin >> first;
		if (command[first] == 1 || command[first] == 2)
			cin >> second;
				
		switch (command[first])
		{
		case 1: numque.push_front(second); break;
		case 2: numque.push_back(second); break;
		case 3: 
			if (!numque.empty())
			{
				cout << numque.front() << '\n'; numque.pop_front();
			}
			else cout << -1 << '\n';
			break;
		case 4: 
			if (!numque.empty())
			{
				cout << numque.back() << '\n'; numque.pop_back();
			}
			else cout << -1 << '\n';
			break;
		case 5: cout << numque.size() << '\n'; break;
		case 6: cout << (numque.empty() ? 1 : 0) << '\n'; break;
		case 7: 
			if (!numque.empty())
			{
				cout << numque.front() << '\n';
			}
			else cout << -1 << '\n';
			break;
		case 8: 
			if (!numque.empty())
			{
				cout << numque.back() << '\n';
			}
			else cout << -1 << '\n';
			break;
		}
	}
}