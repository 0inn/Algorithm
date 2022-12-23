//
//  boj_1446.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/22.
//
//  지름길

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let D = input[1]

var shortPath: [(Int, Int, Int)] = []
var dp = Array(repeating: 0, count: D + 1)

for _ in 0..<N {
    let info = readLine()!.split(separator: " ").map { Int($0)! }
    shortPath.append((info[0], info[1], info[2]))
}

for i in 1...D {
    dp[i] = dp[i-1] + 1
    for j in 0..<shortPath.count {
        if shortPath[j].1 == i {
            dp[i] = min(dp[i], dp[shortPath[j].0] + shortPath[j].2)
        }
    }
}

print(dp[D])

/*
 
 고려 사항
 
 0 50 20
 0 50 10
 
 동일한 시작점, 도착점을 가질 경우
 더 작은 값으로 dp 초기화 시켜줘야 한다.
 
 */
