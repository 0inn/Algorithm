//
//  pg_87946.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/11.
//
//  피로도

import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var dgs = dungeons
    var visit = Array(repeating: false, count: dungeons.count)
    var ans = 0
    
    func dfs(_ k: Int, _ cnt: Int) {
        ans = max(ans, cnt)
        
        for i in 0..<dungeons.count {
            if visit[i] { continue }
            if k - dgs[i][0] < 0 { continue }
            visit[i] = true
            dfs(k - dgs[i][1], cnt + 1)
            visit[i] = false
        }
    }
    
    dfs(k, 0)
    
    return ans
}
