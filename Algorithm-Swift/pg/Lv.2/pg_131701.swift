//
//  pg_131701.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/31.
//
//  연속 부분 수열 합의 개수

import Foundation

func solution(_ elements:[Int]) -> Int {
    var arr = elements
    var ans = Set<Int>()
    var tmp = elements.first! + elements.last!
    
    ans.insert(arr[0])
    for i in 1..<arr.count {
        arr[i] += arr[i-1]
        ans.insert(arr[i])
        for j in stride(from: i - 1, through: 0, by: -1) {
            ans.insert(arr[i] - arr[j])
        }
    }
    
    ans.insert(tmp)
    for i in 1..<arr.count-1 {
        arr[i] -= arr[0]
        ans.insert(tmp + arr[i])
    }
    
    arr = elements
    ans.insert(tmp + arr[arr.count - 2])
    for i in stride(from: arr.count - 3, to: 0, by: -1) {
        arr[i] += arr[i + 1]
        ans.insert(tmp + arr[i])
    }
    
    return ans.count
}
