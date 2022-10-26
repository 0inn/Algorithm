//
//  pg_12978.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/26.
//
//  배달

import Foundation

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var visit = Array(repeating: Int.max, count: N + 1)
    var cities = [Int: [[Int]]]()
    var queue = [[Int]]()
    var ans = 0
    
    for i in 0...N {
        cities[i] = []
    }
    
    for r in road {
        cities[r[0]]!.append([r[1], r[2]])
        cities[r[1]]!.append([r[0], r[2]])
    }
    
    func bfs(_ start: Int) {
        queue.append([start, 0])
        visit[start] = 0
        
        while !queue.isEmpty {
            let cur = queue.first!
            queue.removeFirst()
            
            for city in cities[cur[0]]! {
                let nxtCity = city[0]
                let nxtCnt = city[1] + cur[1]
                if nxtCnt < visit[nxtCity] && nxtCnt <= k {
                    queue.append([nxtCity, nxtCnt])
                    visit[nxtCity] = nxtCnt
                }
            }
        }
    }
    
    bfs(1)
    
    for v in visit {
        if v != Int.max {
            ans += 1
        }
    }
    
    return ans
}
