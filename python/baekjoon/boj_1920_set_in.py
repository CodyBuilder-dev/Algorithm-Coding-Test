"""
접근 : set 을 만들면 바로 체크 가능

정답여부 : Y
(set의 in 원리를 찾아내야 함)
"""
if __name__ == "__main__" :
    n = int(input())
    target_set = set(map(int,input().split()))
    
    m = int(input())
    source_list = list(map(int,input().split()))
       
    for source in source_list :
        print(1 if source in target_set else 0)
