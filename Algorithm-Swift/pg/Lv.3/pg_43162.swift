//
//  pg_43162.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/23.
//
//  네트워크

import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var visited = Array(repeating: false, count: n)
    var network = 0
    
    func dfs(_ computer: Int) {
        visited[computer] = true
        
        for i in 0..<n {
            if computers[computer][i] == 1 && !visited[i] {
                dfs(i)
            }
        }
    }
    
    for i in 0..<n {
        if !visited[i] {
            network += 1
        }
        dfs(i)
    }
    
    return network
}
