//
//  boj_11058.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/08.
//
//  크리보드

import Foundation

let N = Int(readLine()!)!
var dp = Array(repeating: 0, count: 101)
var maxNum = 0

for i in 1...6 {
    dp[i] = i
}

if N > 6 {
    for i in 7...N {
        maxNum = 0
        for j in 1...i-3 {
            maxNum = max(dp[j] * (i-j-1), maxNum)
        }
        dp[i] = maxNum
    }
}

print(dp[N])
