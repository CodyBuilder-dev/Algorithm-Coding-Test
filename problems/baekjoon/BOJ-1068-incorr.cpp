//제목 : 트리
//목적 : 트리의 자식을 잘라냈을 떄 리프의 개수 구하기
//조건 : 노드는 최대 50개

/*아이디어 : 부모정보가 주어지므로, 이로부터 연결상태 확보
(주의! 이진 트리라는 말이 없으므로 이진트리로 짜면 틀림!!)
1. 부모와 자식 연결
2. 연결하는것만으론 리프노드 개수 모르므로, 트리 다 돌면서 리프노드 개수 파악
3. 특정 노드 제거한 후 다시 리프노드 개수 구하기
*/

/*느낀점
1. 구조체 정의시 내부 포인터 변수는 값 안정하면 자동 NULL
*/
#include <iostream>

using namespace std;

typedef struct node {
	node* parent;
	node* left;
	node* right;
}NODE;

int N;
NODE nodeArray[10000];
int cut;

int leaf=0;

void cnt_leaf(NODE* start) {
	if (start->left == NULL && start->right == NULL)
		leaf++;

	if (start->left != NULL) cnt_leaf(start->left);
	if (start->right != NULL) cnt_leaf(start->right);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int parent;
		cin >> parent;
		if (parent == -1) continue;

		nodeArray[i].parent = &nodeArray[parent];
		if (nodeArray[parent].left == NULL)
			nodeArray[parent].left = &nodeArray[i];
		else nodeArray[parent].right = &nodeArray[i];
	}

	cin >> cut;
	//자르기 시작
	//부모로 찾아가서, 왼쪽인지 오른쪽인지 보고 자르기

	if (nodeArray[cut].parent->left == &nodeArray[cut])
		nodeArray[cut].parent->left = NULL;
	else if (nodeArray[cut].parent->right == &nodeArray[cut])
		nodeArray[cut].parent->right = NULL;

	nodeArray[cut].parent = NULL;

	//자른후 탐색 시작
	cnt_leaf(&nodeArray[0]);

	cout << leaf;
}