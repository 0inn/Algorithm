//
//  pg_43164.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/05.
//
//  여행경로

import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var ans = [String]()
    var visit = Array(repeating: false, count: tickets.count)
    var isAns = false
    
    var ticket = tickets.sorted { $0[0] == $1[0] ? $0[1] < $1[1] : $0[0] < $1[0] }
    
    func dfs(_ start: String, _ cnt: Int) {
        ans.append(start)
        
        if cnt == ticket.count {
            isAns = true
        }
        
        for i in 0..<ticket.count {
            if visit[i] { continue }
            if ticket[i][0] == start {
                visit[i] = true
                dfs(ticket[i][1], cnt + 1)
                
                if !isAns {
                    ans.removeLast()
                    visit[i] = false
                }
            }
        }
    }
    
    dfs("ICN", 0)
    
    return ans
}
