# [Gold III] 프로거 - 6595 

[문제 링크](https://www.acmicpc.net/problem/6595) 

### 성능 요약

메모리: 2800 KB, 시간: 4 ms

### 분류

자료 구조, 분리 집합, 플로이드–워셜, 그래프 이론, 최소 스패닝 트리, 최단 경로

### 제출 일자

2024년 11월 15일 01:35:32

### 문제 설명

<p>Freddy Frog는 호수 한 가운데 돌에 앉아 있다. 그는 불현듯 또 다른 돌에 앉아 있는 Fiona Frog를 인식했다. 그는 그녀에게 갈 계획을 세웠지만, 물이 더럽고 관광객의 선크림으로 가득 차있었기 때문에, 그는 수영을 하지 않고 점프를 통해그녀에게 가고자 했다. </p>

<p>불행히도 Fiona의 돌은 점프 범위를 벗어나 있다. 그러므로 Freddy는 다른 돌을 거쳐 여러 번의 점프로 그녀에게 가기로 마음 먹었다.</p>

<p>주어진 순서로 점프하기 위해, frog의 점프 범위는 적어도 순서의 가장 멀리 먼 거리의 점프만큼은 되어야 한다.</p>

<p>두 돌 사이의 the frog distance (사람들이 최소 거리라 부르는) 는 모든 가능한 두 돌 사이의 경로의 필요한 최소한의 점프 범위로 정의할 수 있다.</p>

<p>당신은 주어진 Freddy의 돌, Fiona의 돌 그리고 호수의 모든 다른 돌을 좌표로 받게 된다. 당신의 일은 Freddy 돌과 Fiona 돌의 the frog distance를 계산하는 것이다. </p>

### 입력 

 <p>입력 파일은 하나 혹은 그 이상의 테스트 케이스로 이루어진다. 각 테스트 케이스의 첫 번째 줄은 n개의 돌을 포함한다. (각각의 2nn lines은 두 개의 정수 xi,yi 를 포함한다.) 돌 #1은 Freddy의 돌이고, 돌 #2는 Fiona의 돌 그리고 다른 n-2 돌은 비어 있는 돌이다. 각 테스트 케이스 사이에는 공백 행이 있다. n을 위한 값이 zero (0)가 될 경우 입력은 종료된다. </p>

### 출력 

 <p>각각의 테스트 케이스에서 "Scenario #x" 문장과 "Frog Distance = y" 문장을 출력한다. 여기서 x는 테스트 케이스의 수로 대체된다 (1부터 번호가 매겨진다). y는 적절한 소수점 셋째 자리의 실수로 대체될 수 있다. 마지막 케이스까지 각 테스트 케이스 뒤에는 공백 행을 출력해라.</p>

