//
//  pg_12941.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  최솟값 만들기

import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int {
    return zip(A.sorted(), B.sorted { $0 > $1 }).map { $0 * $1 }.reduce(0, +)
}
