//제목 : 숫자 카드2
//목적 : 손안의 N개 카드 중에 일치하는 것이 몇개 인지
//조건 : 카드 손안의 개수는 50만개, 카드에 쓴 수의 범위는 2천만가지, 즉 무식한 비교는 절대 불가능

/*아이디어 : 이분탐색으로 풀기
1. 일단 그냥 오름차순으로 정렬부터 한다.
2. 이분탐색 한다.
3. 탐색하는 값 찾으면 cnt를 올린다.
4. 원래 손안의 패에서 그놈을 뺀다.
2~4 반복
*/

/* 구현 : 이분탐색 재귀로 구현
데이터는 리스트로 구현

*/

//느낀점 : 벡터에서 값을 지우는 erase는 사용에 주의해야 한다.
//느낀점 : vector subscript out of range는 벡터 사용시 벡터크기 초과 인덱스 접근시 발생
//느낀점 : 오히려 삭제가 많으면 list가 나을 수도 있음
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> target;
int *find_array;
int N,M;
int temp_cnt = 0;
vector<int> cnt_array;

void bs(int left, int right, int find)
{
	//한번 들어가면, 값 다 찾을 때 까지 안나옴
	//값 다 찾고 더이상 못 찾으면 return
	if (left > right) { // 모든값 다 찾아서 더 없을 때
		cnt_array.push_back(temp_cnt);
		temp_cnt = 0;
		return;
	}

	int mid = (left + right) / 2;

	if (target[mid] == find) { //값 하나 찾았을 때
		temp_cnt++;
		target.begin()+mid = target.erase(target.begin()+mid);

		if(right==0) {
			cnt_array.push_back(temp_cnt);
			temp_cnt = 0;
			return;
		}
		bs(left, right-1, find);
	}
	else if (target[mid] > find) bs(left, mid - 1, find);
	else bs(mid + 1, right, find);

}

int main()
{
	scanf("%d", &N);

	int temp;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &temp);
		target.push_back(temp);
	}

	sort(target.begin(), target.end());

	//타겟 okay
	//for (int i = 0; i < N; ++i)
		//printf("%d ", target[i]);
	

	scanf("%d", &M);

	find_array = new int[M];

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);
	
	//for (int i = 0; i < M; ++i)
		//printf("%d ", find_array[i]);
	
	//여기서부터 이분탐색 코드 작성

	for (int i = 0; i < M; ++i)
		bs(0, N-1, find_array[i]);


	//-----------------------------
	for (int i = 0; i < M; ++i)
		printf("%d ", cnt_array[i]);
	
	return 0;


}