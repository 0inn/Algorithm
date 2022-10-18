//
//  pg_43165.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/07.
//
//  타겟 넘버

import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var ans = 0
    
    func dfs(_ cnt: Int, _ sum: Int) {
        if cnt == numbers.count {
            if sum == target { ans += 1 }
            return
        }
        dfs(cnt + 1, sum + numbers[cnt])
        dfs(cnt + 1, sum - numbers[cnt])
    }
    
    dfs(0, 0)
    
    return ans
}
