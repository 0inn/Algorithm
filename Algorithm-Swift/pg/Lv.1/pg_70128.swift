//
//  pg_70128.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

 func solution1(_ a:[Int], _ b:[Int]) -> Int {
     var ans = 0
     (0..<a.count).map{ ans += (a[$0] * b[$0]) }
     return ans
 }

func solution2(_ a:[Int], _ b:[Int]) -> Int {
    return zip(a, b).map{ $0 * $1 }.reduce(0, +)
}

func solution2(_ a:[Int], _ b:[Int]) -> Int {
    return zip(a, b).map(*).reduce(0, +)
}
