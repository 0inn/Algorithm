//
//  boj_13164.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/02/15.
//
//  행복 유치원

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let heights = readLine()!.split(separator: " ").map { Int($0)! }

let N = input[0]
let K = input[1]

var diff: [Int] = []
var ans = 0

for i in 1..<N {
    diff.append(heights[i] - heights[i-1])
}

diff.sort()

ans = diff[0..<(N-K)].reduce(0) { $0 + $1 }

print(ans)
