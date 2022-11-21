//
//  pg_86971.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/21.
//
//  전력망을 둘로 나누기

import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var graph = [Int: [Int]]()
    var visit = Array(repeating: false, count: n + 1)
    var ans = n
    
    for i in 1...n {
        graph[i] = []
    }
    
    for wire in wires {
        graph[wire[0]]!.append(wire[1])
        graph[wire[1]]!.append(wire[0])
    }
    
    var q = [Int]()
    
    for wire in wires {
        visit = Array(repeating: false, count: n + 1)
        visit[1] = true
        q.append(1)
        var cnt = 1
        
        graph[wire[0]] = graph[wire[0]]!.filter { $0 != wire[1] }
        graph[wire[1]] = graph[wire[1]]!.filter { $0 != wire[0] }
        
        while !q.isEmpty {
            let cur = q.removeFirst()
        
            for nxt in graph[cur]! {
                if visit[nxt] { continue }
                cnt += 1
                visit[nxt] = true
                q.append(nxt)
            }
        }
        
        graph[wire[0]]!.append(wire[1])
        graph[wire[1]]!.append(wire[0])
    
        ans = min(ans, abs((n - cnt) - cnt))
    }
    
    return ans
}
