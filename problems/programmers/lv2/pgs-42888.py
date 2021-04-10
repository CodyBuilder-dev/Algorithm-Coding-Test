"""
제목 : 오픈채팅방

아이디어 : 완전 탐색
-> 당연히 O(N^2) = 10^10이므로 실패

아이디어 : 해시를 쓰는수밖에 없다
- 특정 유저의 id를 key로, 해당 유저와 관련된 메시지의 idx를 value로 하자
- for문을 돌면서 id관련정보를 수집한다
    - 메시지의 idx를 수집한다
    - 최종적으로 결정된 닉네임을 수집한다
- for문이 끝나면 해당 id의 메시지를 변경한다
    - 실시간으로 하지 않고 한번에 모아서 해야 빠름
    - 문자열이 immutable이라 객체생성이 엄청 날텐데... 다른 방법이 없나
"""
def solution(record):
    # idx_hash = {}
    nickname_hash = {}
    for i,r in enumerate(record):
        r = r.split()

        # idx저장
        # 굳이 안해도 되나?
        # if not idx_hash.get[r[1]]:
        #     idx_hash[r[1]] =[]
        # idx_hash[r[1]].append(i)

        # 닉네임 변경여부 확인
        if r[0] == "Change" or r[0] == "Enter":
            if not nickname_hash.get(r[1]):
                nickname_hash[r[1]] = "0"
            nickname_hash[r[1]] = r[2]

    answer = []
    # 최종적으로 변경
    for r in record:
        r = r.split()
        if r[0] == "Enter":
            answer.append(f"{nickname_hash[r[1]]}님이 들어왔습니다.")
        if r[0] == "Leave":
            answer.append(f"{nickname_hash[r[1]]}님이 나갔습니다.")
    return answer

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))