//
//  main.swift
//  Algorithm-c++
//
//  Created by 김영인 on 2023/11/05.
//

import Foundation

let a = "a", b = "b"

let input = readLine()!.map { String($0) }
let str = input + input
let len = str.count

var ans = Int.max

func solution() -> Int {
    var start = 0, end = input.count - 1
    
    while end < len {
        var cnt = 0
        var left = start, right = end
        
        while(left < right) {
            if str[left] == a {
                left += 1
            } else if str[right] == b {
                right -= 1
            } else {
                cnt += 1
                left += 1
                right -= 1
            }
        }
        
        ans = min(ans, cnt)
        start += 1
        end += 1
    }
    
    return ans
}

print(solution())
