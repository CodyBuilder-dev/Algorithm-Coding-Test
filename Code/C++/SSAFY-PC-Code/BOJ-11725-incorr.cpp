//���� : Ʈ���� �θ� ã��
//���� : ���� tuple������ Ʈ���� ��� ����� ����
/*���̵�� : ��ũ�� ����Ʈ�� N�� �����
1. �̰Ŵ� ��¿ �� ����, �ϴ� �Է��� �� �ް�, 1�� �ִ� �� ���� ó���ϴ� �� �ۿ� ����.
2. �Է��� �޾Ƽ�, 2�� �迭�̳� Ʃ�� ���·� �����Ѵ�?
3. Ʃ���� ���� �� 1�� �մ� Ʃ�õ� ���� ó���Ѵ�
4. Ʃ���� ���� �� 3������ ó���� ����� �ִ� Ʃ�ú��� ó���Ѵ�
5. 4���� �ݺ��Ѵ�.
6. Ʈ�� �ϼ� �Ϸ�
*/

#include <iostream>

using namespace std;

struct node {
	struct node *next;
	int data;
};

int main()
{
	int N;
	//1�� ���� NODE[0], 2�� ���� NODE[1]...
	struct node *NODE;
	//input�� 1 6�̸� ���� [0] =1 , [1] =6
	int** input_storage;
	int* parent_check;

	cin >> N;

	input_storage = new int*[N];
	input_storage[0] = new int[2];
	input_storage[1] = new int[2];
	
	parent_check = new int[N];
	NODE = new struct node[N];
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> input_storage[i][0] >> input_storage[i][1];
		if (input_storage[i][0] == 1)
		{
			NODE[input_storage[i][1] - 1].next = &NODE[0];
			parent_check[input_storage[i][1] - 1] = 1;
		}
			
			
		else if (input_storage[i][1] == 1)
		{
			NODE[input_storage[i][0] - 1].next = &NODE[1];
			parent_check[input_storage[i][0] - 1] = 1;
		}
	}

	for
}