//
//  pg_70129.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/15.
//
//  이진 변환 반복하기

import Foundation

func solution(_ s:String) -> [Int] {
    var str = s
    var cnt = 0
    var ansF = 0
    var ansS = 0

    while str != "1" {
        cnt = str.filter { $0 == "1" }.count
        ansS += str.count - cnt
        str = String(cnt, radix: 2)
        ansF += 1
    }
    
    return [ansF, ansS]
}
