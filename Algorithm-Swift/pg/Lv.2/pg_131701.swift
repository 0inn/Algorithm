//
//  pg_131701.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/31.
//
//  연속 부분 수열 합의 개수

import Foundation

func solution(_ elements:[Int]) -> Int {
    var arr = elements + elements
    let len = elements.count
    var ans = Set<Int>()
    var sum = 0
    
    for i in 0..<len {
        sum = 0
        for j in 0..<len {
            sum += arr[i + j]
            ans.insert(sum)
        }
    }
    
    return ans.count
}
