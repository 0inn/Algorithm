//
//  pg_92335.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/02.
//
//  k진수에서 소수 개수 구하기

import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    var nums = String(n, radix: k).split(separator: "0").map { Int($0)! }.filter { $0 != 1 }.sorted { $0 > $1 }
    var ans = 0
    
    // 소수 판별
    func isPrime(_ n: Int) -> Bool {
        var i = 2
        
        while i <= Int(sqrt(Double(n))) {
            guard n % i != 0 else {
                return false
            }
            i += 1
        }
        
        return true
    }
    
    for num in nums {
        if isPrime(num) {
            ans += 1
        }
    }
    
    return ans
}
