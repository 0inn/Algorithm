//
//  pg_12939.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  최댓값과 최솟값

import Foundation

func solution(_ s:String) -> String {
    var ans = s.split(separator: " ").map { Int($0)! }.sorted()
    return "\(ans[0]) \(ans[ans.count-1])"
}
