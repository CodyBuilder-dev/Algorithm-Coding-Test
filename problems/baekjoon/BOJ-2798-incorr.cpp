//���� : ����
//���� : �Է��� ������������ �����Ƿ� �ڿ������� Ž��?!
//���� : ī��� �ִ� 100��, ī���� ���� �ִ� 30��, 

/*���̵�� : for���� 3�� ��ߵǳ� ���ƾߵǳ� �̰� ����ϰ� �־���*/
//������ : ������ ���� ��¥ �������̾�����
#include <iostream>

#define MAX_LEN 101

using namespace std;

int main() {
	int N, M;
	int arr[MAX_LEN];
	int selected[MAX_LEN];

	cin >> N >> M;
	
	int sum = 0;
	int cur_max = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int a = 0; a < N; a++) {
		sum = 0;
		for (int i = 0; i < N; i++)
			selected[i] = 0;
		
		selected[a] = 1;
		if(M > arr[a]) sum += arr[a];
		else continue;

			for (int b = 0; b < N; b++)
			{
				if (selected[b] != 1) {
					selected[b] = 1;
					if (sum + arr[b] > M) break;
					sum += arr[b];
				}
				else continue;
				for (int c = 0; c < N; c++) {
					if (selected[c] != 1) {
						selected[c] = 1;
						if (sum + arr[c] > M) continue;
						sum += arr[c];
					}
					
				}
			}
		if (sum > cur_max) cur_max = sum;
		
	}
	cout << sum;
}