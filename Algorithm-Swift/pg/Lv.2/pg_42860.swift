//
//  pg_42860.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/02.
//
//  조이스틱

import Foundation

func solution(_ name:String) -> Int {
    let alphabet = Array("ABCDEFGHIJKLMNZYXWVUTSRQPO")
    var name = Array(name)
    var updown = 0
    var len = name.count
    var leftright = len - 1

    for idx in 0..<name.count {
        // 위 아래
        var alpha = alphabet.firstIndex(of: name[idx]) ?? 0
        if alpha > 13 { alpha -= 13 }
        updown += alpha
        
        // 좌우
        var nxtIdx = idx + 1
        while nxtIdx < len && name[nxtIdx] == "A" {
            nxtIdx += 1
        }
        
        // 앞으로 돌아가는 경우 vs. 뒤로 돌아가는 경우
        let front = (len - nxtIdx) + idx * 2
        let back = idx + (len - nxtIdx) * 2
        
        let frontback = min(front, back)
        leftright = min(leftright, frontback)
    }
    
    return updown + leftright
}
