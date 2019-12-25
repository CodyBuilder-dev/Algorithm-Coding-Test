/*제목 : 하노이 탑 이동 순서
목적 : 하노이의 탑 최소 이동의 과정을 출력한다
조건 : 원판은 최대 20개
*/

/*아이디어 : 하노이의 탑 일반론
1. 하노이의 탑은 '뒤에서부터 거꾸로' 생각하면 된다
2. 맨 바닥을 목표로 이동하려면, 맨 바닥을 제외한 나머지가 목표 옆에 있어야 한다.
3. 나머지 모든 칸이 옆에 있으려면, N-1번째가 옆칸으로 가야되므로
*/

/*구현
0. 각각의 봉은 stack으로 구현한다.
stack은 equility를 비교하기 힘드므로, 최대 3*20 배열로 해도 된다.
배열은 index 처리 및 empty가 힘드므로, deque로 구현한다

1. N번째를 움직여 본다
2. N번째를 움직일 수 없으면, N-1번째를 옆으로 옮기는 작업을 수행한다.
3. N번째를 움직일 수 있으면 움직인다.
*/

/*느낀점 :
1. stack, queue등의 동일성을 비교하는 방법에 대해 생각해보기
2.
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<deque<int>> pillar(3);

void input_block()
{
	cin >> N;

	for (int i = 1; i <=N; ++i) {
		pillar[0].push_back(i);
	}
}

int find_pillar(int size)
{
	int pillarnum;
	for (int i = 0; i < 3; ++i) {
		if (find(pillar[i].begin(), pillar[i].end(), size) != pillar[i].end()) //찾아내면
			pillarnum = i;
	}
	return pillarnum;
}
void move_block(int maxsize, int size, int end)
{
	int start = find_pillar(size);
	bool selected[3] = { 0, };
	selected[start] = true;
	selected[end] = true;
	int middle;
	for (int i = 0; i < 3; ++i) {
		if (selected[i] == false) middle = i;
	}
	
	if (size == 1) { //사이즈가 1인 경우
		pillar[start].pop_front();
		pillar[end].push_front(size);
		cout << start + 1 << ' ' << end +1 << '\n';
		
	}
	
	move_block(size - 1, middle);


}
int main()
{
	input_block();
	move_block(N,2);

}

