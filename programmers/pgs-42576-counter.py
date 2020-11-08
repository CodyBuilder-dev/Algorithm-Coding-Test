import collections

def solution(participant, completion):
    part = collections.Counter(participant)
    comp = collections.Counter(completion)
    
    
    return list((part - comp).keys())[0]


participant = ["leo", "kiki", "eden"]
completion = ["eden", "kiki"]

result = solution(participant, completion)
print(result)