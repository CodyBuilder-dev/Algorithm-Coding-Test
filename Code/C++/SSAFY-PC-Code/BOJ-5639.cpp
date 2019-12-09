//제목 : 이진 검색 트리
//목적 : 이진 검색트리를 전위순회한 결과로부터, 트리 구조를 파악하고, 후위순회 결과를 찾아내라
//조건 : 노드의 개수는 최대 1만개

/*아이디어 : 우선 전위순회의 방식을 파악
1. 루트 노드를 찍고 왼쪽 서브트리로
2. 제일 작아질떄까지 계속 작게
3. 어느 순간 제일 깊이 들어가면, 그 뒤로는 증가함
4. 루트보다 커지는 순간부터는 오른쪽 서브트리임
5. 거기서부터 다시 작아질때까지 왼쪽
6. 하한선 찍고 다시 올라오기 시작
*/

/*구현 : 스택을 잘 쓰면 됡 거 같은데*/

/*느낀점 
1. node의 pair를 스택에 넣었다 뺄 때, stack.top 의 first와 second의 node는 포인터임
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef struct node {
	int value;
	node* left;
	node* right;
}NODE;

/*
vector<pair<node*, int>> inputStack;
vector<pair<node*, int>>::iterator iter;
*/

NODE nodeArray[10000];//0번째가 루트, 그뒤로 이진트리식으로 1,2,3,4...

void postorder(NODE* start) {
	if (start->left != NULL) postorder(start->left);
	if (start->right != NULL) postorder(start->right);
	cout << start->value << '\n';
}

int main()
{
	//루트 노드 값 받기
	int value;
	int i = 0;

	
	while (cin >> value)
	{
		if (value == 0) break;
		
		if (i == 0) {
			nodeArray[i].value = value;
		}

		else {
			if (value < nodeArray[i - 1].value) //새로 받은애가 작으면 스택 맨 끝의 왼쪽에 붙이기
			{
				nodeArray[i].value = value;
				nodeArray[i - 1].left = &nodeArray[i];
			}
			else //새로 받은애가 크면, 안 커질떄까지 스택 뺀 후 안 빠지면 오른쪽에 붙임
			{
				int j;
				for (j=i-1; j >= 0; --j)
				{
					if (nodeArray[j].value > value) break;
				}

				nodeArray[i].value = value;
				nodeArray[j].right = &nodeArray[i];
			}
		}
		i++;

	}

	postorder(&nodeArray[0]);

	return 0;
}