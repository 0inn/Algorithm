//
//  boj_13398.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/11.
//
//  연속합 2

import Foundation

let n = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map { Int($0)! }

var dp = Array(repeating: Array(repeating: 0, count: 2), count: n)

dp[0][0] = arr[0]
dp[0][1] = arr[0]
var ans = arr[0]

for i in 1..<n {
    dp[i][0] = max(arr[i], dp[i-1][0] + arr[i])
    dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0])
    
    ans = max(ans, dp[i][0])
    ans = max(ans, dp[i][1])
}

print(ans)
