//
//  pg_12913.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/29.
//
//  땅따먹기

import Foundation

func solution(_ land:[[Int]]) -> Int {
    var dp = land
    
    for i in 1..<land.count {
        for j in 0..<4 {
            var maxNum = 0
            for z in 0..<4 {
                if z == j { continue }
                maxNum = max(dp[i-1][z], maxNum)
            }
            dp[i][j] += maxNum
        }
    }
    
    return dp[land.count-1].sorted().last!
}
