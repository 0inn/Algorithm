//
//  boj_2021.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/04/27.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let (N, L) = (input[0], input[1])

let nxtLine = 100000
var metro: [[Int]] = Array(repeating: [], count: 200001)
var dist: [Int] = Array(repeating: -1, count: 200001)
var ans = -1

var q: [Int] = []
var dq: [Int] = []

func pop() -> Int {
    if dq.isEmpty {
        dq = q.reversed()
        q.removeAll()
    }
    let cur = dq.popLast()!
    return cur
}

func bfs() {
    q.append(start)
    dist[start] = 0
    
    while (!q.isEmpty || !dq.isEmpty) {
        let cur = pop()
        
        if cur == end {
            ans = (dist[cur] - 1 > 0) ? dist[cur] - 1 : 0
            break
        }
        for nxt in metro[cur] {
            if dist[nxt] > -1 { continue }
            
            var change = 0
            if nxt > nxtLine { change = 1 } /// 다른 호선으로 바꾸는 경우
            dist[nxt] = dist[cur] + change
            q.append(nxt)
        }
    }
}

for l in 1...L {
    let stations = readLine()!.split(separator: " ").map { Int($0)! }
    for st in stations {
        if st == -1 { continue }
        /// 호선 <-> 역만 연결
        metro[st].append(l + nxtLine)
        metro[l+nxtLine].append(st)
    }
}

let station = readLine()!.split(separator: " ").map { Int($0)! }
let start = station.first!
let end = station.last!

bfs()
print(ans)
