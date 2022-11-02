//
//  prime.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//

import Foundation

// 에라토스테네스의 체

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


// for문

func isForPrime(_ n: Int) -> Bool {
    if n == 1 { return false }
    if n == 2 || n == 3 { return true }
    
    let sq = Int(sqrt(Double(n)))
    
    for i in 2...sq {
        if n % i == 0 { return false }
    }
    
    return true
}


// while문
func isWhilePrime(_ n: Int) -> Bool {
    if n == 1 { return false }
    if n == 2 || n == 3 { return true }
    
    let sq = Int(sqrt(Double(n)))
    
    while i <= sq {
        gaurd n % i != 0 else { return false }
        i += 1
    }
    
    return true
}
