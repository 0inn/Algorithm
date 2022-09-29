//
//  pg_77884.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//
// 약수의 개수와 덧셈

import Foundation

func solution(_ left:Int, _ right:Int) -> Int {
    var ans = 0
    for i in left...right {
        ((1...i).filter { i % $0 == 0 }.count % 2 == 0) ? (ans += i) : (ans -= i)
    }
    return ans
}
