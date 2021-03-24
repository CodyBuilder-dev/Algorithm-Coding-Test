"""
제목 : 베스트 앨범

요구사항 :
- 장르를 조회수로 정렬
    - 장르는 최대 100
- 장르 내에서 조회수,고유번호로 정렬해 2개씩 전성
    - 곡은 최대 10,000

구현 :
- dict구조를 사용하면 두가지 요구사항 수행 가능
- { "genre_name" :
    { plays : 1000,
        songs : [(0,600),(2,300),(5,100)]
    }
}

(1) 리스트 2개 -> dict로 구조 전환
(2) 장르별로 정렬
(3) 해당 장르의 조회수/id별로 정렬
"""

def make_dict(genres,plays):
    data = {}
    for i in range(len(genres)):
        if not data.get(genres[i]) :
            data[genres[i]] = dict()
            data[genres[i]]["name"],data[genres[i]]["plays"],data[genres[i]]["songs"] = genres[i],0,list()
        data[genres[i]]["plays"] += plays[i]
        data[genres[i]]["songs"].append((i,plays[i]))
    return data

def solution(genres, plays):
    data = make_dict(genres,plays)
    data = sorted(data.values(), key=lambda x : (-x["plays"]))

    answer = []
    for d in data:
        sorted_song = sorted(d["songs"],key = lambda x : (-x[1],x[0]))
        answer.extend([x for x,y in sorted_song[:2]])

    return answer

genres = ["classic", "pop", "classic", "classic", "pop"]
plays = [500, 600, 150, 800, 2500]
print(solution(genres,plays))

