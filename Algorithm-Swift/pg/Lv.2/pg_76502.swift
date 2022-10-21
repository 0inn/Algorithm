//
//  pg_76502.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/21.
//
//  괄호 회전하기

import Foundation

func solution(_ s:String) -> Int {
    var str = Array(s)
    var arr = [Character]()
    var ans = 0
    
    for _ in 0..<str.count {
        var isRight = true
        for c in str {
            if c == "[" || c == "(" || c == "{" {
                arr.append(c)
            } else {
                if arr.isEmpty {
                    isRight = false
                    break
                }
                var back = arr.popLast()
                if (c == "]" && back == "[") || (c == ")" && back == "(") || (c == "}" && back == "{") {
                    continue
                } else {
                    isRight = false
                    break
                }
            }
        }
        if isRight && arr.isEmpty { ans += 1 }
        str.append(str.first!)
        str.removeFirst()
        arr.removeAll()
    }
    
    return ans
}
