"""
요구사항
순서는 정해져 있고, 그 순서에서 최단시간을 계산하는 것

방법 1 : 다리를 진짜 시뮬레이션 한다
1. 다리 길이만큼의 배열을 만든다
2. 트럭을 직접 다리 위에서 이동시킨다

방법 2 : 큐를 이용한다(진자 큐 말고)
1. 버틸수 있는 무게면 큐에 넣는다
- 이때, 큐에 잔존한 시간을 함께 넣는다
2. 1초가 지날 때마다 잔존한 시간을 증가시킨다
3. 시간이 일정 숫자에 도달하면 큐에서 내보낸다

"""

def solution(bridge_length, weight, truck_weights):
    
    trucks_waiting = truck_weights
    trucks_onbridge = []
    trucks_complete = []
    
    total_truck = len(truck_weights)
    time = 0
    while len(trucks_complete) != total_truck :
        # 1. 현재 bridge 내의 잔존시간 검사 및 도달시 방출
        if len(trucks_onbridge) > 0 :              
            for truck in trucks_onbridge :
                truck[1] -= 1
        
            if trucks_onbridge[0][1] <= 0 :
                trucks_complete.append(trucks_onbridge.pop(0))
            
        # 2. 수용가능 여부 검증
        if len(trucks_waiting) > 0 :
            if (sum([x[0] for x in trucks_onbridge]) + trucks_waiting[0] <= weight) :
                trucks_onbridge.append([trucks_waiting.pop(0),bridge_length])
    

        time += 1
    return time

bridge_length = 2
weight = 10
truck_weights = [7,4,5,6]

print(solution(bridge_length, weight, truck_weights))