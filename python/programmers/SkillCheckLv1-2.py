def do_command(array,command) :
    if command[1] == len(array) :
        cut_array = array[command[0]-1:]
    else :
        cut_array = array[command[0]-1:command[1]]

    return sorted(cut_array)[command[2]-1]

def solution(array, commands):
    result =[]
    for command in commands :
        result.append(do_command(array,command))
    return result

if __name__ == "__main__" :
    array=[1, 5, 2, 6, 3, 7, 4]
    commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

    print(solution(array,commands))