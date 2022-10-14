//
//  pg_12951.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  JadenCase 문자열 만들기

import Foundation

func solution(_ str:String) -> String {
    var s = str.lowercased()
    var ans = ""
    var flag = true
    
    for c in s {
        if c == " " {
            ans += " "
            flag = true
        }
        else {
            if flag {
                ans += c.uppercased()
                flag = false
            } else { ans += "\(c)" }
        }
    }
    
    return ans
}
