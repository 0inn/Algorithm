//
//  pg_49994.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/19.
//
//  방문 길이

import Foundation

func solution(_ dirs:String) -> Int {
    var cur = [0, 0]
    var set = Set<String>()
    
    for dir in dirs {
        var next = cur
        switch dir {
            case "U":
                next[1] += 1
            case "D":
                next[1] -= 1
            case "R":
                next[0] += 1
            default:
                next[0] -= 1
        }
        
        // 좌표 평면 넘어가는지 확인
        if !(next.filter { $0 < -5 || $0 > 5 }.isEmpty) {
            next = cur
            continue
        }
        
        // (미래 -> 현재)의 경우 (현재 -> 미래)로 바꿔서 Set에 넣어주면 자동으로 중복 체크
        if !set.contains("\(next)\(cur)") {
            set.insert("\(cur)\(next)")
        }
        
        cur = next
    }
    
    return set.count
}
