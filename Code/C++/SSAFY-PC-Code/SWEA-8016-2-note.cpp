#include <iostream>

using namespace std;

long long *pyramid;

int main()
{
	int test_case;
	int T;
	long N;
	long long height;
	long long index;
	long long width;
	long long cnt;
	long long*left;
	long long *right;

	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		cnt = 1;
		pyramid = new long long[N*N];
		left = new long long[N];
		right = new long long[N];

		for (height = 0; height < N; height++) {
			width = height * 2 + 1;
			for (index = 0; index < width; index++) {
				
				pyramid[(height)*(height) + index+1] = 2 * cnt - 1;
				if (index == 0) left[height] = 2 * cnt - 1;
				if (index == width-1) right[height] = 2 * cnt - 1;

				cnt++;
			}

		}
		
		cout << "#" << test_case << " " << left[N-1] << " " << right[N-1] << '\n';
	}
	return 0;
}