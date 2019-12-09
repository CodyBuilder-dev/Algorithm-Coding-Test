//제목 : 트리의 부모 찾기
//목적 : 정수 tuple만으로 트리의 모양 만들어 내기
/*아이디어 : 링크드 리스트를 N개 만든다
1. 이거는 어쩔 수 없이, 일단 입력을 다 받고, 1이 있는 놈 부터 처리하는 수 밖에 없다.
2. 입력을 받아서, 2열 배열이나 튜플 형태로 저장한다?
3. 튜플의 원소 중 1이 잇는 튜플들 부터 처리한다
4. 튜플의 원소 중 3번에서 처리한 놈들이 있는 튜플부터 처리한다
5. 4번을 반복한다.
6. 트리 완성 완료
*/

#include <iostream>

using namespace std;

struct node {
	struct node *next;
	int data;
};

int main()
{
	int N;
	//1번 노드는 NODE[0], 2번 노드는 NODE[1]...
	struct node *NODE;
	//input이 1 6이면 각각 [0] =1 , [1] =6
	int** input_storage;
	int* parent_check;

	cin >> N;

	input_storage = new int*[N];
	input_storage[0] = new int[2];
	input_storage[1] = new int[2];
	
	parent_check = new int[N];
	NODE = new struct node[N];
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> input_storage[i][0] >> input_storage[i][1];
		if (input_storage[i][0] == 1)
		{
			NODE[input_storage[i][1] - 1].next = &NODE[0];
			parent_check[input_storage[i][1] - 1] = 1;
		}
			
			
		else if (input_storage[i][1] == 1)
		{
			NODE[input_storage[i][0] - 1].next = &NODE[1];
			parent_check[input_storage[i][0] - 1] = 1;
		}
	}

	for
}