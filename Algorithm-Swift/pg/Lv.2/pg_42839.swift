//
//  pg_42839.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/27.
//
//  소수 찾기

import Foundation

func permutation<T: Comparable>(_ arr: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if arr.count < n { return result }
    
    var visit = Array(repeating: false, count: arr.count)
    
    func cycle(_ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        for i in 0..<arr.count {
            if visit[i] { continue }
            visit[i] = true
            cycle(now + [arr[i]])
            visit[i] = false
        }
    }
    
    cycle([])
    
    return result
}

func solution(_ numbers:String) -> Int {
    var nums = Array(numbers)
    var n = Int(String(numbers.sorted { $0 > $1 }))!
    var primeArr = [Int](repeating: 0, count: n + 1)
    var ans = Set<Int>()
    
    for i in 2...n {
        primeArr[i] = i
    }
    
    for i in 2...n {
        if primeArr[i] == 0 {
            continue
        }
        
        for j in stride(from: i*i, through: n, by: i) {
            primeArr[j] = 0
        }
    }
    
    for n in 1...nums.count {
        for p in permutation(nums, n).map({ Int(String($0))! }) {
            print(p)
            if primeArr[p] != 0 {
                ans.insert(p)
            }
        }
    }
    
    return ans.count
}
