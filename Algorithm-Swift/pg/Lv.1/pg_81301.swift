//
//  pg_81301.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  숫자 문자열과 영단어

import Foundation

func solution1(_ s:String) -> Int {
    var ans = ""
    var i = 0
    while true {
        if i == s.count { return Int(ans)! }
        let idx = s.index(s.startIndex, offsetBy: i)
        let nextIdx = s.index(s.startIndex, offsetBy: i+1)
        if s[idx] == "z" {
            ans += "0"
            i += 4
        } else if s[idx] == "o" {
            ans += "1"
            i += 3
        } else if s[idx] == "t" {
            ans += (s[nextIdx] == "w") ? "2" : "3"
            i += (s[nextIdx] == "w") ? 3 : 5
        } else if s[idx] == "f" {
            ans += (s[nextIdx] == "o") ? "4" : "5"
            i += 4
        } else if s[idx] == "s" {
            ans += (s[nextIdx] == "i") ? "6" : "7"
            i += (s[nextIdx] == "i") ? 3 : 5
        } else if s[idx] == "e" {
            ans += "8"
            i += 5
        } else if s[idx] == "n" {
            ans += "9"
            i += 4
        } else {
            ans += String(s[idx])
            i += 1
        }
    }
}

func solution2(_ s:String) -> Int {
    let arr = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    var str = s
    
    for i in 0..<arr.count {
        str = str.replacingOccurrences(of: arr[i], with: String(i))
    }
    
    return Int(str)!
}
