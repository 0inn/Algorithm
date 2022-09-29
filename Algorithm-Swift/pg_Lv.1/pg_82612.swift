//
//  pg_82612.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/30.
//
//  부족한 금액 계산하기

import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var ans = Int64((1...count).map { $0 * price }.reduce(0, +) - money)
    return ans > 0 ? ans : 0
}
