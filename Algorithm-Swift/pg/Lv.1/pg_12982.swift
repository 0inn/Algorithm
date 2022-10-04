//
//  pg_12982.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  예산

import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var sum = 0
    var ans = 0
    d.sorted().forEach {
        sum += $0
        if sum <= budget { ans += 1 }
    }
    return ans
}
