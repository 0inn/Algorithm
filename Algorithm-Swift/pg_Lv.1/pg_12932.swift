//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution(_ n:Int64) -> [Int] {
    var arr = String(n).map{ Int(String($0))! }
    
    return arr.reversed()
}

print(solution(12345))
