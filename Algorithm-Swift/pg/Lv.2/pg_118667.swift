//
//  pg_118667.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/09.
//
//  두 큐 합 같게 만들기

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var arr = queue1 + queue2
    var sum1 = queue1.reduce(0, +)
    var sum2 = queue2.reduce(0, +)
    var idx1 = 0
    var idx2 = queue1.count
    var ans = 0
    var cnt = 0
    
    while true {
        if cnt == queue1.count * 3 { return -1 }
        if idx1 == idx2 { return -1 }
        
        if sum1 > sum2 {
            let num = arr[idx1]
            sum1 -= num
            sum2 += num
            if idx1 == arr.count - 1 {
                idx1 = 0
            } else {
                idx1 += 1
            }
            ans += 1
        } else if sum1 < sum2 {
            let num = arr[idx2]
            sum2 -= num
            sum1 += num
            if idx2 == arr.count - 1 {
                idx2 = 0
            } else {
                idx2 += 1
            }
            ans += 1
        } else {
            return ans
        }
        
        cnt += 1
    }
    
    return -1
}
