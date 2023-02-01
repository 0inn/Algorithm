//
//  boj_4811.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/31.
//

import Foundation

//  dp[w][h] : w와 h로 만들 수 있는 문자열들 중 문제의 조건에 부합하는 경우의 수
var dp = Array(repeating: Array(repeating: 0, count: 32), count: 32)

func calculate() {
    for w in 0...30 {
        for h in 0...30 {
            if w < h { continue }
            if h == 0 {
                //  h가 없다면 w를 뽑는 경우의 수밖에 없으므로 1
                dp[w][0] = 1
            } else {
                //  dp[2][1]: w 2개와 h 1개로 만들 수 있는 문자열의 경우의 수
                //  = w와 h로 표현할 수 있는 길이가 3인 문자열 중 조건을 만족하는 수
                //  = w와 h로 표현할 수 있는 길이가 2인 문자열 + (w or h)
                //  = dp[1][1] (w) + dp[2][0] (h)
                dp[w][h] = dp[w-1][h] + dp[w][h-1]
            }
        }
    }
}

calculate()

while true {
    let N = Int(readLine()!)!
    if N == 0 { break }
    //  총 2N 길이의 문자열 중 조건에 부합하는 경우의 수 출력
    //  = w N개, h N개로 만들 수 있는 문자열 중 조건에 부합하는 경우의 수 출력
    //  = dp[w][h] = dp[N][N]
    print(dp[N][N])
}

