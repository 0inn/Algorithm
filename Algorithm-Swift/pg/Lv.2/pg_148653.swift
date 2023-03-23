//
//  pg_148653.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/03/23.
//

import Foundation

func solution(_ storey: Int) -> Int {
    var floor = storey
    var ans = 0
    
    while (floor != 0) {
        let cur = floor % 10
        let nxt = (floor / 10) % 10
        
        floor /= 10
        
        if cur > 5 {
            ans += (10 - cur)
            floor += 1
        } else if cur < 5 {
            ans += cur
        } else {
            ans += cur
            if nxt >= 5 {
                floor += 1
            }
        }
    }
    
    return ans
}
