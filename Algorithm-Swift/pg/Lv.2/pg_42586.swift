//
//  pg_42586.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//
//  기능 개발

import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var days = [Int]()
    var ans = [Int]()
    
    for idx in 0..<speeds.count {
        var day = (100 - progresses[idx]) / speeds[idx]
        if (100 - progresses[idx]) % speeds[idx] != 0 {
            day += 1
        }
        days.append(day)
    }
    
    var num = days[0]
    var cnt = 0
    for idx in 0..<days.count {
        if num >= days[idx] {
            cnt += 1
        } else {
            ans.append(cnt)
            num = days[idx]
            cnt = 1
        }
        if idx == days.count - 1 {
            ans.append(cnt)
        }
    }
    
    return ans
}
