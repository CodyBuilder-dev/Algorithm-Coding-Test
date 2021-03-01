//���� : ���� �˻� Ʈ��
//���� : ���� �˻�Ʈ���� ������ȸ�� ����κ���, Ʈ�� ������ �ľ��ϰ�, ������ȸ ����� ã�Ƴ���
//���� : ����� ������ �ִ� 1����

/*���̵�� : �켱 ������ȸ�� ����� �ľ�
1. ��Ʈ ��带 ��� ���� ����Ʈ����
2. ���� �۾��������� ��� �۰�
3. ��� ���� ���� ���� ����, �� �ڷδ� ������
4. ��Ʈ���� Ŀ���� �������ʹ� ������ ����Ʈ����
5. �ű⼭���� �ٽ� �۾��������� ����
6. ���Ѽ� ��� �ٽ� �ö���� ����
*/

/*���� : ������ �� ���� �� �� ������*/

/*������ 
1. node�� pair�� ���ÿ� �־��� �� ��, stack.top �� first�� second�� node�� ��������
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef struct node {
	int value;
	node* left;
	node* right;
}NODE;

/*
vector<pair<node*, int>> inputStack;
vector<pair<node*, int>>::iterator iter;
*/

NODE nodeArray[10000];//0��°�� ��Ʈ, �׵ڷ� ����Ʈ�������� 1,2,3,4...

void postorder(NODE* start) {
	if (start->left != NULL) postorder(start->left);
	if (start->right != NULL) postorder(start->right);
	cout << start->value << '\n';
}

int main()
{
	//��Ʈ ��� �� �ޱ�
	int value;
	int i = 0;

	
	while (cin >> value)
	{
		if (value == 0) break;
		
		if (i == 0) {
			nodeArray[i].value = value;
		}

		else {
			if (value < nodeArray[i - 1].value) //���� �����ְ� ������ ���� �� ���� ���ʿ� ���̱�
			{
				nodeArray[i].value = value;
				nodeArray[i - 1].left = &nodeArray[i];
			}
			else //���� �����ְ� ũ��, �� Ŀ�������� ���� �� �� �� ������ �����ʿ� ����
			{
				int j;
				for (j=i-1; j >= 0; --j)
				{
					if (nodeArray[j].value > value) break;
				}

				nodeArray[i].value = value;
				nodeArray[j].right = &nodeArray[i];
			}
		}
		i++;

	}

	postorder(&nodeArray[0]);

	return 0;
}