//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution(_ n:Int) -> Int {
    var cnt = 0
    
    while true {
        cnt += 1
        if n % cnt == 1 {
            return cnt
        }
    }
}

print(solution(10))
