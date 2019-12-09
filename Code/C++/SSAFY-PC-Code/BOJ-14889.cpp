//제목 : 스타트와 링크
//목적 : N명의 사람들을 스타트와 링크로 나눌 때, 팀의 능력치를 균등하게 나누기
/*조건
1. 어떤 사람은 다른 사람과 팀에 같이 들어가면 시너지가 생긴다
2. 이는 표로 나타낼 수 있다.
3. 팀의 능력치는 모든 시너지의 합이다.
*/

/*아이디어 :
1. 우선 N/2명씩 나눠서 인덱스를 준비한다.
2. 표를 탐색하며 인덱스 안의 시너지를 모두 더한다
3. 각팀별 최종합을 구해 빼서 차를 구한다.
4. 차의 최소값 출력
*/
/*구현 :
1. N/2 씩 나누는 방법은  N/2개의 1과 N/2개의 2를 준비한 후 같은 것이 있는 순열
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int **synergy;

int main()
{
	cin >> N;

	synergy = new int*[N];
	vector<int> teamSelect;

	for (int i = 0; i < N; ++i)
		synergy[i] = new int[N];

	int temp;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			cin >> temp;
			synergy[i][j] = temp;
		}
	
	for (int i = 0; i < N / 2; ++i){
		teamSelect.push_back(1);//스타트팀은 1
		teamSelect.push_back(2);//링크팀은 2
	}

	sort(teamSelect.begin(), teamSelect.end());

	int start, link;
	int minDifference=987654321;

	do {
		start = 0; link = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				if (teamSelect[i] == 1 && teamSelect[j] == 1) //스타트팀 팀원이면
					start += synergy[i][j];
				if (teamSelect[i] == 2 && teamSelect[j] == 2) //링크팀 팀원이면
					link += synergy[i][j];
			}
		if (minDifference > abs(start - link)) minDifference = abs(start - link);
	} while (next_permutation(teamSelect.begin(), teamSelect.end()));
	cout << minDifference;
}
