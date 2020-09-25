"""
접근방식 :자기자신을 뒤집어서 더함
정답여부 : N
틀린 이유 : 합이 9라고 해서 순서가 asc/desc라는 보장이 없음
"""

def set_data() :
    data = list(map(int,input().split()))
    return data

def reverse_data(data) :
    return [data[x] for x in range(len(data)-1,-1,-1)]
    
def reverse_data_test() :
    data = [1,2,3]
    print(reverse_data(data))

def check_direction(data) :
    isDir = True
    for i in [sum(x) for x in zip(data,reverse_data(data))] :
        if i != 9 : isDir = False
    
    if isDir : 
        if data[0] == 1 : return 0
        else : return 1
    else : return 2


if __name__ == "__main__" :
    cache = ["ascending","descending","mixed"]
    data = set_data()
    print(cache[check_direction(data)])

    
    