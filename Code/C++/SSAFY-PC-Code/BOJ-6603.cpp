//제목 : 로또
//목적 : 1~49 수 중에서 k개를 고른 후, 해당 수 중에서 6개 고르기
//조건 : 숫자가 49개이므로 2^49 = 560조... 과연?!

/*아이디어: 1 2 3 4 5 6 7 이랑 1 2 3 4 5 6 7 8이랑 중복 엄청됨
1. 중복을 제거하려면 메모이제이션을 쓴다
2. 그나마 다행인건 문제 입력에 딱 k와 S가 주어짐.
3. 따라서 그냥 입력대로 조합 하면 됨
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	int k;


	while(1)
	{
		cin >> k;
		if (k == 0) break;
		int temp;
		vector<int> S;
		vector<int> idx;
		for (int i = 0; i < k; ++i) {
			cin >> temp;
			S.push_back(temp);
		}
		for (int i = 0; i < 6; ++i)
			idx.push_back(1);
		for (int i = 6; i < k; ++i)
			idx.push_back(0);

		//소팅 해야되나? 글쎄
		//여기서부터 본격적인 코딩 시작
		do
		{
			for (int i = 0; i < k; ++i)
				if (idx[i] == 1) printf("%d ", S[i]);
			printf("\n");
		} while (prev_permutation(idx.begin(), idx.end()));
		printf("\n");
	}
}