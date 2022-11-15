//
//  pg_12979.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/15.
//
//  기지국 설치

import Foundation

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int {
    var range: [(Int, Int)] = [(0, 0)]
    var wRange = w * 2 + 1
    var ans = 0
    
    for s in stations {
        range.append((s - w, s + w))
    }
    range.append((n + 1, n + 1))
    
    for i in 1..<range.count {
        let empty = range[i].0 - range[i-1].1 - 1
        if empty <= 0 { continue }
        ans += (empty / wRange)
        if empty % wRange != 0 {
            ans += 1
        }
    }

    return ans
}
