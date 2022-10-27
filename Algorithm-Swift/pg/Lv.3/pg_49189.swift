//
//  pg_49189.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//
//  가장 먼 노드

import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var dist = [Int](repeating: Int(1e9), count: n + 1)
    var graph = [[Int]](repeating: [], count: n + 1)
    var q = [Int]()
    var farDist = 0
    
    for e in edge {
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    }
    
    q.append(1)
    dist[1] = 0
    
    while !q.isEmpty {
        let cur = q.first!
        q.removeFirst()
        
        for nxt in graph[cur] {
            if dist[cur] + 1 < dist[nxt] {
                q.append(nxt)
                dist[nxt] = dist[cur] + 1
            }
        }
    }
    
    farDist = dist.filter { $0 != Int(1e9) }.sorted().last!
    
    return dist.filter { $0 == farDist }.count
}
