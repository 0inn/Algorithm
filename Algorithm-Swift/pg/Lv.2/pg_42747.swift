//
//  pg_42747.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/19.
//
//  H-Index

import Foundation

func solution1(_ citations:[Int]) -> Int {
    let arr = citations.sorted { $0 > $1 }
    var h = 0

    for idx in 0 ..< arr.count {
        if idx + 1 > arr[idx] {
            h = idx
            break
        }
        else if idx + 1 == arr[idx] {
            h = arr[idx]
            break
        }
        else if idx == arr.count - 1 { h = arr.count }
    }

    return h
}

func solution2(_ citations:[Int]) -> Int {
    let arr = citations.sorted { $0 > $1 }
    var ans = 0
    
    for idx in 0 ..< arr.count {
        if idx + 1 <= arr[idx] {
            ans += 1
        } else { break }
    }
    
    return ans
}
