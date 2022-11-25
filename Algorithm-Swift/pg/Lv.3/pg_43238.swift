//
//  pg_43238.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//
//  입국심사

import Foundation

func solution1(_ n:Int, _ times:[Int]) -> Int64 {
    var left = 0
    var right = times.sorted().last! * n
    var ans = 0
    
    while left <= right {
        var mid = (left + right) / 2
        var person = 0
        
        for time in times {
            person += (mid / time)
        }
        
        if person >= n {
            right = mid - 1
            ans = mid
        } else {
            left = mid + 1
        }
    }
    
    return Int64(ans)
}

func solution2(_ n:Int, _ times:[Int]) -> Int64 {
    var low = 0
    var high = times.sorted().last! * n
    
    func check(_ mid: Int) -> Bool {
        var total = 0
        
        for time in times {
            total += (mid / time)
        }
        
        return total >= n
    }
    
    while low + 1 < high {
        let mid = (low + high) / 2
        
        if check(mid) {
            high = mid
        } else {
            low = mid
        }
    }
    
    return Int64(high)
}
