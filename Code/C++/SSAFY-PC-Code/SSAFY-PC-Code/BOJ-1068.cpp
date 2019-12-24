//제목 : 트리
//목적 : 트리의 자식을 잘라냈을 떄 리프의 개수 구하기
//조건 : 노드는 최대 50개

/*아이디어 : 부모정보가 주어지므로, 이로부터 연결상태 확보
(주의! 이진 트리라는 말이 없으므로 이진트리로 짜면 틀림!!)
1. 부모와 자식 연결
2. 연결하는것만으론 리프노드 개수 모르므로, 트리 다 돌면서 리프노드 개수 파악
3. 특정 노드 제거한 후 다시 리프노드 개수 구하기
(주의! 루트를 지우지 말라는 법이 없으므로 루트 지울떄를 고려하라!)
*/

/*느낀점
1. 트리 문제는 문제의 조건을 매우 꼼꼼하게 읽어야 함
(이진인지 아닌지, 아니면 어떤식으로 표현하는지, 루트가 어느 놈인지)
2. 구조체 정의시 내부 포인터 변수는 값 초기화 안하면 자동 NULL
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
	node* parent;
	vector<node*> child;
}NODE;

int N;
NODE nodeArray[10000];
int cut;

int leaf;

void cnt_leaf(NODE* start) {
	bool isLeaf=true;
	for (int i = 0; i < start->child.size(); ++i){
		if (start->child[i] != NULL) {
			isLeaf = false;
			break;
		}
	}
	if (isLeaf) leaf++;

	for (int i = 0; i < start->child.size(); ++i) {
		if (start->child[i] != NULL) cnt_leaf(start->child[i]);
	}
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
		nodeArray[parent].child.push_back(&nodeArray[i]);
	}

	//자르기 시작
	cin >> cut;
	
	//해당 놈이 루트면 그냥 0
	if (nodeArray[cut].parent == NULL) leaf = 0;
	//아니면 해당 놈의 부모를 자르기
	else {
		for (int i = 0; i < nodeArray[cut].parent->child.size(); ++i)
			if (nodeArray[cut].parent->child[i] == &nodeArray[cut])
				nodeArray[cut].parent->child[i] = NULL;
		
		//자른후 탐색 시작
		for (int j = 0; j < N; ++j)
		{
			if(nodeArray[j].parent == NULL)	cnt_leaf(&nodeArray[j]);
		}

	}
	

	cout << leaf;
}