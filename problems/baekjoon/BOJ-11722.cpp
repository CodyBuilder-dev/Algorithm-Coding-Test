///제목 : 가장 긴 감소하는 부분 수열
//목적 : 수열이 주어진 경우, 감소하는 수열의 길이 중 가장 긴 것을 구하여라
//조건 : 수열의 길이는 최대 1000

/*아이디어 : DP로 해결하기
1.맨 오른쪽부터 길이 생성
2. 오른쪽으로 한칸 가면 최대 수열 길이는 +1 증가함?
2.맨 오른쪽으로부터 n번째의 수열 길이는  n-1번째까지 수열길이 + n-2까지의 수열길이...
*/

