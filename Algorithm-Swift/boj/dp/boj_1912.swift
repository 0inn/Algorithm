//
//  boj_1912.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/11.
//
//  연속합

import Foundation

let n = Int(readLine()!)!
var dp = readLine()!.split(separator: " ").map { Int($0)! }
var ans = dp[0]

for i in 1..<n {
    if dp[i] + dp[i-1] > dp[i] {
        dp[i] += dp[i-1]
    }
    
    ans = max(ans, dp[i])
}

print(ans)
