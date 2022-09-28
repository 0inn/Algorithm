//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/28.
//

import Foundation

func solution(_ num:Int) -> Int {
    var cnt = 0
    var n = num
    
    while true {
        if n == 1 {
            if cnt == 0 { return 0 }
            else { return cnt }
        }
        if cnt == 500 { return -1 }
        n = n % 2  == 0 ? n / 2 : n * 3 + 1
        cnt += 1
    }
}

print(solution(6))
