//
//  boj_2412.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/09.
//
//  암벽 등반

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0]
let T = input[1]
var arr: [(Int, Int)] = [(0, 0)]
var dist = Array(repeating: -1, count: n + 1)
var ans = -1

for _ in 1...n {
    let spot = readLine()!.split(separator: " ").map { Int($0)! }
    
    arr.append((spot[0], spot[1]))
}

arr.sort { $0.0 == $1.0 ? $0.1 < $1.1 : $0.0 < $1.0 }

func bfs() {
    var q = [Int]()
    q.append(0)
    dist[0] = 0
    
    while !q.isEmpty {
        let cur = q.removeFirst()   // 현재 좌표 idx
        let x = arr[cur].0  // 현재 좌표 x
        let y = arr[cur].1  // 현재 좌표 y
        
        if y == T {
            ans = dist[cur]
        }
        
        for nxt in stride(from: cur - 1, through: 0, by: -1) {   // 현재 좌표보다 작은 좌표들 중
            if abs(arr[nxt].0 - x) > 2 { break }    // x좌표 차이가 2를 초과하는 경우 제외
            if dist[nxt] == -1 && abs(arr[nxt].1 - y) <= 2 {    // 방문한 적 없고, y좌표 차이도 2가 안나면
                dist[nxt] = dist[cur] + 1   // dist 계산
                q.append(nxt)
            }
        }
        
        for nxt in stride(from: cur + 1, through: n, by: 1) {   // 현재 좌표보다 큰 좌표들 중에서 똑같이 탐색
            if abs(arr[nxt].0 - x) > 2 { break }
            if dist[nxt] == -1 && abs(arr[nxt].1 - y) <= 2 {
                dist[nxt] = dist[cur] + 1
                q.append(nxt)
            }
        }
    }
}

bfs()

print(ans)
