//제목 : 트리의 지름
//목적 : 트리의 두 노트를 선택해 양쪽으로 쫙 당겨서, 두 노드간의 거리를 최대로 하는 경우를 구하기
//조건 : 노드는 최대 1만개

/*아이디어 : 어차피 거리가 최대가 되려면 제일 말단 leaf끼리 재야됨
(이유? 임의의 start 노드로부터 not leaf 까지 거리 < start로부터 leaf 까지 거리)
1. 그럼 leaf간의 거리는 어떻게 구하는가?
2. 공통 조상 중 제일 밑에 있는놈으로부터의 거리가 leaf 간의 거리
3. 
*/

/*느낀점 :
1.최소 공통 조상은 (Least Common Ancestor)로 알고리즘이 따로 있음
2.간선에 가중치가 있는 트리를 다뤄보기
3.트리에서 입력받는 개수 잘 생각해보기
*/

#include <iostream>
#include <utility>

using namespace std;

int N;

typedef struct node {
	pair<node*,int> parent;
	pair<node*, int> left;
	pair<node*, int> right;
}NODE;

NODE nodeArray[10000];

int main()
{
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		int parent, child, cost;
		cin >> parent >> child >> cost;

		if (nodeArray[parent - 1].left.first == NULL){
			nodeArray[parent - 1].left.first = &nodeArray[child - 1];
			nodeArray[parent - 1].left.second = cost;
		}
		else{
			nodeArray[parent - 1].right.first = &nodeArray[child - 1];
			nodeArray[parent - 1].right.second = cost;
		}
	}


}
