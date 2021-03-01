//제목 : 단어 공부
//목적 : 역시 checklist 사용 잘 하는지 못하는지 확인할라고
//조건 : 단어의 길이는 최대 100만

//아스키 코드 상으로는 a = 97 z = 122
//주의점 : 체크리스트 포인터의 sizeof는 4임. ㅇㅋ?

#include <iostream>
#include <string>

using namespace std;

void print_max(int* checklist)
{
	int max = -1;
	int maxidx = -1;
	int maxcnt = 0;
	int i = 0;
	while(checklist[i] != NAN)
	{
		if (max < checklist[i])
		{
			max = checklist[i];
			maxidx = i;
			maxcnt = 0;
		}
		else if (max == checklist[i]) maxcnt++;
		
		++i;
	}
	if (maxcnt == 0) cout << (char)(maxidx+65);
	else cout << '?' ;
}
int main()
{
	string str;
	int checklist[26] = { 0 };
	
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]>=65 && str[i]<=90) checklist[str[i] - 65]++;
		else checklist[str[i] - 97]++;
	}
	
	print_max(checklist);
	return 0;
}