//
//  pg_42861.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/17.
//
//  섬 연결하기

import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var costs = costs.sorted { $0[2] < $1[2] }
    var parents = [Int]()
    var ans = 0
    
    for i in 0...n {
        parents.append(i)
    }
    
    func find(_ n: Int) -> Int {
        if parents[n] != n {
            parents[n] = find(parents[n])
        }
        return parents[n]
    }
    
    func union(_ first: Int, _ second: Int) {
        let firstParent = find(first)
        let secondParent = find(second)
        
        if firstParent < secondParent {
            parents[secondParent] = firstParent
        } else {
            parents[firstParent] = secondParent
        }
    }
    
    for cost in costs {
        let u = cost[0]
        let v = cost[1]
        let w = cost[2]
        
        if find(u) == find(v) {
            continue
        }
        
        union(u, v)
        ans += w
    }
    
    return ans
}
