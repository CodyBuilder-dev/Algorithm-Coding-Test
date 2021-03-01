"""
"""
def get_input() :
    data = list(map(int,input().split()))
    return data

def check_direction(data) :
    isAsc = True
    isDesc = True

    for i in range(len(data)-1) :
        if (data[i] < data[i+1]) :
            isDesc = False
        elif (data[i] > data[i+1]) :
            isAsc = False
    
    if isAsc : print("ascending")
    elif isDesc : print("descending")
    else : print("mixed")
if __name__ == "__main__" :
    data = get_input()
    check_direction(data)