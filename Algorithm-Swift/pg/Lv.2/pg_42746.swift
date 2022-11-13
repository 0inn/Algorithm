//
//  pg_42746.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/11.
//
//  가장 큰 수

import Foundation

func solution(_ numbers:[Int]) -> String {
    var arr = numbers.sorted { Int("\($0)\($1)")! > Int("\($1)\($0)")! }.map { String($0) }
    if arr[0] == "0" {
        return "0"
    }
    
    return arr.joined()
}
