//
//  boj_16507.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/02/09.
//
//  어두운 건 무서워

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let R = input[0]
let C = input[1]
let Q = input[2]

var arr: [[Int]] = []
var dp = Array(repeating: Array(repeating: 0, count: C + 1), count: R + 1)

arr.append(Array(repeating: 0, count: C + 1))

for _ in 1...R {
    var column = readLine()!.split(separator: " ").map { Int($0)! }
    column.reverse()
    column.append(0)
    column.reverse()
    arr.append(column)
}

dp[1][1] = arr[1][1]

for r in 1...R {
    for c in 1...C {
        if r == 1 && c == 1 { continue }
        if r == 1 {
            dp[r][c] = dp[r][c-1] + arr[r][c]
        } else if c == 1 {
            dp[r][c] = dp[r-1][c] + arr[r][c]
        } else {
            dp[r][c] = dp[r-1][c] + dp[r][c-1] + arr[r][c] - dp[r-1][c-1]
        }
    }
}

var start: (Int, Int) = (0 ,0)
var end: (Int, Int) = (0, 0)
var n: Int = 0
var ans: Int = 0

for _ in 0..<Q {
    let points = readLine()!.split(separator: " ").map { Int($0)! }
    start = (points[0], points[1])
    end = (points[2], points[3])
    n = (end.0 - start.0 + 1) * (end.1 - start.1 + 1)
    
    ans = (dp[end.0][end.1] - dp[end.0][start.1 - 1] - dp[start.0 - 1][end.1] + dp[start.0 - 1][start.1 - 1]) / n
    print(ans)
}
