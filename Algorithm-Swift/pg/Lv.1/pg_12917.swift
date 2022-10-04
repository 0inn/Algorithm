//
//  pg_12917.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/29.
//

import Foundation

func solution1(_ s:String) -> String {
    return String(Array(s).sorted { $0 > $1 })
}

func solution2(_ s:String) -> String {
    return String(s.sorted { $0 > $1 })
}
