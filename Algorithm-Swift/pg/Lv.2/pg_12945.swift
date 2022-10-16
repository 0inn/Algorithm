//
//  pg_12945.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/16.
//
//  피보나치 수

import Foundation

func solution(_ n:Int) -> Int {
    var fibo = Array(repeating: 0, count: 100001)
    
    fibo[0] = 0
    fibo[1] = 1
    
    for i in 2...n {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567
    }
    
    return fibo[n]
}
