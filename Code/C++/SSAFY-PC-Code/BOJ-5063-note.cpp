//제목 : TGN
//목적 : 광고수익.비용, 기회비용을 통해 손익분기점 계산하는 매우 쉬운 버전

//주의점 : 입력할 때 \가 들어가면 갑자기 advertise로 쭉 나오는데 왜그럴까?

#include <iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	int r, e, c;
	for (int i = 0; i < N; ++i){
		scanf("%d %d %d", &r, &e, &c);
		if (r > e - c) printf("do not advertise\n");
		else if( r< e-c) printf("advertise\n");
		else printf("does not matter\n");
	}

}