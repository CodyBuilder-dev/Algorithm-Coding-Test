//제목 : 일곱 난쟁이
//목적 : 9개의 수 중에 합이 100이되는 수 7개 찾기

//아이디어 : 일단 다 받고, 합 100 될떄까지 loop 고고
/*구현 : 
1.STL 벡터로 구현해보기
2.7개 선택은... 9C7이므로 조합을 쓸 수밖에 없는듯
3. 조합을 안 쓰고 완탐으로 하려면...부분집합이므로 7중 for문?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> dwarfs;
	vector<int> idx;
	
	int temp;
	for (int i = 0; i < 9; ++i){
		cin >> temp;
		dwarfs.push_back(temp);
	}

	sort(dwarfs.begin(), dwarfs.end());

	for (int i = 0; i < 7; ++i)
	{
		idx.push_back(1);
	}
	for (int i = 7; i < 9; ++i)
	{
		idx.push_back(0);
	}

	sort(idx.begin(), idx.end());
	
		
	do {
		int sum = 0;
		for (int i = 0; i < 9; ++i)
			if (idx[i] == 1)
				sum += dwarfs[i];
		//cout << sum<<'\n';
		if (sum == 100) {
			for (int i = 0; i < 9; ++i)
				if (idx[i] == 1)
					cout << dwarfs[i] << '\n';
			break;
		}
	} while (next_permutation(idx.begin(), idx.end()));

}