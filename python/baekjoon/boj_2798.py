"""
접근방식 : 카드가 3장이므로, 3중 for문을 쓰면 됨
정답여부 : Y
"""
n = 0
m = 0
max_sum = -987654321

def get_nm() :
    n,m = list(map(int,input().split()))
    return n,m

def get_list() :
    data = list(map(int,input().split()))
    return data

def get_card(data) :
    global max_sum
    for i in range(len(data)-2) :
        selected_card =[0]*3

        selected_card[0] = data[i]
        for j in range(i+1,len(data)-1) :
            selected_card[1] = data[j]
            for k in range(j+1,len(data)) :
                selected_card[2] = data[k]
                
                selected_sum = sum(selected_card)
                if selected_sum <= m :
                    max_sum = selected_sum if max_sum < selected_sum else max_sum

    print(max_sum)


    
if __name__ == "__main__" :
    n,m = get_nm()
    data = get_list()

    get_card(data)
    
