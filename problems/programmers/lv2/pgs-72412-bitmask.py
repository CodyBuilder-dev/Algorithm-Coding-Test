"""
아이디어 : for 2개 완전탐색
- 5 * 10^4 * 10^5이므로 불가능

아이디어 : 비트마스크
- query를 순회하면서, 비트마스크로 계산
- 최종적으로 비트마스크의 True(=1)의 개수를 셈
-> python 문자열을 이용한 비트마스크는 생각보다 느리다
-> 시간 초과
"""

def solution(info, query):
    people_category = {}
    people_score = [0]*len(info)

    for i,person in enumerate(info) :
        person_info = person.split()
        for a in person_info[:-1]:
            if not people_category.get(a) : people_category[a] =[]
            people_category[a].append(i)
        people_score[i] = int(person_info[-1])

    answer = []

    for q in query :
        q = q.replace('and','').replace('-','').split()
        people_num = 0
        people_bitmap = "1"*len(info)
        if len(q) > 1 : # 타 조건 존재
            score_bitmap = ["1" if sc >= int(q[-1]) else "0" for sc in people_score ]
            score_bitmap = int(''.join(score_bitmap),2)
            people_bitmap = int(people_bitmap, 2)
            people_bitmap = bin(people_bitmap & score_bitmap)[2:].zfill(len(info))

            for condition in q[:-1]:
                temp_bitmap = ["0"]*len(info)
                for p in people_category[condition]:
                    temp_bitmap[p] = "1"
                temp_bitmap = int(''.join(temp_bitmap),2)
                people_bitmap = int(people_bitmap,2)

                people_bitmap = bin(people_bitmap & temp_bitmap)[2:].zfill(len(info))



            people_num = people_bitmap.count("1")

        else :
            for p in people_score :
                if p >= int(q[-1]) : people_num += 1

        answer.append(people_num)

    return answer

# 테스트 케이스
info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
print(solution(info,query))

