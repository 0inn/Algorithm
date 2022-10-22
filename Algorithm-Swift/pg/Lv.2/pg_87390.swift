//
//  pg_87390.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/22.
//
//  n^2 배열 자르기

import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var ans = [Int]()
    
    for num in Int(left) ... Int(right) {
        ans.append(max(num / n, num % n) + 1)
    }
    
    return ans
}
