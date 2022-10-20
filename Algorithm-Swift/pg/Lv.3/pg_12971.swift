//
//  pg_12971.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/20.
//
//  스티커 모으기(2)

import Foundation

func solution(_ sticker:[Int]) -> Int {
    var dpO = Array(repeating: 0, count: sticker.count)
    var dpX = Array(repeating: 0, count: sticker.count)
    
    if sticker.count == 1 { return sticker[0] }
    
    // 첫 번째 스티커 떼는 경우
    dpO[0] = sticker[0]
    dpO[1] = sticker[0]
    
    // 첫 번째 스티커 안 떼는 경우
    dpX[1] = sticker[1]
    
    for idx in 2..<sticker.count {
        dpX[idx] = max(dpX[idx-1], dpX[idx-2] + sticker[idx])
        if idx == sticker.count - 1 { break }
        dpO[idx] = max(dpO[idx-1], dpO[idx-2] + sticker[idx])
    }
    
    return max(dpO[sticker.count-2], dpX[sticker.count-1])
}
