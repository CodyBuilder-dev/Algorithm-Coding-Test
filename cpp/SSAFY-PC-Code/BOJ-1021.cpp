//제목 : 회전하는 큐
//목적 : 주어진 조건대로 동작하는 회전하는 큐 자료구조를 만든다.

/*아이디어 : 
1. 첫번째 원소를 뽑는다 : 첫번째 원소를 제거한 후, 다른 원소를 한칸씩 당긴다
2. 왼쪽으로 한칸 이동 : 첫번째 원소를 저장한 후, 다른 원소 한칸씩 당기고 맨 뒤에 넣는다
3. 오른쪽 한칸 이동 : 위와 비슷한데 방향이 반대
*/

/*구현 : (0번지에 1, 1번지에 2들어감에 주의)
1.삽입, 메모리 이동, 삭제가 빈번하게 일어나므로,
STL중에 deque를 써보는게 맞는거 같다.
2. deque 메소드중에 내가 정확하게 원하는 게 없으므로,
필요한 메소드는 작성해서 구현한다.
3. 숫자를 받으면, 해당 숫자의 위치 파악
4. 왼쪽이 가까우면 왼쪽으로, 오른쪽이 가까우면 오른쪽으로
5. 1회 수행시마다 횟수 +1
6. 최종적으로 다 끝나면 횟수 출력
*/

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int N, M;
int total=0;

void rotate_right()
{
	if (!dq.empty()) {//맨 뒷자리를 맨 앞으로
		int last = dq.back();
		dq.pop_back();
		dq.push_front(last);
		total++;
	}
	else cout << "empty!\n";
}
void rotate_left()
{
	if (!dq.empty()) {//맨 앞자리를 맨 뒤로
		int first = dq.front();
		dq.pop_front();
		dq.push_back(first);
		total++;
	}
	else cout << "empty!\n";
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);
	/*순차접근 잘 되는거 확인
	for (int i = 0; i < N; ++i)
		cout << dq[i];
	*/

	/*dq size 잘 되는가 확인
	cout << dq.size();
	*/

	int numarray[50];
	for (int i = 0; i < M; ++i)
	{
		cin >> numarray[i];
	}

	for (int i = 0; i<M;++i){
		int idx;
		for (int j = 0; j < dq.size(); ++j) //idx찾기
			if (dq[j] == numarray[i]) idx = j;

		while (!idx == 0)
		{

			if (idx <= dq.size() / 2){
				rotate_left();
				idx--;
			}
			else{
				rotate_right();
				if (idx == dq.size() - 1) idx = 0;
				else idx++;
			}
		}
		dq.pop_front();
				
	}
	
	cout << total;
}