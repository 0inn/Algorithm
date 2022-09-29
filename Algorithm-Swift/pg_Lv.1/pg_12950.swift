//
//  pg_12950.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//  
//  행렬의 덧셈

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    return zip(arr1, arr2).map { zip($0, $1).map(+) }
}
