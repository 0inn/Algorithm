//
//  pg_92343.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/06.
//
//  양과 늑대

import Foundation

func solution(_ info:[Int], _ edges:[[Int]]) -> Int {
    var graph = [Int: [Int]]()
    var nxtArr = [Int]()
    var ans = 0
    
    for i in 0..<info.count {
        graph[i] = []
    }
    
    for edge in edges {
        graph[edge[0]]!.append(edge[1])
    }
    
    func dfs(_ cur: Int, _ sheep: Int, _ wolf: Int, _ nxtArr: [Int]) {
        var s = sheep
        var w = wolf
        
        if info[cur] == 0 {
            s += 1
        } else {
            w += 1
        }
        
        if s <= w { return }
        
        ans = max(ans, s)
        
        for n in nxtArr {
            var nxt = nxtArr
            let idx = nxt.firstIndex(of: n)!
            nxt.remove(at: idx)
            for i in graph[n]! {
                nxt.append(i)
            }
            dfs(n, s, w, nxt)
        }
    }
    
    for i in graph[0]! {
        nxtArr.append(i)
    }
    
    dfs(0, 0, 0, nxtArr)
    
    return ans
}
