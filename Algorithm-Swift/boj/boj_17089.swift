//
//  boj_17089.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/22.
//
//  세 친구

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]

var graph: [[Int]] = Array(repeating: [], count: N + 1)
var visit = Array(repeating: false, count: N + 1)
var ans = Int(1e9)

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    
    let u = input[0]
    let v = input[1]
    
    graph[u].append(v)
    graph[v].append(u)
}

func dfs(_ n: Int, _ idx: Int, _ cnt: Int, _ friends: Int) {
    if cnt == 3 {
        if graph[n].contains(idx) {
            ans = min(ans, friends)
        }
        return
    }
    
    for nxt in graph[n] {
        if visit[nxt] { continue }
        visit[nxt] = true
        dfs(nxt, idx, cnt + 1, friends + graph[nxt].count)
        visit[nxt] = false
    }
}

for i in 1...N {
    visit[i] = true
    dfs(i, i, 1, graph[i].count)
}

if ans == Int(1e9) {
    print(-1)
} else {
    print(ans - 6)
}
