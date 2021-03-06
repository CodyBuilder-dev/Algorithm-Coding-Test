//제목 : 레벨 N 버거
//목적 : 규칙에 따라 버거를 만들 때, 아래부터 X장을 먹은 경우 패티의 장수
//조건 : 레벨은 최대 50, 먹는 수는 전체 다 먹을 수 있음

/*아이디어 : N버거의 규칙은 B - N-1 - P - N-1 -B이다.
즉 L0 = 1, L1 = 2*L0 +3, L2 = 2*L1 +3 ...이므로 등비수열이고,
총 크기는 표현범위를 아득히 넘어가므로 일일히 계산 못 한다.

패티의 개수 
*/
