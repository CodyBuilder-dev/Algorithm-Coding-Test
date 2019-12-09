//제목 : 원자소멸 시뮬레이션
//유형 : 역시 시뮬레이션
/*
조건 : 원자 1000개, 
게임판 가로세로 크기는 2000, 즉 한개 원자는 총 2000개의 경로 가능

*/
/*
아이디어 : 여러 개의 객체가 움직일 때 어떻게 시뮬레이션 하는가?

아이디어 1 : 각 원자의 경로를 다 배열로 저장한 후 비교
문제점1 : 원자 1000개, 즉 1개씩 비교해보면 50만번
2000개에서 2000개 비교하는건 이분탐색 쓰면 2000*log2000 * 50만번 = 3억번
즉 시간초과 걸릴 확률이 높음

아이디어 2 : 현위치 점들의 structure의 vector에 저장하자
이동시키고 나서, vector를 순회해 pair의 x,y좌표가 같은게 있는지 확인하자
그럼 
문제점 2: 배열판은 2000*2000 =4백만, 즉 1초에 4백만개 탐색을 해야 함.
struct vector을 쓰면 좀 줄일 수 있음. 그래도 19초씩 걸림.
*/

/*최적화
1. 벡터 전역변수 -> 지역변수로
2. scanf사용
*/
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef struct element {
	int x;
	int y;
	int dir;
	int energy;
} ELEMENT;

int T; //테케갯수
int N; //원자갯수
int X, Y, Dir, K;//0북 1남 2서 3동

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		//벡터 초기화 구문
		vector<ELEMENT> vec;

		scanf("%d",&N);

		for (int j = 0; j < N; ++j)
		{
			ELEMENT tempElement;
			scanf("%d %d %d %d",&X,&Y,&Dir,&K);
			tempElement.x = X;
			tempElement.y = Y;
			tempElement.dir = Dir;
			tempElement.energy = K;
			vec.push_back(tempElement);
		}
		
		//여기서부터 코딩 시작
		//sum산출 종료는, 모든 원자들이 2000칸 이상 움직였을 때
		int time = 0;
		int sum = 0;
		while (time <= 2000)
		{
			time++;
			//원소 위치 변경
			for (int j = 0; j < vec.size(); ++j)
			{
				switch (vec[j].dir)
				{
				case 0: vec[j].x += dx[0]; vec[j].y += dy[0]; break;
				case 1: vec[j].x += dx[1]; vec[j].y += dy[1]; break;
				case 2: vec[j].x += dx[2]; vec[j].y += dy[2]; break;
				case 3: vec[j].x += dx[3]; vec[j].y += dy[3]; break;
				}
			}
			//원소 충돌 검사 및 합계
			//이분탐색하는게 답. 근데 생각해보니 정렬 안되네 ㅋㅋ 
			//어쩔수 없이 무식 제거방법 고고.
			//3개, 4개이상 충돌케이스 어떻게 처리할지 생각
			
			
			//누구랑 충돌하는지는 사실 상관없다.
			//같은놈 만나면 일단 그놈 좌표 어레이에 넣기
			//루프 끝날때 최종적으로 좌표 있는놈들 다 제거
			//제거할 때 그놈들 다 더하기
			//제거할 게 없는 경우 다음놈으로 바통 넘김
					
			/*
			타인의 아이디어 : 정렬시켜서 인접한 애들만 검사하기
			*/
			set<int> idx_set;
			for (int j = 0; j < vec.size(); ++j) {
				for (int k = 0; k < vec.size(); ++k) {
					ELEMENT tempElement = vec[k];
					if (j == k) continue;
					if (vec[j].x == tempElement.x && vec[j].y == tempElement.y)
						idx_set.insert(j);	//같을 경우 j 저장
				}

				//for (int k = 0; k< idx_array.size(); ++k)
					//printf("idx_array = %d ", idx_array[k]);


				//비교가 끝에 도달한 경우 어레이 정리
				set<int>::iterator itr;
				while(!idx_set.empty()){
					itr = idx_set.end();
					ELEMENT tempElement = vec[*itr];
					sum += tempElement.energy;
					vec.erase(vec.begin() + (*itr));
					idx_set.erase(itr);

				}
			}
		}

		printf("#%d %d\n", i, sum);
		//테케 끝. 에너지 출력			
	}


	return 0;
}