//
//  pg_42883.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/09.
//
//  큰 수 만들기

import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var num = number.map { String($0) }
    var cnt = 0
    var ans = [String]()
    
    for i in 0..<num.count {
        while cnt < k && !ans.isEmpty && ans.last! < num[i] {
            ans.removeLast()
            cnt += 1
        }
        
        ans.append(num[i])
        
        if i == num.count - 1 && cnt < k {
            ans = ans[0..<num.count - (k - cnt)].map { String($0) }
        }
    }
    
    return ans.joined(separator: "")
}
