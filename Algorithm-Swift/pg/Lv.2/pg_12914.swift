//
//  pg_12914.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/18.
//
//  멀리 뛰기

import Foundation

func solution1(_ n:Int) -> Int {
    var dp = Array(repeating: 0, count: n + 2)
    
    dp[1] = 1
    dp[2] = 2
    
    if n == 1 || n == 2 { return dp[n] }
    for idx in 3...n {
        dp[idx] = (dp[idx - 2] + dp[idx - 1]) % 1234567
    }
    
    return dp[n]
}

func solution2(_ n:Int) -> Int {
    var n1 = 0
    var n2 = 1
    var sum = 0
    if n == 1 || n == 2 { return n }
    for _ in 0..<n {
        sum = n1 + n2
        n1 = n2
        n2 = sum % 1234567
    }
    return n2
}
