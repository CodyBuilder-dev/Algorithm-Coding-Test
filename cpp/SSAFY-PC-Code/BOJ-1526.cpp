//���� : ���� ū �ݹμ�
//���� : �ݹμ��� 4�� 7�θ� �̷���� �� , Ư�� ���� �ݹμ� �� ���� ū ���� ����Ͻÿ�
//���� : �ִ� 10^6���� �־�����.

/*���̵��1 : 100�������� ���� �Ź� ���ڸ����ڸ� ���캻�ٸ�,
�ð����⵵ = �ִ� �ڸ��� 7�ڸ� * 100�� = O(7*10^6)
1.1���� N���� for�� 
2.���� ���ڸ� string���� ����� -> atoi�� �ݴ�
3.string�� 0�������� ����������
4.�ݹμ��� ��� ����
*/

/*���̵��2 : �� ������ �Է� �޾Ƽ� �ڸ��� Ȯ���ϰ� �ű� �´� �ݹμ� �����
1. �Է� ��ü�� �Ѱ��� �ޱ�
2. �ڸ��� Ȯ��
3. �� ���ڸ� �Ǵ�. 4�̸��̸� ���ڸ� ����, 4�̻� 7�̸��̸� 4XXX 7�̻��̸� 7
4. �ݹμ� ����
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

int main()
{
	int temp;
	while (true) {
		if (!scanf("%1d", &temp)) break;
		if (temp < 4) continue;
		else if (temp >= 4 && temp < 7) result.push_back(4);
		else result.push_back(7);
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i];
		
}