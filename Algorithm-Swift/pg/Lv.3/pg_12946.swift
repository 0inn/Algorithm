//
//  pg_12946.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/26.
//
//  하노이의 탑

import Foundation

func solution(_ n:Int) -> [[Int]] {
    var ans = [[Int]]()
    
    func hanoi(_ n: Int, _ start: Int, _ to: Int, _ via: Int) {
        if n == 1 {
            ans.append([start, to])
            return
        }
        hanoi(n-1, start, via, to)
        ans.append([start, to])
        hanoi(n-1, via, to, start)
    }
    
    hanoi(n, 1, 3, 2)
    
    return ans
}
