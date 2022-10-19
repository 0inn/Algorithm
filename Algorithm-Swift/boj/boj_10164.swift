//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/18.
//
//  격자상의 경로

import Foundation

let input = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = input[0]
let m = input[1]
let k = input[2]
var dp = Array(repeating: Array(repeating: 0, count: m + 1), count: n + 1)

var cnt = 0
var ans = 0
var x = 0
var y = 0

func solution() {
    // (0, 0) -> O 까지 이동 가능한 경우의 수
    dp[1][1] = 1
    for i in 1...n {
        for j in 1...m {
            cnt += 1
            if cnt == k {
                x = i
                y = j
            }
            if i == 1 && j == 1 { continue }
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        }
    }
    
    if k == 0 {
        print(dp[n][m])
        return
    }
    // O -> (n, m) 까지 이동 가능한 경우의 수
    ans = dp[x][y]
    dp = Array(repeating: Array(repeating: 0, count: m + 1), count: n + 1)
    dp[x][y] = 1
    for i in x...n {
        for j in y...m {
            if i == x && j == y { continue }
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        }
    }
    
    print(ans * dp[n][m])
}

solution()
