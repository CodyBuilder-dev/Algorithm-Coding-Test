//���� : TGN
//���� : �������.���, ��ȸ����� ���� ���ͺб��� ����ϴ� �ſ� ���� ����

//������ : �Է��� �� \�� ���� ���ڱ� advertise�� �� �����µ� �ֱ׷���?

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