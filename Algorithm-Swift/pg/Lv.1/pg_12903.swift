//
//  pg_12903.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

 func solution1(_ s:String) -> String {
     if s.count == 1 || s.count == 2 { return s }
     var evenIdx = s.index(s.startIndex, offsetBy: s.count/2 - 1)
     var idx = s.index(s.startIndex, offsetBy: s.count/2)
     return s.count % 2 != 0 ? String(s[idx]) : String(s[evenIdx...idx])
 }

func solution2(_ s:String) -> String {
    return s.count % 2 != 0 ? String(Array(s)[s.count/2]) : String(Array(s)[(s.count/2 - 1)...(s.count/2)])
}
