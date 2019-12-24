//제목 : 숨바꼭질5
//목적 : 두 사람의 이동 규칙이 주어졌을 때, 수빈이가 동생을 만나는 시점을 계산하기
//조건 : 제한시간이 0.25초임 = 즉 2500만번 안에 풀어야 함

/*아이디어 : 예전 숨바꼭질 풀 때랑 비슷
1. 시간 변수 생성
2. for문 돌리기
3. 이동조건에 따라 갈수있는곳 표시
4. 동생이 거기 있나 체크
5. 없으면 큐에 넣고 넘기기
->시간도 같이 넣나 안넣나?
6. 동생은 계속 커지기만 하므로, 동생보다 작은 위치는 그냥 컷
*/
#include <iostream>
#include <queue>

using namespace std;

int time;
int subin;
int sis;
bool isOver;

priority_queue<int, vector<int>, greater<int>> minTime;

int main()
{
	cin >> subin >> sis;
	
	
	queue<int> timeQ;
	queue<int> sisQ;
	queue<int> subinQ;
	subinQ.push(subin);
	sisQ.push(sis);
	timeQ.push(time);

	if (subin == sis) cout << 0;
	else {
		while (!timeQ.empty()) {
			time = timeQ.front();
			sis = sisQ.front();
			subin = subinQ.front();
			timeQ.pop();
			sisQ.pop();
			subinQ.pop();

			if (sis > 500000) {
				isOver = true;
				break;
			}

			int nt = time + 1;
			int nsis = sis + nt;
			//각각의 세가지 경우 판단
			int nsubin = subin - 1;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else if (nsubin > nsis) { //1뺀게 크다면
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}

			nsubin = subin + 1;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else if (nsubin > nsis) //1뺀게 크다면
			{
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}
			nsubin = subin * 2;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else {
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}

		}

		if (minTime.empty()) cout << -1;
		else cout << minTime.top();
	}
}