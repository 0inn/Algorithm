//
//  pg_131705.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  삼총사
//  내부적인 오류 출력 .. 왜지 . . ?

import Foundation

func solution(_ number:[Int]) -> Int {
    var ans = 0
    
    for i in 0..<number.count {
        for j in i+1..<number.count {
            for z in j+1..<number.count {
                if number[i] + number[j] + number[z] == 0 { ans += 1 }
            }
        }
    }
    
    return ans
}
