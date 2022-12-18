//
//  boj_1389.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/29.
//
//  케빈 베이컨의 6단계 법칙

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let N = input[0]
let M = input[1]

var graph = [Int: [Int]]()
var dist = Array(repeating: Int(1e9), count: N + 1)
var minNum = Int(1e9)

for i in 1...N {
    graph[i] = []
}

for _ in  0..<M {
    let edge = readLine()!.split(separator: " ").map { Int($0)! }
    graph[edge[0]]!.append(edge[1])
    graph[edge[1]]!.append(edge[0])
}

func dfs(_ start: Int) {
    var q = [Int]()
    q.append(start)
    dist[start] = 0
    
    while !q.isEmpty {
        let cur = q.removeFirst()
        
        for nxt in graph[cur]! {
            if dist[nxt] > dist[cur] + 1 {
                dist[nxt] = dist[cur] + 1
                q.append(nxt)
            }
        }
    }
}

var sums = Array(repeating: 0, count: N + 1)

for i in 1...N {
    dist = Array(repeating: Int(1e9), count: N + 1)
    dist[0] = 0
    
    dfs(i)
     
    let sum = dist.reduce(0, +)
    sums[i] = sum
    minNum = min(minNum, sum)
}

print(sums.enumerated().filter { $0.1 == minNum }.first!.0)

/* 플로이드 와샬

let input = readLine()!.split(separator: " ").map { Int($0)! }
let N = input[0]
let M = input[1]

var graph = [Int: [Int]]()
var dist = Array(repeating: Array(repeating: Int(1e9), count: N + 1), count: N + 1)
var minNum = Int(1e9)

for i in 1...N {
    dist[i][i] = 0
}

for _ in  0..<M {
    let edge = readLine()!.split(separator: " ").map { Int($0)! }
    dist[edge[0]][edge[1]] = 1
    dist[edge[1]][edge[0]] = 1
}

for k in 1...N {
    for i in 1...N {
        for j in 1...N {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        }
    }
}

var sums = Array(repeating: 0, count: N + 1)

for i in 1...N {
    var sum = 0
    for j in 1...N {
        sum += dist[i][j]
    }
    sums[i] = sum
    minNum = min(minNum, sum)
}

print(sums.enumerated().filter { $0.1 == minNum }.first!.0)
 
*/
