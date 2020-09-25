//제목 : 세수의 합
//목적 : 집합 내 원소들의 합이 그 집합에 포함되는가 여부(수학적으로 용어가 있을텐데)
//조건 : 원소 개수는 <=1000 집합의 원소는 <=2*10^9

/*
아이디어 : 
1. 브루트포스를 못할 줄 알았는데 1000개뿐이라 할만함
2. 근데 생각해보면 브루트포스 말고는 답이 없음
3. 속도를 향상시키기 위해 따라서, 뒤에서부터 더해가면서 풀면 될듯
*/

/*구현 :
index를 3개 선택하면 되므로 3중 for문. 어 이럼 10^9인데?
값은 2억*3까지이므로 6억, 즉 long long
값을 더해서 저장후 뒤에서부터 있는지 검사
검사후 max와 비교해 교체
*/
//문제점 : 시간초과 뜸 ㅋㅋ
//느낀점 : 자료 값의 크기와 개수의 크기를 잘 구분
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long> set;
	vector<long long>::iterator itr;
	vector<long long> failed;
	vector<long long>::iterator itr2;

	for (int i = 0; i < N; ++i){
		int temp;
		cin >> temp;
		set.push_back(temp);
	}
	//정렬은 되있나 안되있나 몰겠는데 일단 그냥 고고
	//정렬이 안돼서 시간초과일수도 있음. 정렬해보자
	sort(set.begin(), set.end());

	//아니면 메모이제이션 도입해야 될 수도 있음
	//이미 계산해본 값은 빼는거지.
	long long Sum;
	long long Max;
	int maxidx;
	for (int i = N - 1; i >= 0; --i)
		for (int j = N - 1; j >= 0; --j)
			for (int k = N - 1; k >= 0; --k){
				Sum = set[i] + set[j] + set[k];
				itr2 = find(failed.begin(), failed.end(), Sum);
				if (itr2 != failed.end()) continue;//failed안에 포함될 경우

				maxidx = max(j,k);
				maxidx = max(maxidx, i);
				itr = find(set.begin()+maxidx, set.end(), Sum);//find를 쓰되, 최소범위를 좁힐 수 있음
				if (itr != set.end())//find는 마지막 원소의 가능성을 열어두어야 함
					Max = max(Sum, Max);
				else if (Sum == set[N - 1])
					Max = max(Sum, Max);
				else
					failed.push_back(Sum);
			}

	cout << Max;
}



