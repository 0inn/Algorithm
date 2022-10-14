//
//  pg_131128.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  숫자 짝꿍

import Foundation

func solution(_ X:String, _ Y:String) -> String {
    var arrX = [Int](repeating: 0, count: 10)
    var arrY = [Int](repeating: 0, count: 10)
    var ans = ""
    
    for x in X { arrX[Int(String(x))!] += 1 }
    for y in Y { arrY[Int(String(y))!] += 1 }
    for i in 0...9 {
        if arrX[i] == 0 || arrY[i] == 0 { continue }
        var cnt = min(arrX[i], arrY[i])
        for _ in 0..<cnt { ans += "\(i)" }
    }
    ans = String(ans.sorted { $0 > $1 })
    if !ans.isEmpty {
        while ans.first! == "0" {
            if ans.count == 1 { break }
            ans.removeFirst()
        }
    }
    
    return (ans == "") ? "-1" : ans
}
