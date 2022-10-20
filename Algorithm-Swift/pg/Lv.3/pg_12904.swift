//
//  pg_12904.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/20.
//
//  가장 긴 팰린드롬

import Foundation

func solution(_ s:String) -> Int {
    let arr: [Character] = Array(s)
    var answer = 0

    for i in 0..<arr.count {
        // 이미 구한 answer보다 작은 경우면 그냥 넘어가도록
        for j in stride(from: arr.count - i, to: answer, by: -1) {
            var left = i
            var right = i + j - 1
            
            // 좌우 같은지 확인하기
            while left <= right, arr[left] == arr[right] {
                left += 1
                right -= 1
            }
                        
            // 팰린드롬일 경우
            if left > right { answer = max(answer, j) }
        }
    }

    return answer
}
