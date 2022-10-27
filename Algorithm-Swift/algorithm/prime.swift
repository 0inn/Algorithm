//
//  prime.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//

import Foundation

var n = 100

var primeArr = Array(repeating: 0, count: n + 1)

for i in 2...n {
    primeArr[i] = i
}

for i in 2...n {
    if primeArr[i] == 0 { continue }
    
    for j in stride(from: i * i, through: n, by: i) {
        primeArr[j] = 0
    }
}

var x = 17

if primeArr[x] != 0 {
    print("Prime")
}
