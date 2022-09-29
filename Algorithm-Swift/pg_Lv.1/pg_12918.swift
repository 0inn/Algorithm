//
//  pg_12918.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

 func solution1(_ s:String) -> Bool {
     return (s.count == 4 || s.count == 6) && !(s.map { Int(String($0)) != nil }.contains(false))
 }

func solution2(_ s:String) -> Bool {
    return (s.count == 4 || s.count == 6) && Int(s) != nil ? true : false
}
