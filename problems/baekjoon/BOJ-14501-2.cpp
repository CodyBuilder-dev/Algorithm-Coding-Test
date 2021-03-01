//제목 : 퇴사
//목적 : 상담표를 보고, 남은기간 중 수익이 최대로 되도록 상담 잡기
//조건 : N<15이므로, 다 따져봐도 2^15 = 32000정도. O(NlogN)으로 할만 함


/*아이디어2 : 제한조건이 굉장히 많으므로, 어떻게 제한조건을 만족시킬지 생각해야 함
1. 일자별로 할지 안할지를 중복순열을 통해 선택
2. for문을 돌면서, 각 날짜별로 valid한지 살펴봄
3. 조건에 안 맞으면 거름
4. 조건에 맞으면 수익 max랑 비교해서 저장
(문제에서는 1,2..N순이지만 인덱스는 0,1,...N-1주의
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> days;
vector<int> pays;
vector<int> dayIdx;

int maxPay = 0; 

int day_check(vector<int>dayIdx)
{
	for (int i = 0; i < N; ++i) //0~N-1
	{
		if (dayIdx[i] == 1) //특정일이 선택되어있으면
		{
			if (i + days[i] > N) //퇴사일 초과시 -1
				return -1;
			for (int j = 1; j < days[i]; ++j) //해당일로부터 순서대로 검사
				if (dayIdx[i + j] == 1) return -1;//불가능시 -1
			
		}
	}
	return 1;
}

//주의점 : 미리 set은 아무 값이든 넣어서 size를 할당해둔후 써야 함
void repeatedPerm(vector<int> set, int setSize, int n, int r) {
	//종료 조건
	if (setSize == r) {
		if (day_check(set) == -1) return;
		else {
			int sum = 0;
			for (int j = 0; j < set.size(); ++j)
				if(set[j] == 1) sum += pays[j];
			maxPay = max(sum, maxPay);
		}
		return;
	}
	//분기 조건
	for (int i = 0; i < n; ++i) {
		set[setSize] = i;
		repeatedPerm(set, setSize + 1, n, r);
	}
}

int main()
{

	cin >> N;
	//일자, 수익 받아오기




	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		days.push_back(a);
		pays.push_back(b);
		dayIdx.push_back(0);
	}
	
	
	//여기서부터 본격적인 코딩 시작
	repeatedPerm(dayIdx, 0, 2, N);
	cout << maxPay;
	return 0;
}