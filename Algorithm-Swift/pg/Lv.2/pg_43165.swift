//
//  pg_43165.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/07.
//

import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var ans = 0
    
    func dfs(_ idx: Int, _ sum: Int) {
        if idx == numbers.count {
            if sum == target {
                ans += 1
            }
            return
        }
        
        dfs(idx + 1, sum + numbers[idx])
        dfs(idx + 1, sum - numbers[idx])
    }
    
    dfs(0, 0)
    
    return ans
}
