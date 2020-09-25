//���� : Ʈ��
//���� : Ʈ���� �ڽ��� �߶���� �� ������ ���� ���ϱ�
//���� : ���� �ִ� 50��

/*���̵�� : �θ������� �־����Ƿ�, �̷κ��� ������� Ȯ��
(����! ���� Ʈ����� ���� �����Ƿ� ����Ʈ���� ¥�� Ʋ��!!)
1. �θ�� �ڽ� ����
2. �����ϴ°͸����� ������� ���� �𸣹Ƿ�, Ʈ�� �� ���鼭 ������� ���� �ľ�
3. Ư�� ��� ������ �� �ٽ� ������� ���� ���ϱ�
*/

/*������
1. ����ü ���ǽ� ���� ������ ������ �� �����ϸ� �ڵ� NULL
*/
#include <iostream>

using namespace std;

typedef struct node {
	node* parent;
	node* left;
	node* right;
}NODE;

int N;
NODE nodeArray[10000];
int cut;

int leaf=0;

void cnt_leaf(NODE* start) {
	if (start->left == NULL && start->right == NULL)
		leaf++;

	if (start->left != NULL) cnt_leaf(start->left);
	if (start->right != NULL) cnt_leaf(start->right);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int parent;
		cin >> parent;
		if (parent == -1) continue;

		nodeArray[i].parent = &nodeArray[parent];
		if (nodeArray[parent].left == NULL)
			nodeArray[parent].left = &nodeArray[i];
		else nodeArray[parent].right = &nodeArray[i];
	}

	cin >> cut;
	//�ڸ��� ����
	//�θ�� ã�ư���, �������� ���������� ���� �ڸ���

	if (nodeArray[cut].parent->left == &nodeArray[cut])
		nodeArray[cut].parent->left = NULL;
	else if (nodeArray[cut].parent->right == &nodeArray[cut])
		nodeArray[cut].parent->right = NULL;

	nodeArray[cut].parent = NULL;

	//�ڸ��� Ž�� ����
	cnt_leaf(&nodeArray[0]);

	cout << leaf;
}