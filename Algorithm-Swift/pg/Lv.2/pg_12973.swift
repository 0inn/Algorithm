//
//  pg_12973.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/17.
//
//  짝지어 제거하기

import Foundation

func solution1(_ s:String) -> Int{
    var str = Array(s)
    var arr = [String]()
    
    arr.append(String(str[0]))
    for i in 1..<str.count {
        if arr.isEmpty {
            arr.append(String(str[i]))
        } else {
            var tmp = arr.popLast()
            if tmp != String(str[i]) {
                arr.append(tmp!)
                arr.append(String(str[i]))
            }
        }
    }
    
    return arr.isEmpty ? 1 : 0
}

func solution2(_ s:String) -> Int{
    var str = Array(s)
    var arr = [String]()
    
    arr.append(String(str[0]))
    for i in 1..<str.count {
        if arr.isEmpty {
            arr.append(String(str[i]))
        } else {
            if arr.last! == String(str[i]) {
                arr.removeLast()
            } else {
                arr.append(String(str[i]))
            }
        }
    }
    
    return arr.isEmpty ? 1 : 0
}
