//제목 : 경매
//목적 : 입찰자 이름과 가격이 주어질 떄, 가장 낮은 가격, 가장 빨리 부른 사람을 찾아라

/*아이디어:
가격은 갯수만 세면 되고, 입찰자는 1명만 기록하면 된다
1. 가격 배열 만들어서 가격 들어올때마다 ++
2. 이름 배열은 만들어서 처음 사람이름만 더하기
*/

//느낀점 :
//string은 크기가 가변인데, 배열의 정적할당이 가능한가?
//-> 가능하다. 근데 엥간하면 쓰지 말자.선언시 쓰레기값 들어간다.
//스트링의 배열이 비어있는지 아닌지 어케 검사함
//-> char* 배열로 만든 후 비교
//-> string 배열 시 NULL,\0등으로 compare해도 오류 나므로, 그냥 for문으로 수동으로 초기화해서 비교하거나 아예 쓰지 말자
//빈문자열 검사시 nullptr이 쓸모있는가?
//cin은 스트링이나 char*받기엔 부적합한가?
#include <iostream>
#include <string>

using namespace std;

int U, N;
int price[10001];
char* name[10001];
//string name[10001]; <- not good
int main()
{
	cin >> U >> N;

	char* tempName = { 0 };
	int tempPrice;

	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d", tempName, &tempPrice);
		if (strcmp(name[tempPrice],NULL) == 0 ) name[tempPrice] = tempName;
		price[tempPrice]++;

	}
	int minima = 987654;
	for (int i = 0; i <= N; ++i)
	{
		if (price[i] == 0)continue;
		minima = (minima > price[i]) ? i : minima;
	}
	cout << name[minima] << ' ' << minima;
}