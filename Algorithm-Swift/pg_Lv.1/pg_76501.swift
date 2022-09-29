//
//  pg_76501.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution(_ absolutes:[Int], _ signs:[Bool]) -> Int {
    var ans = 0
    for i in 0..<signs.count {
        ans += signs[i] ? absolutes[i] : absolutes[i] * -1
    }
    return ans
}
