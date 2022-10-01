//
//  pg_12930.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  이상한 문자 만들기

import Foundation

func solution(_ s:String) -> String {
    var cnt = 0
    var ans = ""
    s.forEach {
        ($0 == " ") ? (cnt = 0) : (cnt += 1)
        ans += (cnt % 2 == 0) ? $0.lowercased() : $0.uppercased()
    }
    return ans
}
