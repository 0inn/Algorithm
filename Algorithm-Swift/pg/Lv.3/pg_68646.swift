//
//  pg_68646.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/22.
//

import Foundation

func solution(_ a:[Int]) -> Int {
    var ans = 0
    var leftMin = Array(repeating: 0, count: a.count)
    var rightMin = Array(repeating: 0, count: a.count)

    leftMin[0] = a.first!
    rightMin[a.count-1] = a.last!
    
    for i in 1..<a.count {
        leftMin[i] = min(leftMin[i-1], a[i])
    }
    
    for i in stride(from: a.count-2, through: 0, by: -1) {
        rightMin[i] = min(rightMin[i+1], a[i])
    }
    
    for i in 0..<a.count {
        if a[i] > leftMin[i] && a[i] > rightMin[i] {
            continue
        }
        ans += 1
    }
    
    return ans
}
