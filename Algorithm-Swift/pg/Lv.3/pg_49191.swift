//
//  pg_49191.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/02.
//
//  순위

import Foundation

// MARK: - DFS

func solution1(_ n:Int, _ results:[[Int]]) -> Int {
    var graph = [Int: [Int]]()
    var visit = Array(repeating: false, count: n + 1)
    var strong = Array(repeating: 0, count: n + 1)
    var weak = Array(repeating: 0, count: n + 1)

    for i in 1...n {
        graph[i] = []
    }

    for result in results {
        graph[result[0]]!.append(result[1])
    }

    var cnt = -1

    func dfs(_ n: Int) {
        visit[n] = true

        for i in graph[n]! {
            if visit[i] { continue }
            strong[i] += 1
            dfs(i)
        }

        cnt += 1
    }

    for i in 1...n {
        cnt = -1
        visit = Array(repeating: false, count: n + 1)
        dfs(i)
        weak[i] = cnt
    }

    return zip(strong, weak).filter { $0 + $1 == n - 1 }.count
}

// MARK: - BFS

func solution2(_ n:Int, _ results:[[Int]]) -> Int {
    var graph = [Int: [Int]]()
    var info = [(Int, Int)](repeating: (0, 0), count: n + 1)
    
    for i in 1...n {
        graph[i] = []
    }
    
    for result in results {
        graph[result[0]]!.append(result[1])
    }
    
    func bfs(_ start: Int) {
        var q = [Int]()
        var visit = Array(repeating: false, count: n + 1)
        q.append(start)
        visit[start] = true
        
        while !q.isEmpty {
            let cur = q.removeFirst()
            
            for nxt in graph[cur]! {
                if !visit[nxt] {
                    info[nxt].0 += 1
                    info[start].1 += 1
                    
                    q.append(nxt)
                    visit[nxt] = true
                }
            }
        }
    }
    
    for i in 1...n {
        bfs(i)
    }
    
    return info.filter { $0.0 + $0.1 == n - 1 }.count
}
