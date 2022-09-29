//
//  pg_12922.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution(_ n:Int) -> String {
    var ans = ""
    (1...n).map{ ($0 % 2 == 1) ? (ans += "수") : (ans += "박") }
    return ans
}
