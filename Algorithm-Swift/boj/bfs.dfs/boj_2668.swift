//
//  boj_2668.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/07.
//
//  숫자고르기

import Foundation

let N = Int(readLine()!)!
var graph: [Int] = [0]

for _ in 0..<N {
    let num = Int(readLine()!)!
    graph.append(num)
}

var totalVisit = Array(repeating: false, count: N + 1)
var visit = Array(repeating: false, count: N + 1)
var totalAns = [Int]()
var ans = [Int]()
var last: Int = 0

func dfs(_ n: Int) {
    visit[n] = true
    ans.append(n)
    
    let nxt = graph[n]
    if !visit[nxt] && !totalVisit[nxt] {
        dfs(nxt)
    } else {
        last = nxt
    }
}

for i in 1...N {
    if totalVisit[i] { continue }
    visit = Array(repeating: false, count: N + 1)
    ans.removeAll()
    dfs(i)
    if i == last {
        ans.forEach {
            totalAns.append($0)
        }
    }
    totalVisit[i] = true
}

totalAns.sort { $0 < $1 }

print(totalAns.count)
totalAns.forEach {
    print($0)
}

let N = Int(readLine()!)!
var graph: [Int] = [0]

for _ in 0..<N {
    let num = Int(readLine()!)!
    graph.append(num)
}

/* 다른 풀이
var visit = Array(repeating: false, count: N + 1)
var ans = [Int]()

func dfs(_ n: Int, _ start: Int) {
    if visit[n] { // 이미 방문했는데
        if n == start { // 시작점과 같다면 cycle 발생
            ans.append(n)
        }
    } else {
        visit[n] = true
        dfs(graph[n], start)
    }
}

for i in 1...N {
    visit = Array(repeating: false, count: N + 1)
    dfs(i, i)
}

print(ans.count)
ans.forEach {
    print($0)
}
*/
