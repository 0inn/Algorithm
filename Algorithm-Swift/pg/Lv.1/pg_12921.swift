//
//  pg_12921.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/07.
//
//  소수 찾기

import Foundation

func solution(_ n:Int) -> Int {
    var ans = 0
    for i in 2 ... n {
        var prime = true
        if i > 3 {
            for j in 2 ... Int(sqrt(Double(i))) {
                if i % j == 0 {
                    prime = false
                    break;
                }
            }
        }
        if prime { ans += 1 }
    }
    return ans
}
