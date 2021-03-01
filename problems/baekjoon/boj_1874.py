"""
문제 개요 : 스택을 이용한 수열 출력이 가능한지 묻는 메타문제...
접근 방식 : 그리디로 접근하는게 맞나? -> 검증 필요
동작 순서 :
1. 숫자를 받는다
2. 현재 포인터와 스택의 최상단을 본다
3. push를 얼마나 해야 할지 본다
4. 적당히 쌓이면 pop을 한다
5. 해당 과정에서 pop에 문제가 생기면(다른 수가 나오면) error
무한반복
정답 여부 : Y
"""


if __name__ == "__main__" :
    stack =  []
    op_list = []
    next_num = 1
    N = int(input())

    for i in range(N) :
        required_num = int(input())
        # push 하기
        while next_num <= required_num :
            stack.append(next_num)
            op_list.append('+')
            next_num += 1
        
        # pop 하기 -> 문제 발생시 break
        if stack[-1] == required_num :
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
        
        
    
