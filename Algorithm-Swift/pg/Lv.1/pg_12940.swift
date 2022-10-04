//
//  pg_12940.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  최대공약수와 최소공배수

func solution(_ n:Int, _ m:Int) -> [Int] {
    return [GCD(m, n), LCM(m, n)]
}

func GCD(_ n: Int, _ m: Int) -> Int {
    return (n % m == 0) ? min(n, m) : GCD(m , n % m)
}

func LCM(_ n: Int, _ m: Int) -> Int {
    return n * m / GCD(n, m)
}
