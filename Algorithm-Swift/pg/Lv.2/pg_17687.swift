//
//  pg_17687.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/12.
//
//  [3차] n진수 게임

import Foundation

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var str = ""
    var cnt = 0
    var cnt_p = 0
    var ans = ""
    
    while ans.count < t {
        str = String(cnt, radix: n).uppercased()
        
        for s in str {
            if ans.count >= t {
                break
            }
            if cnt_p % m == (p-1) {
                ans += String(s)
            }
            cnt_p += 1
        }
        
        cnt += 1
    }
    
    return ans
}
