//제목 : 우수 마을
//목적 : 트리구조를 가진 마을들 중에서 우수 마을을 최대한 선정하기
//조건 : 마을은 최대 1만개, 마을 주민은 최대 1만명

/*아이디어 :
1.node 구조체 안에 사람수 넣어 구현하기
2.두 마을 간 연결관계만 주어졌을 때, 트리 구조를 적절히 판단하여 트리 구현하기
3.합의 최대화 알고리즘...을 찾는데....
3.1 우수/비우수로 나눈 후 걔들이 조건에 만족하는지 탐색?
3.2 그리디로 제일 큰놈부터 꼽은 뒤 탐색?
*/

/*느낀점 :
1.트리라고 해서 반드시 부모-자식간의 계층관계로 이해할 필요 없는듯!
(그냥 사이클 없는 그래프 = 트리로 해석해도 됨)
2. 포인터의 벡터 사용할 때 조심해서 쓰기 ㅋㅋ
*/


#include <iostream>
#include <vector>

using namespace std;

int N;

typedef struct village{
	int people;
	vector<village*> near;
}VILL;

//typedef struct village {
//	int people;
//	village *near1;
//	village *near2;
//}VILL;

village villArray[10000];

int main()
{
	cin >> N;


	for (int i = 0; i < N; ++i)
		cin >> villArray[i].people;

	//연결관계 받기
	for (int i = 0; i < N - 1; ++i)
	{
		int start, end;
		cin >> start >> end;
		
		villArray[start - 1].near.push_back(&villArray[end - 1]);
		villArray[end - 1].near.push_back(&villArray[start - 1]);

		/*if (villArray[start - 1].near1 == NULL) villArray[start - 1].near1 = &villArray[end - 1];
		else villArray[start - 1].near2 = &villArray[end - 1];
		
		if (villArray[end - 1].near1 == NULL) villArray[end - 1].near1 = &villArray[start - 1];
		else villArray[end - 1].near2 = &villArray[start - 1];
		*/
	}

}