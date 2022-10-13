//
//  pg_67256.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/13.
//
//  키패드 누르기

import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
    var ans = ""
    var left = 10
    var right = 12
    
    for num in numbers {
        var n = num
        if n == 0 { n = 11 }
        if n % 3 == 1 { // 왼손
            left = n
            ans += "L"
        } else if n % 3 == 0 {  // 오른손
            right = n
            ans += "R"
        } else {
            let l = abs(left-n) / 3 + abs(left-n) % 3
            let r = abs(right-n) / 3 + abs(right-n) % 3
            if l < r || (l == r && hand == "left") {    // 왼손
                left = n
                ans += "L"
            } else if l > r || (l == r && hand == "right") {    // 오른손
                right = n
                ans += "R"
            }
        }
    }
    
    return ans
}
