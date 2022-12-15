//
//  boj_9935.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/12/15.
//

import Foundation

var strs = String(readLine()!)
var bombs = String(readLine()!)
let bombsCnt = bombs.count
var ans = ""

for str in strs {
    ans += String(str)
    
    if ans.hasSuffix(bombs) {
        ans.removeLast(bombsCnt)
    }
}

if ans.isEmpty {
    print("FRULA")
} else {
    print(ans)
}
