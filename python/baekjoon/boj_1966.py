"""
접근방식 1 : 매번 검사를 하면 O(N), 이걸 N번 반복하니까 O(N^2)
접근방식 2 : 현재 Queue의 Max값을 저장해두면, 검사를 안하고 넘기면 되잖아
동작 순서 :
1. 쭉 돌면서 입력을 다 받는다
2. 중요도 순으로 Priority Queue 비스무리하게 만든다
3. 맨 앞에 놈이 중요도 젤 높은 놈이 맞는지 본다
4-1. 맞으면 pop
4-2. 틀리면 볼 필요도 없이 그냥 맨 뒤로
무한반복
자료구조 :
- 데이터의 우선순위와 식별자를 같이 넣기 위해서 dict를 쓸수밖에 없나?
-> 그럼 중복되는 우선순위를 못 넣음
"""

if __name__ == "__main__" :
    t = int(input())
    for i in range(t) :
        n,m = list(map(int,input().split()))
        value = list(map(int,input().split()))

        # 우선순위 정렬
        prior_list = sorted(value,reverse=True)

        print_order = 1
        while len(value) != 0 :
            if value[0] == prior_list[0] :
                if m == 0 : break
                value.pop(0)
                prior_list.pop(0)
                print_order += 1
                #m 위치 조절필요
                if m > 0 : m -= 1
                else : m = len(value) - 1
            else :
                value.append(value.pop(0))
                #m 위치 조절필요
                if m > 0 : m -= 1
                else : m = len(value) - 1
        print(print_order)