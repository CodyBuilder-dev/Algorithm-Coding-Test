"""
접근 : dict를 만들고, in으로 접근한다

정답여부 : Y
(dict의 in 원리 파악 필요)
"""
if __name__ == "__main__" :
    n = int(input())
    target_list = list(map(int,input().split()))
    
    m = int(input())
    source_list = list(map(int,input().split()))


    target_dict ={}
    for target in target_list :
        target_dict[target] = True
    
    for source in source_list :
        print(1 if source in target_dict else 0)
            
