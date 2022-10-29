//
//  pg_12987.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/29.
//
//  숫자 게임

import Foundation

func solution1(_ a:[Int], _ b:[Int]) -> Int {
    var bArr = b.sorted()
    var ans = 0

    for i in 0..<a.count {
        let aScore = a[i]
        var left = 0
        var right = bArr.count - 1
        var idx = -1

        while left <= right {
            let mid = (left + right) / 2

            if bArr[mid] > aScore {
                right = mid - 1
                idx = mid
            } else {
                left = mid + 1
            }
        }

        if idx != -1 {
            bArr.remove(at: idx)
            ans += 1
        }
    }

    return ans
}

func solution2(_ a:[Int], _ b:[Int]) -> Int {
    var aArr = a.sorted()
    var bArr = b.sorted()
    var idx = 0
    
    for bScore in bArr {
        if bScore > aArr[idx] {
            idx += 1
        }
    }
    
    return idx
}
