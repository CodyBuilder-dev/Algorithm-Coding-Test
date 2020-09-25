//제목 : 스택
//목표 : 스택의 기본적인 명령어
//스택을 만드는 방법 : 링크드 리스트를 만든다? 배열을 만든다?
//사실은 : STL쓰면 한방에 된다!
//아이디어 : 명령어가 한자리인지 2자리인지 읽으려면 문자열 처리 필요
//그냥 문자열처리 하지 말고, 명령어 집합 만들고 2칸짜리면 한번 더 읽음
//명령어의 배열을 만들어서 비교하는건 귀찮고, 그냥 getline해서 앞에것만 파싱하는게 맞다.

//switch case 에서 문자열 사용하기
//전통적으로는 map 이용해 string을 int에 대응시키고 그 int를 switch에 넣음

//1칸 명령어 : top,size,empty,pop
//2칸 명령어 : push 

//소감 : map, stack이 느리긴 함. 그래도 편한걸 어떡해ㅋㅋ
#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main()
{
	int N;
	stack<int> a;
	map<string, int> m;
	string first;
	int second;
	
	m.insert(make_pair("push", 1));
	m.insert(make_pair("pop", 2));
	m.insert(make_pair("size", 3));
	m.insert(make_pair("empty", 4));
	m.insert(make_pair("top", 5));
	//아니면  m[키값] = 벨류값; 으로 초기화해도 됨

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> first;
		if (m[first] == 1) 
		{
			cin >> second;
		}
		switch (m[first])
		{
		case 1: a.push(second); break;
		case 2: 
			if (!a.empty()) {
				cout << a.top() << '\n';
				a.pop();
			}
			else cout << -1 << '\n';
			break;
		case 3:
			cout << a.size() << '\n'; break;
		case 4:
			cout << (a.empty() ? 1 : 0) << '\n'; break;
		case 5:
			if (!a.empty()) cout << a.top() << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}