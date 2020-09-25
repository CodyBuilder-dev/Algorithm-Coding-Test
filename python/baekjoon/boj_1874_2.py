"""
문제 개요 : 스택을 이용한 수열 출력이 가능한지 묻는 메타문제...
접근 방식 : 이거 한번 maximum 찍고 나면, 그 뒤로는 내림차순이어야만 YES다
-> 그럼 중간에 maximum 확인과 내림차순 확인 로직을 넣어보자
동작 순서 :
1. 숫자를 받는다. 이때 한번에 미리 다 받아둬야 한다.
2. 현재 포인터와 스택의 최상단을 본다
3. 현재 포인터가 maximum이면 내림차순을 본다
4. 내림차순이 안되면 바로 탈출
5. 내림차순이 되면 정상 진행
정답 여부 : Y
"""


if __name__ == "__main__" :
    required_list = []
    stack =  []
    op_list = []
    next_num = 1
    N = int(input())
    for i in range(N) :
        required_list.append(int(input()))

    for i in range(N) :
        # 내림차순 검증로직
        # if문 반복으로 인해 더 느려지는듯ㅜㅜ
        isDesc = True
        if required_list[i] == N :
            for j in range(i,N-1) :
                if required_list[j] < required_list[j+1] :
                    isDesc = False
                    break
        if isDesc == False : 
            op_list = []
            break

        # push 하기
        while next_num <= required_list[i] :
            stack.append(next_num)
            op_list.append('+')
            next_num += 1
        
        # pop 하기 -> 문제 발생시 break
        if stack[-1] == required_list[i] :
            # del stack[-1] 보다 pop()이 빠르다
            stack.pop()
            op_list.append('-')
        else :
            op_list = []
            break
    
    if len(op_list) != 0 :
        for op in op_list :
            print(op)
    else :
        print("NO")
        
        
    
