//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution1(_ n:Int64) -> Int64 {
    
    var arr = String(n).map { Int(String($0))! }
    arr.sort { return $0 > $1 }
    var ans = Int64(arr.map { String($0) }.joined(separator: ""))
    
    return ans!
}

func solution2(_ n:Int64) -> Int64 {
    
    return Int64(String(String(n).sorted{ return $0 > $1}))!
}

print(solution1(118372), solution2(118372))
