//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/28.
//

import Foundation

func solution1(_ seoul:[String]) -> String {
    for i in 0...seoul.count {
        if seoul[i] == "Kim" {
            return "김서방은 \(i)에 있다"
        }
    }
    return ""
}

func solution2(_ seoul:[String]) -> String {
    
    return "김서방은 \(seoul.firstIndex(of: "Kim")!)에 있다"
}

print(solution1(["Kim", "0inn"]), solution2(["Kim", "0inn"]))
