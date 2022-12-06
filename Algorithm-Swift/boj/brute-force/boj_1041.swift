//
//  boj_1041.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/06.
//
//  주사위

import Foundation

let N = Int(readLine()!)!
var dice = readLine()!.split(separator: " ").map { Int($0)! }
var mins = Array(repeating: Int(1e9), count: 4)
var ans = Array(repeating: 0, count: 4)

var maxNum = dice.max()!
mins[1] = dice.min()!

for i in 0..<6 {
    for j in i+1..<6 {
        if (i + j == 5) { continue }
        
        mins[2] = min(mins[2], dice[i] + dice[j])
        
        for k in j+1..<6 {
            if (i + k == 5) || (j + k == 5) { continue }
            
            mins[3] = min(mins[3], dice[i] + dice[j] + dice[k])
        }
    }
}


ans[1] = (N-2) * (N-2) * 5 + (N-2) * 4
ans[2] = (N-2) * 8 + 4
ans[3] = 4

if N == 1 {
    print(dice.reduce(0, +) - maxNum)
} else {
    print(zip(ans, mins).map { $0 * $1 }.reduce(0, +))
}
