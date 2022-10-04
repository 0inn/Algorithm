//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/28.
//

import Foundation

func solution(_ a:Int, _ b:Int) -> Int64 {
    var ans = 0
    
    for i in min(a, b) ... max(a, b) {
        ans += i
    }
    
    return Int64(ans)
}

print(solution(3, 5))
