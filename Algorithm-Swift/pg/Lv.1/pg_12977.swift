//
//  pg_12977.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/12.
//
//  소수 만들기

import Foundation

func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return result }
    func cycle(_ index: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    cycle(0, [])
    return result
}

func isPrime(_ n: Int) -> Bool {
    var primes = [Bool](repeating: true, count: n+1)
    for i in 2...n {
        if primes[i] && i == n {
            return primes[n]
        }
        for j in 1...(n/i) {
            primes[i*j] = false
        }
    }
    return primes[n]
}

func solution(_ nums:[Int]) -> Int {
    var arr = combination(nums, 3)
    return arr.map { $0.reduce(0, +) }.filter { isPrime($0) }.count
}
