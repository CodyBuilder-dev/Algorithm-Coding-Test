//���� : ���� ī��2
//���� : �վ��� N�� ī�� �߿� ��ġ�ϴ� ���� � ����
//���� : ī�� �վ��� ������ 50����, ī�忡 �� ���� ������ 2õ������, �� ������ �񱳴� ���� �Ұ���

/*���̵�� : �̺�Ž������ Ǯ��
1. �ϴ� �׳� ������������ ���ĺ��� �Ѵ�.
2. �̺�Ž�� �Ѵ�.
3. Ž���ϴ� �� ã���� cnt�� �ø���.
4. ���� �վ��� �п��� �׳��� ����.
2~4 �ݺ�
*/

/* ���� : �̺�Ž�� ��ͷ� ����
�����ʹ� ����Ʈ�� ����

*/

//������ : ���Ϳ��� ���� ����� erase�� ��뿡 �����ؾ� �Ѵ�.
//������ : vector subscript out of range�� ���� ���� ����ũ�� �ʰ� �ε��� ���ٽ� �߻�
//������ : ������ ������ ������ list�� ���� ���� ����
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> target;
int *find_array;
int N,M;
int temp_cnt = 0;
vector<int> cnt_array;

void bs(int left, int right, int find)
{
	//�ѹ� ����, �� �� ã�� �� ���� �ȳ���
	//�� �� ã�� ���̻� �� ã���� return
	if (left > right) { // ��簪 �� ã�Ƽ� �� ���� ��
		cnt_array.push_back(temp_cnt);
		temp_cnt = 0;
		return;
	}

	int mid = (left + right) / 2;

	if (target[mid] == find) { //�� �ϳ� ã���� ��
		temp_cnt++;
		target.begin()+mid = target.erase(target.begin()+mid);

		if(right==0) {
			cnt_array.push_back(temp_cnt);
			temp_cnt = 0;
			return;
		}
		bs(left, right-1, find);
	}
	else if (target[mid] > find) bs(left, mid - 1, find);
	else bs(mid + 1, right, find);

}

int main()
{
	scanf("%d", &N);

	int temp;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &temp);
		target.push_back(temp);
	}

	sort(target.begin(), target.end());

	//Ÿ�� okay
	//for (int i = 0; i < N; ++i)
		//printf("%d ", target[i]);
	

	scanf("%d", &M);

	find_array = new int[M];

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);
	
	//for (int i = 0; i < M; ++i)
		//printf("%d ", find_array[i]);
	
	//���⼭���� �̺�Ž�� �ڵ� �ۼ�

	for (int i = 0; i < M; ++i)
		bs(0, N-1, find_array[i]);


	//-----------------------------
	for (int i = 0; i < M; ++i)
		printf("%d ", cnt_array[i]);
	
	return 0;


}