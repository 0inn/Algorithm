//
//  pg_118668.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/23.
//
//  코딩 테스트 공부

import Foundation

func solution(_ alp:Int, _ cop:Int, _ problems:[[Int]]) -> Int {
    var goalAlp = alp
    var goalCop = cop
    goalAlp = max(goalAlp, problems.sorted { $0[0] > $1[0] }[0][0])  // 목표 알고력
    goalCop = max(goalCop, problems.sorted { $0[1] > $1[1] }[0][1])  // 목표 코딩력
    var dp = Array(repeating: Array(repeating: 10000, count: goalCop + 1), count: goalAlp + 1)
    
    dp[alp][cop] = 0
    
    // dp[목표 알고력][목표 코딩력] 찾기
    for i in alp...goalAlp {
        for j in cop...goalCop {
            let nxt_alp = min(i + 1, goalAlp)
            let nxt_cop = min(j + 1, goalCop)
            dp[nxt_alp][j] = min(dp[nxt_alp][j], dp[i][j] + 1)
            dp[i][nxt_cop] = min(dp[i][nxt_cop], dp[i][j] + 1)
            
            for idx in 0..<problems.count {
                let alp_req = problems[idx][0]
                let cop_req = problems[idx][1]
                let alp_rwd = problems[idx][2]
                let cop_rwd = problems[idx][3]
                let cost = problems[idx][4]
                
                if i >= alp_req && j >= cop_req {
                    let nxt_alp = min(i + alp_rwd, goalAlp)
                    let nxt_cop = min(j + cop_rwd, goalCop)
                    dp[nxt_alp][nxt_cop] = min(dp[nxt_alp][nxt_cop], dp[i][j] + cost)
                }
            }
        }
    }
    
    return dp[goalAlp][goalCop]
}
