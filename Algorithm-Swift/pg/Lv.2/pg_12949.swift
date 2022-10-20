//
//  pg_12949.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/20.
//
//  행렬의 곱셈

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var num = 0
    var ans = Array(repeating: Array(repeating: 0, count: arr2[0].count), count: arr1.count)
    
    for i in 0..<arr1.count {
        for j in 0..<arr2[0].count {
            for z in 0..<arr1[0].count {
                ans[i][j] += arr1[i][z] * arr2[z][j]
            }
        }
    }
    
    return ans
}
