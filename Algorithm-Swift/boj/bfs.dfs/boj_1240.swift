//
//  boj_1240.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/02/21.
//

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let M = input[1]

var graph: [Int: [(Int, Int)]] = [:]

// 그래프 생성
for _ in 1..<N {
    let info = readLine()!.split(separator: " ").map { Int($0)! }
    
    let u = info[0]
    let v = info[1]
    let w = info[2]
    
    graph[u, default: []].append((v, w))
    graph[v, default: []].append((u, w))
}

// bfs
func bfs(_ s: Int, _ e: Int) -> Int {
    var dist = Array(repeating: -1, count: N + 1)
    var queue = [Int]()
    dist[s] = 0
    queue.append(s)
    
    while !queue.isEmpty {
        let curN = queue.removeFirst()
        
        if curN == e {
            return dist[e]
        }
        
        for (nxtN, nxtW) in graph[curN]! {
            if dist[nxtN] != -1 { continue }
            dist[nxtN] = dist[curN] + nxtW
            queue.append(nxtN)
        }
    }
    
    return 0
}

for _ in 0..<M {
    let node = readLine()!.split(separator: " ").map { Int($0)! }
    
    let u = node[0]
    let v = node[1]
    
    print(bfs(u, v))
}
