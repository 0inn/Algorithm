//
//  pg_12953.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/18.
//
//  N개의 최소공배수

import Foundation

func gcd(_ m: Int, _ n: Int) -> Int {
    return m % n == 0 ? min(m, n) : gcd(n, m % n)
}

func lcm(_ m: Int, _ n: Int) -> Int {
    return m * n / gcd(m, n)
}

func solution1(_ arr:[Int]) -> Int {
    var ans = lcm(arr[0], arr[1])
    
    for idx in 2..<arr.count {
        ans = lcm(ans, arr[idx])
    }
    
    return ans
}

func solution2(_ arr:[Int]) -> Int {
    return arr.reduce(1) { lcm($0, $1) }
}
