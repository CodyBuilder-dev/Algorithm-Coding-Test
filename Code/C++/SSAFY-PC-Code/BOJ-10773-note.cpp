//제목 : 제로
//목적 : 스택에 잘 넣고, 스택에서 꺼내서 합 구하기
//문제점 : 스택은 pop하는 순간 무조건 변형되므로, 부수지 않고 스택에서 합을 구하긴 어려울 수 있음
//오히려 배열을 쓰는게 나을 수 있음
//소감 : 이거는 stack 쓰고도 20ms에 실행되던데 왜 그럴까?
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int K;
	int temp;
	int sum = 0;
	stack<int> numstack;

	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		cin >> temp;
		if (temp == 0) numstack.pop();
		else numstack.push(temp);
	}
	//이거 왜 안되냐
	//for (int i = 1; i <= numstack.size(); ++i)
	while(!numstack.empty())
	{
		sum += numstack.top();
		numstack.pop();
	}
	cout << sum;
}