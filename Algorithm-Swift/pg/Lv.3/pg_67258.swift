//
//  pg_67258.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/25.
//
//  보석 쇼핑

import Foundation

func solution(_ gems:[String]) -> [Int] {
    var dict = [String : Int]()
    var gemsCount = Set(gems).count
    var start = 0
    var end = 0
    var minDiff = Int.max
    var answer = [0, 0]
    
    while end <= gems.count {
        // 모든 보석 종류 포함한 경우
        if dict.count == gemsCount {
            let gem = dict[gems[start]]!
            if gem > 1 {
                dict[gems[start]] = gem - 1
            } else if gem == 1 {
                dict[gems[start]] = nil
            }
            start += 1
            
            let len = end - start
            if len < minDiff {
                minDiff = len
                answer = [start, end]
            }
        }
        // 보석 추가해야하는 경우
        else {
            if end < gems.count {
                if let gem = dict[gems[end]] {
                    dict[gems[end]] = gem + 1
                } else {
                    dict[gems[end]] = 1
                }
            }
            end += 1
        }
    }
    
    return answer
}
