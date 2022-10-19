//
//  pg_12980.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/19.
//
//  점프와 순간 이동

import Foundation

func solution(_ n:Int) -> Int {
    var num = n
    var ans = 0
    
    while num > 0 {
        if num % 2 == 0 {
            num /= 2
        } else {
            num -= 1
            ans += 1
        }
    }
    
    return ans
}
