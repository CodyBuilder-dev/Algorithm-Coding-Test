//���� : �� �����ϱ� 2
//���� : nlogn. ��ǥ�����δ� ���� ����, �� ����,������ ���� �ƴ°�
//���̵�� : heap sort ����, �ڷᱸ����, �迭�� ���� ���� ����

/* �� ������ ����
�߻� : ���� ����Ʈ���� �̿��ؼ� ������ �غ���!
���� :
1. �����͸� �տ������� �ϳ��� ���� �ִ´�.
2. ���� �θ� �ڽĺ��� ������ ũ�ų� �۾ƾ� �ϹǷ�, �־����� ���ǿ� �� ������ �θ�� swap�Ѵ�(���� �ֱ�)

3. ������ �� ������, ���� ��Ʈ�� ���� ���� ����Ѵ�
4. �ְ� ������ ��Ʈ�� �ְ�, �ٽ� ���� �����Ѵ�(��� �� �� ����)

5. ���� �� �� ���� 3~4�� �ݺ��Ѵ�.

*/

/* �ڷᱸ�� : �� ����
��� : �迭�� �̿��� Ʈ�� ����
��Ʈ : �ε����� 1�� ��(0���� �ϸ� �ſ� �����ϹǷ� 1�� �ϴ°� ����)
�θ�-�ڽ� : �ڽ� �ε��� n, �θ� �ε��� n/2
*/

#include <iostream>

#define HEAP_SIZE 1000001

using namespace std;

int heap[HEAP_SIZE]; //�� �迭 �����Ҵ�.
int last_index = 0; //���� ���� ������ ��ġ(push�Ҷ� �����ؾ���)


void push(int data)
{
	heap[++last_index] = data; //�ϴ� ���� ���� ������ �߰�
	
	int child_index = last_index; //��� ���� ���� child�� ��Ī
	int parent_index = child_index / 2; //��� ���� ���� �θ� ã��
	while (child_index > 1 && heap[parent_index] > heap[child_index])
	//root���� �ؿ� �ְ�, �θ� �ڽĺ��� ������ ��ȯ ����
	{
		//�θ��ڽ� ������ �ٲٱ�
		swap(heap[parent_index], heap[child_index]);
		child_index = parent_index; //�ڽ� �ε����� �� �θ� �ε�����
		parent_index = child_index / 2; //���ο� �θ� ����Ŵ
	}

	
}
int pop()
{
	//��Ʈ�� ������, ��Ʈ���� �� ������ ���� ����
	//��Ʈ �ڸ��� �� ���� �ڽĵ��߿� �ְ� �켱�������� ������
	//���ǿ� �� �����Ƿ� ���ؼ� ��ü
	//���������� �ݺ��ؼ� ��ü
	//���̻� �ݺ� �� �ص� �Ǹ� ��

	int result = heap[1]; //��Ʈ ���� �� �̸� ����
	swap(heap[1], heap[last_index]); //�� ���� ���Ҹ� ��Ʈ ��ġ�� ����
	last_index--; //�� ���� ���� �� �� ���� last_index -1

	int parent_index = 1; //���� root�� parent�� ����
	int child_index = parent_index * 2; //root�� child�� ���� ��
	if (child_index + 1 <= last_index) {
		child_index = (heap[child_index] < heap[child_index + 1]) ?
			child_index : child_index + 1;
		//���ʳ��� ������ ��������, ������ ���� ������ ����������

	}
	while (child_index <= last_index
		&& heap[parent_index] > heap[child_index])
	//�θ� �ڽĺ��� ũ�� ��ü ����
	{
		//�θ��ڽ� ������ �ٲٱ�
		swap(heap[parent_index], heap[child_index]);
		parent_index = child_index; //child�� ���� ���ο� �θ�
		child_index = parent_index*2;
		if (child_index + 1 <= last_index) {
			child_index = (heap[child_index] < heap[child_index + 1]) ? child_index : child_index + 1;
		}

	}
	return result;


}

int main()
{
	int N;
	int temp;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		push(temp);
	}

	for (int i = 0; i < N; ++i) {
		temp = pop();
		cout << temp << '\n';
	}
}