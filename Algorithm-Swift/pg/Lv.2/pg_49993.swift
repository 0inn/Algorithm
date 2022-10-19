//
//  pg_49993.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/19.
//
//  스킬트리

import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var ans = 0
    
    for skills in skill_trees {
        var cnt = 0
        for s in Array(skills) {
            var idx = Array(skill).firstIndex(of: s)
            if idx == cnt { cnt += 1 }
            else if idx != nil {
                ans -= 1
                break
            }
        }
        ans += 1
    }
    
    return ans
}
