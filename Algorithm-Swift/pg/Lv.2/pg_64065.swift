//
//  pg_64065.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/20.
//
//  튜플

import Foundation

func solution(_ s:String) -> [Int] {
    var arr = Array(s)  // 이거 무조건 초기에 변수로 선언 필수 !!
    var dict = [Int: Int]()
    var number = ""
    
    for i in 0..<s.count - 1 {
        var num = String(arr[i])
        if arr[i].isNumber {
            if arr[i+1].isNumber {
                number += num
                continue
            }
            number += num
            let n = Int(number)!
            if let d = dict[n] {
                dict[n] = d + 1
            } else {
                dict[n] = 0
            }
            number = ""
        }
    }
    
    return dict.sorted { $0.1 > $1.1 }.map { $0.0 }
}
