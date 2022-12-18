//
//  boj_1167.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/16.
//
//  트리의 지름

import Foundation

let V = Int(readLine()!)!

var graph = [Int: [(Int, Int)]]()
var visit = Array(repeating: false, count: V + 1)
var dist = 0
var y = 0

for i in 1...V {
    graph[i] = []
}

for _ in 0..<V {
    let tree = readLine()!.split(separator: " ").map { Int($0)! }
    let u = tree[0]
    
    var i = 1
    while i < tree.count - 1 {
        graph[u]!.append((tree[i], tree[i + 1]))
        i += 2
    }
}

func dfs(_ n: Int, _ w: Int) {
    visit[n] = true
    
    if dist < w {
        y = n
        dist = w
    }
    
    for (node, weight) in graph[n]! {
        if visit[node] { continue }
        
        dfs(node, w + weight)
    }
}

//  임의의 한 점에서 가장 멀다는 것은 지름의 두 꼭짓점 중 하나라는 의미
dfs(1, 0)
dist = 0
visit = Array(repeating: false, count: V + 1)
//  해당 지름의 꼭짓점에서 가장 먼 노드를 찾으면 다른 하나의 지름의 꼭짓점
dfs(y, 0)

print(dist)
