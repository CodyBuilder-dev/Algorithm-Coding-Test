//���� : Ʈ���� ����
//���� : Ʈ���� �� ��Ʈ�� ������ �������� �� ��ܼ�, �� ��尣�� �Ÿ��� �ִ�� �ϴ� ��츦 ���ϱ�
//���� : ���� �ִ� 1����

/*���̵�� : ������ �Ÿ��� �ִ밡 �Ƿ��� ���� ���� leaf���� ��ߵ�
(����? ������ start ���κ��� not leaf ���� �Ÿ� < start�κ��� leaf ���� �Ÿ�)
1. �׷� leaf���� �Ÿ��� ��� ���ϴ°�?
2. ���� ���� �� ���� �ؿ� �ִ³����κ����� �Ÿ��� leaf ���� �Ÿ�
3. 
*/

/*������ :
1.�ּ� ���� ������ (Least Common Ancestor)�� �˰����� ���� ����
2.������ ����ġ�� �ִ� Ʈ���� �ٷﺸ��
3.Ʈ������ �Է¹޴� ���� �� �����غ���
*/

#include <iostream>
#include <utility>

using namespace std;

int N;

typedef struct node {
	pair<node*,int> parent;
	pair<node*, int> left;
	pair<node*, int> right;
}NODE;

NODE nodeArray[10000];

int main()
{
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		int parent, child, cost;
		cin >> parent >> child >> cost;

		if (nodeArray[parent - 1].left.first == NULL){
			nodeArray[parent - 1].left.first = &nodeArray[child - 1];
			nodeArray[parent - 1].left.second = cost;
		}
		else{
			nodeArray[parent - 1].right.first = &nodeArray[child - 1];
			nodeArray[parent - 1].right.second = cost;
		}
	}


}
