//
//  pg_12948.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution(_ str:String) -> String {
    var ans = String(repeating: "*", count: str.count - 4)
    var startIndex = str.index(str.endIndex, offsetBy: -4)
    
    ans += str[startIndex..<str.endIndex]
    
    return ans
}

print(solution("01033334444"))
