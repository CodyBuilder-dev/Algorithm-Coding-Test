"""
접근 : dict를 만들고, key로 접근한 후, try/except문으로 접근한다

정답여부 : Y
(try/except문은 굉장히 느림에도 불구하고 이진탐색보다 빠르다)
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
        # print(1 if target_dict[source] else 0)
        try :
            target_dict[source]
            print(1)
        except :
            print(0)
            
