def no_continuous(s):
    a = []
    for i in s:
        if a[-1:] == [i]: continue
        a.append(i)
    return a

arr = [1,3,3,3,0,3]
print(no_continuous(arr))