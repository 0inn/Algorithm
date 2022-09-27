//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution(_ x:Int) -> Bool {
    
    var num = x % Int(String(x).map { Int(String($0))! }.reduce(0, +))
    
    var ans = num == 0 ? true : false
    
    return ans
}

print(solution(10))
