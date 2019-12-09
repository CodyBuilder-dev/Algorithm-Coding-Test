//���� : Ʈ��
//���� : Ʈ���� �ڽ��� �߶���� �� ������ ���� ���ϱ�
//���� : ���� �ִ� 50��

/*���̵�� : �θ������� �־����Ƿ�, �̷κ��� ������� Ȯ��
(����! ���� Ʈ����� ���� �����Ƿ� ����Ʈ���� ¥�� Ʋ��!!)
1. �θ�� �ڽ� ����
2. �����ϴ°͸����� ������� ���� �𸣹Ƿ�, Ʈ�� �� ���鼭 ������� ���� �ľ�
3. Ư�� ��� ������ �� �ٽ� ������� ���� ���ϱ�
(����! ��Ʈ�� ������ ����� ���� �����Ƿ� ��Ʈ ����� ����϶�!)
*/

/*������
1. Ʈ�� ������ ������ ������ �ſ� �Ĳ��ϰ� �о�� ��
(�������� �ƴ���, �ƴϸ� ������� ǥ���ϴ���, ��Ʈ�� ��� ������)
2. ����ü ���ǽ� ���� ������ ������ �� �ʱ�ȭ ���ϸ� �ڵ� NULL
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
	node* parent;
	vector<node*> child;
}NODE;

int N;
NODE nodeArray[10000];
int cut;

int leaf;

void cnt_leaf(NODE* start) {
	bool isLeaf=true;
	for (int i = 0; i < start->child.size(); ++i){
		if (start->child[i] != NULL) {
			isLeaf = false;
			break;
		}
	}
	if (isLeaf) leaf++;

	for (int i = 0; i < start->child.size(); ++i) {
		if (start->child[i] != NULL) cnt_leaf(start->child[i]);
	}
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
		nodeArray[parent].child.push_back(&nodeArray[i]);
	}

	//�ڸ��� ����
	cin >> cut;
	
	//�ش� ���� ��Ʈ�� �׳� 0
	if (nodeArray[cut].parent == NULL) leaf = 0;
	//�ƴϸ� �ش� ���� �θ� �ڸ���
	else {
		for (int i = 0; i < nodeArray[cut].parent->child.size(); ++i)
			if (nodeArray[cut].parent->child[i] == &nodeArray[cut])
				nodeArray[cut].parent->child[i] = NULL;
		
		//�ڸ��� Ž�� ����
		for (int j = 0; j < N; ++j)
		{
			if(nodeArray[j].parent == NULL)	cnt_leaf(&nodeArray[j]);
		}

	}
	

	cout << leaf;
}