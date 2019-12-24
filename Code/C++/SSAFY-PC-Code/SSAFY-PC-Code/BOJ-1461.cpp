//제목 : 도서관
//목적 : 한번에 들 수 있는 책 권수가 주어질 때, 최소걸음으로 책을 원상복귀 시키는 방법
//조건 : 책의 개수는 10^4개 이하

/*아이디어 : 브루트포스로 모든 경우에 대해 최단경로 찾는건 개 에바고,
최단거리 규칙을 찾아내서 구현해야함
1. 책은 무조건 최대로 드는게 좋다
2. 한방향으로 최대한 간 뒤, 놓으면서 돌아오는 식으로 하는게 좋다.
3. 즉, 한 방향으로 간 뒤, 놓으면서 오고, left max를 기록한다.
4. 반대방향으로도 간 뒤, right max기록한다.
5. 다 놔두고 돌아올 필요 없으므로, 마지막에 가장 멀리 가는게 좋다.
*/

/*구현 : (X)
1. 책 위치를 인덱스로 갖는 visited 배열을 만든다
2. 음수의 경우는 어떻게 처리해야 하냐면... 중간값을 0으로 한다.
3. 책을 놔두었을 시 배열값 1로 바꾼다.
*/

/*구현2 : 굳이 방문할 필요가 있나?
1.그냥 받아서 정렬한다
2.일단 최단거리 간다.
3. 거기서부터 M권 다 떨어질 때 까지 최단거리 찾아서 간다.
3. 최대거리가 짧은 놈 부터 간다.
*/

//느낀점 : 사실 내 논리의 증명은 못함. 증명하려면 엄밀하게 어떻게 해야 될까

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> bookidx;

int main()
{
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; ++i){
		cin >> temp;
		bookidx.push_back(temp);
	}	
	
	sort(bookidx.begin(), bookidx.end());

	//여기서부터 코드작성
	int now = 0;
	int total = 0;
	while(!bookidx.empty()){
		int hand = M;
		while (hand > 0) {
			if (bookidx.empty()) break;
			
			int mindis = 987654;
			int tempnow = 987654;
			int tempidx = 987654;

			for (int i = 0; i < bookidx.size(); ++i) //현위치 최단도달점 찾기
			{
				int tempmin = abs(bookidx[i] - now);

				if (tempmin < mindis)
				{
					mindis = tempmin;
					tempnow = bookidx[i];
					tempidx = i;
				}
			}
			total += mindis;
			bookidx.erase(bookidx.begin() + tempidx);
			now = tempnow;
			hand--;
		}
	}
	cout << total;
}

