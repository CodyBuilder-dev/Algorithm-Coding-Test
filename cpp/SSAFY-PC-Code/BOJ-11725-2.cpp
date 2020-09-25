//제목 : 트리의 부모 찾기
//목적 : 정수 tuple입력만으로 트리의 모양 만들어 내기
//조건 : 사실 이진트리라는 말은 없음. 노드의 개수는 최대 10^5

/*아이디어 : 2차원배열이 안되면, 링크드 리스트로 만들기
*/

/*아이디어 : 그래프도 아니고 트리를 2차원배열로 만들래니까 안되지
1. 구조체 만들기
2. 배열 만들기
3. 각 값 적절히 넣기
*/
#include <iostream>

using namespace std;

typedef struct {
	int left;
	int right;
	int value;
	int parent;
}NODE;

int N;
NODE* tree;
int main()
{
	cin >> N;
	//루트가1번이고 N개이므로 N+1크기로 설정해야 함
	tree = new NODE[N + 1];

	int a, b;
	
	pair<int, int>* pairArray; //pair의 배열 만들어봄 ㅋㅋ
	pairArray = new pair<int,int>[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		if (b < a) swap(a, b);
		pairArray[i] = make_pair(a, b);
	}

	for (int i = 0; i < N; ++i) //지금부터 pairArray로부터 NODE배열 생성
	{
		pairArray[i].first
	}

}
