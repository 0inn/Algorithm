//
//  pg_68935.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  3진법 뒤집기

import Foundation

func solution(_ n:Int) -> Int {
    return Int(String(String(n, radix: 3).reversed()), radix: 3)!
}
