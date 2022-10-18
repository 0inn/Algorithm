//
//  pg_12985.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/18.
//
//  예상 대진표

import Foundation

func solution1(_ n:Int, _ a:Int, _ b:Int) -> Int {
    var ans = 1

    func fight(_ vs: [Int]) {
        var arr = vs.sorted()
        if (arr[1] - arr[0] == 1) && arr[0] % 2 == 1 {
            return
        } else {
            ans += 1
            fight(vs.map { ($0 + 1) / 2 })
        }
    }

    fight([a, b])

    return ans
}

func solution2(_ n:Int, _ a:Int, _ b:Int) -> Int {
    var ans = 0
    var nextA = a
    var nextB = b
    
    while nextA != nextB {
        nextA = (nextA + 1) / 2
        nextB = (nextB + 1) / 2
        ans += 1
    }
    
    return ans
}
