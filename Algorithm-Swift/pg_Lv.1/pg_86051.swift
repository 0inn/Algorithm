//
//  pg_86051.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

 func solution1(_ numbers:[Int]) -> Int {
     var ans = 0
     var arr = Array(repeating: 0, count: 10)
     numbers.forEach { arr[$0] += 1 }
     (0...9).map { if arr[$0] == 0 { ans += $0 } }
     return ans
 }

func solution2(_ numbers:[Int]) -> Int {
    return (0...9).filter{ !numbers.contains($0) }.reduce(0, +)
}
