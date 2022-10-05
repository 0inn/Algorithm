//
//  pg_12926.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/04.
//
//  시저 암호

import Foundation

func solution(_ s:String, _ n:Int) -> String {
    var ans = ""
    var upper = false
    s.forEach {
        upper = ($0.asciiValue! >= 65 && $0.asciiValue! <= 90) ? true : false
        var num = $0.asciiValue! + UInt8(n)
        if upper {
            num = (num > 90) ? UInt8(num - 26) : num
        } else {
            num = (num > 122) ? UInt8(num - 26) : num
        }
        ans += ($0 == " ") ? " " : String(UnicodeScalar(num))
    }
    return ans
}
