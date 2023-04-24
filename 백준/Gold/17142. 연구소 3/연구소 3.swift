//
//  boj_17142.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/16.
//

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]
var arr: [[Int]] = []
var dist = Array(repeating: Array(repeating: -1, count: N), count: N)
var blank: [(Int, Int)] = [] /// 빈칸 좌표 담은 배열
var virus: [(Int, Int)] = [] /// 바이러스의 좌표 담은 배열
var activeVirus: [(Int, Int)] = [] /// 활성화할 바이러스의 좌표 담은 배열
var maxResult = 0
var ans = Int(1e9)

let dx = [0, 0, -1, 1]
let dy = [1, -1, 0, 0]

var q: [(Int, Int)] = []
var dq: [(Int, Int)] = []

for i in 0..<N {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    for j in row.indices {
        if row[j] == 2 {
            virus.append((i, j))
        } else if row[j] == 0 {
            blank.append((i, j))
        }
    }
    arr.append(row)
}

func dequeue() -> (Int, Int) {
    if dq.isEmpty {
        dq = q.reversed()
        q.removeAll()
    }
    let cur = dq.popLast()!
    return cur
}

/// 바이러스 퍼지는 시간 계산하는 bfs 함수
func bfs() {
    q = []
    dq = []
    dist = Array(repeating: Array(repeating: -1, count: N), count: N)
    
    for virus in activeVirus {
        q.append((virus.0, virus.1))
        dist[virus.0][virus.1] = 0
    }
    
    while !(q.isEmpty && dq.isEmpty) {
        let cur = dequeue()
        
        for dir in 0..<4 {
            let nx = cur.0 + dx[dir]
            let ny = cur.1 + dy[dir]
            
            if nx < 0 || ny < 0 || nx >= N || ny >= N { continue }
            if dist[nx][ny] != -1 || arr[nx][ny] == 1 { continue } /// 이미 방문했거나, 벽인 경우 제외
            dist[nx][ny] = dist[cur.0][cur.1] + 1
            q.append((nx, ny))
        }
    }
}

var check = Array(repeating: false, count: virus.count) /// 조합 구하기 위해 방문 체크하는 배열

/// 활성 상태로 바꿀 바이러스 M개 선택하는 함수 (조합)
func choose(_ idx: Int, _ active: [(Int, Int)]) {
    var active = active
    if active.count == M {
        activeVirus = active
        sol()
        return
    }
    
    for i in idx..<virus.count {
        if check[i] { continue }
        check[i] = true
        active.append(virus[i])
        choose(i, active)
        check[i] = false
        active.removeLast()
    }
}

/// 정답 갱신하는 함수
func sol() {
    bfs()
    
    maxResult = 0 /// 모든 칸에 바이러스 퍼뜨리는 데 걸리는 시간
    var isAns = true /// 모든 빈 칸에 바이러스 퍼뜨릴 수 있는지 여부

    for i in blank.indices {
        let x = blank[i].0, y = blank[i].1
        if dist[x][y] == -1 {
            isAns = false
            break
        }
        maxResult = max(maxResult, dist[x][y])
    }
    
    if isAns {
        ans = min(ans, maxResult)
    }
}

choose(0, [])

print(ans == Int(1e9) ? -1 : ans)
