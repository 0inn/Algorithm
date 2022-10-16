//
//  pg_12911.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/16.
//
// 다음 큰 숫자

import Foundation

func solution(_ n:Int) -> Int {
    var ans = n
    var oneCnt = String(n, radix: 2).filter { $0 == "1" }.count
    var newOneCnt = 0
    
    while true {
        ans += 1
        newOneCnt = String(ans, radix: 2).filter { $0 == "1" }.count
        if oneCnt == newOneCnt {
            return ans
        }
    }
}
