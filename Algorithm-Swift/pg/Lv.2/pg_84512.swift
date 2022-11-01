//
//  pg_84512.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/01.
//
//  모음사전

import Foundation

func solution(_ word:String) -> Int {
    let str = ["A","E","I","O","U"]
    let num = [781, 156, 31, 6, 1]
    let arr = Array(word)
    var ans = word.count
    
    for i in 0..<arr.count {
        ans += num[i] * str.firstIndex(of: String(arr[i]))!
    }
    
    return ans
}
