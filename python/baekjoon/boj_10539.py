"""
느낀점 : 
- '평균'이라는 단어에만 집착하지말고 문제를 잘 읽자
"""
# statistics mean 사용
# > python 3.4 부터 사용 가능
# from statistics import mean
# print(mean(data))
# print(reduce(mean,data))

# 직접 담근 mean함수 사용
# 파이썬 list에는 mean 메소드가 없다
def mean (lst:list) :
    return sum(lst)/len(lst)

def reverse_mean(lst:list,i:int) :
    if i == 0 : return lst[i] * (i+1)
    else : return (lst[i] * (i+1)) - (lst[i-1] * i)

if __name__ == "__main__" :
    n, B = input(),list(map(int,input().split()))
    A = []
    
    # 평균으로부터 해당 항 수 구하는 식
    # 평균값 * 총 개수 = 총합
    # 해당 항 값 = 총합 - 이전항 까지의 총합
    
    #reduce 함수 사용
    # 사용하기 힘들 것 같음
    # from functools import reduce
    # print(reduce(mean,data))
    
    for i in range(len(B)) :
        A.append(reverse_mean(B,i))

    for v in A :
        print(v, end=' ')
    # print(A)

