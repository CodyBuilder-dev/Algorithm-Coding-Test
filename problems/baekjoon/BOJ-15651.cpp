//제목 : N과 M(3)
//목적 : 같은수를 여러번 골라도 되는 수열
//조건 : M,N이 7이하로 크지 않음.
//그냥 7!해도 5천정도니 괜찮을듯
/*
아이디어 : 즉, 중복순열을 구하는 것이다.
이건 근데 졸라 쉬운게,재귀로 for문 돌리면 된다.
for문 돌릴때 종료조건만 좀 복잡하게 짜주면 가능
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> numvec;

void print_dupperm(int n, int r)
{
	if (r == 0) {
		for (int j = 0; j < numvec.size(); ++j)
			cout << numvec[j] << ' ';
		if (!numvec.empty() && (numvec.back() == n)) {
			do {
				numvec.pop_back();
			} while (numvec.back() == n);
			if(!numvec.empty())numvec.pop_back();
		}
		else numvec.pop_back();
		printf("\n"); return;
	}

	for (int i = 1; i <= n; ++i)
	{
		numvec.push_back(i);
		print_dupperm(n, r - 1);
		
	}
	
}

int main()
{

	cin >> N >> M;

	print_dupperm(N, M);
}