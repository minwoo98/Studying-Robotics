## RRT(Rapidly-Exploring Random Tree)

### 1. RRT?
Sampling-based path planning 알고리즘으로, 랜덤한 샘플링을 만들어 장애물과의 충돌여부를 확인하며 시작~목적지점을 포함하는 트리를 형성한다.
### 2. Pseudo

![image](https://user-images.githubusercontent.com/76464662/183286072-bcafdba2-2e79-4f67-b89a-324b52bff8e8.png)

### 3. 원리
    1) 시작지점을 q_init으로 초기화한다.
    2) Random한 샘플링 q_rdm을 발생시킨다.
    3) q_rdm과 가장 가까운 q_near를 찾는다.
    4) q_near -> q_rdm 방향으로 delta만큼 떨어져있는 q_new를 선정한다.
    5) q_near와 q_new 사이에 장애물이 있는지를 확인한다.
       i) 장애물이 없는 경우 q_new를 트리에 포함하고 2)~5)를 반복한다.
       ii) 장애물과 충돌하는 경우 2)~5)를 실행한다.
    6) 트리에 포함된 q_new가 목적지점이거나 거의 일치하면 종료한다.

### 4. 특징
* 고차원 또는 장애물이 많은 환경에서 비교적 쉽게 경로를 생성할 수 있다.
* 랜덤한 샘플링으로 경로를 탐색하므로 생성한 경로가 optimal하지 않으며, 경로 생성을 실패할 수 있다.
* kinematics를 고려하지 않는다.




