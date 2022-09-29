//
//  pg_12935.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var num = arr[arr.startIndex]
    arr.forEach { num = min($0, num) }
    let ans = arr.filter{ $0 != num }
    return ans.count == 0 ? [-1] : ans
}
