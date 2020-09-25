//제목 : 수 정렬하기 2
//목적 : nlogn. 대표적으로는 병합 정렬, 힙 정렬,퀵정렬 쓸줄 아는가
//아이디어 : heap sort 구현, 자료구조는, 배열을 통해 힙을 만듬

/* 힙 정렬의 이해
발상 : 완전 이진트리를 이용해서 정렬을 해보자!
순서 :
1. 데이터를 앞에서부터 하나씩 힙에 넣는다.
2. 힙은 부모가 자식보다 무조건 크거나 작아야 하므로, 넣었을때 조건에 안 맞으면 부모랑 swap한다(힙에 넣기)

3. 끝까지 다 넣으면, 이제 루트를 가장 먼저 출력한다
4. 최고 말단을 루트에 넣고, 다시 힙을 정렬한다(출력 및 힙 정렬)

5. 힙이 빌 때 까지 3~4를 반복한다.

*/

/* 자료구조 : 힙 구현
방법 : 배열을 이용한 트리 구현
루트 : 인덱스가 1인 놈(0으로 하면 매우 불편하므로 1로 하는게 편함)
부모-자식 : 자식 인덱스 n, 부모 인덱스 n/2
*/

#include <iostream>

#define HEAP_SIZE 1000001

using namespace std;

int heap[HEAP_SIZE]; //힙 배열 정적할당.
int last_index = 0; //현재 힙의 마지막 위치(push할때 참조해야함)


void push(int data)
{
	heap[++last_index] = data; //일단 제일 끝에 데이터 추가
	
	int child_index = last_index; //방금 넣은 놈을 child로 지칭
	int parent_index = child_index / 2; //방금 넣은 놈의 부모를 찾기
	while (child_index > 1 && heap[parent_index] > heap[child_index])
	//root보다 밑에 있고, 부모가 자식보다 작으면 교환 돌입
	{
		//부모자식 데이터 바꾸기
		swap(heap[parent_index], heap[child_index]);
		child_index = parent_index; //자식 인덱스를 현 부모 인덱스로
		parent_index = child_index / 2; //새로운 부모를 가리킴
	}

	
}
int pop()
{
	//루트를 빼내고, 루트에다 맨 마지막 놈을 넣음
	//루트 자리에 들어간 놈이 자식들중에 최고 우선순위보다 딸리면
	//조건에 안 맞으므로 비교해서 교체
	//마찬가지로 반복해서 교체
	//더이상 반복 안 해도 되면 끝

	int result = heap[1]; //루트 빼낼 놈 미리 저장
	swap(heap[1], heap[last_index]); //맨 끝의 원소를 루트 위치로 보냄
	last_index--; //맨 끝은 이제 안 쓸 꺼니 last_index -1

	int parent_index = 1; //현재 root를 parent로 설정
	int child_index = parent_index * 2; //root의 child중 왼쪽 놈
	if (child_index + 1 <= last_index) {
		child_index = (heap[child_index] < heap[child_index + 1]) ?
			child_index : child_index + 1;
		//왼쪽놈이 작으면 왼쪽으로, 오른쪽 놈이 작으면 오른쪽으로

	}
	while (child_index <= last_index
		&& heap[parent_index] > heap[child_index])
	//부모가 자식보다 크면 교체 돌입
	{
		//부모자식 데이터 바꾸기
		swap(heap[parent_index], heap[child_index]);
		parent_index = child_index; //child가 이제 새로운 부모
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