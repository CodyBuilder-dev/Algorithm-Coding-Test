//薦鯉 : 杷左蟹帖 敗呪
//鯉旋 : 杷左蟹帖研 仙瑛稽 承 凶 硲窒判呪研 姥廃陥.
//焼戚巨嬢 : 仙瑛稽 益撹 姥薄馬壱, 硲窒吃凶原陥 cnt++研 背爽澗 姥庚聖 蓄亜廃陥.
//庚薦繊 : 益撹 仙瑛稽 姥薄馬檎 獣娃 段引鞠惟 鞠嬢赤製せせせせせせせせ
//焼戚巨嬢2 : 疑旋拝雁 姥薄馬壱, 0,1 判呪亀 疑旋拝雁 馬澗暗績 せせ
//0,1生 判呪研 煽舌馬澗 切戟姥繕澗 pair
#include <iostream>
#include <utility>
using namespace std;

//n腰属 杷左蟹帖 呪税 0,1 硲窒 鯵呪研 煽舌馬澗 壕伸
pair<int, int> cnt[40];


pair<int,int> fibonacci(int n) {
	if (n == 0) {
		cnt[0].first = 1;
		cnt[0].second = 0;
		return cnt[0];
	}
	else if (n == 1) {
		cnt[1].first = 0;
		cnt[1].second = 1;
		return cnt[1];
	}
	else {
		if (cnt[n].first != 0 && cnt[n].second != 0) {
			return cnt[n];
		}
		else
		{
			cnt[n] = fibonacci[n - 1] + fibonacci[n - 2];
			return cnt[n];
		}
		
	}
}

int main()
{
	int T;
	int N;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> N;
		fibonacci(N);
		cout << cnt[N].first << ' ' << cnt[N].second << '\n';
	}

	return 0;
}