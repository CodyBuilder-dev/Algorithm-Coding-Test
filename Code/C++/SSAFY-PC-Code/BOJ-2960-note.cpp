//���� : �����佺�׳׽��� ü
//���� : �����佺�׳׽��� ü�� ���Ǵ�� ������ �� �ִ°�

/*����
1. �켱 �� �������� �������� ����? ->No
2. ����� ��� cnt ����
3. ó���� 1�� �ʱ�ȭ, �� �� 0���� ����. 
*/
#include <iostream>
//#include <cstring>

using namespace std;

char* prime;

int main()
{
	int N,K;
	cin >> N >> K;
	prime = new char[N+1](); //�׳� 0�ʱ�ȭ ���
	//memset(prime, -1, N+1); �̰� ���� �� �۵� �ȵǴ���?

	
	int cnt = 0;
	for (int i = 2; i<=N;++i)
		if (prime[i] == 0)
		{
			prime[i] = 1;
			cnt++;
			if (cnt == K) cout << i;
			for (int j = 2 * i; j <= N; j += i) {
				if(prime[j] == 0){
					prime[j] = 1;
					cnt++;
					if (cnt == K) cout << j;
				}
			}
			
		}
}