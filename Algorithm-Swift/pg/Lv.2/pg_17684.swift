//
//  pg_17684.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/03.
//
//  [3차] 압축

import Foundation

func solution(_ msg:String) -> [Int] {
    var dict = [String: Int]()
    let msg = Array(msg)
    var str = ""
    var idx = 1
    var ans = [Int]()
    
    for alphabet in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" {
        dict[String(alphabet)] = idx
        idx += 1
    }
    
    idx = 0
    var addIdx = 27
    var answer = 0
    
    while idx < msg.count {
        str = String(msg[idx])
        
        // 현재 입력
        while true {
           if let find = dict[str] {
               if idx == msg.count - 1 {
                   ans.append(find)
                   return ans
               } else { // 다음 글자
                   idx += 1
                   str += String(msg[idx])
               }
               answer = find
           } else {
               break
           }
        }
        
        // 사전 추가
        if dict[str] == nil {
            dict[str] = addIdx
            addIdx += 1
        }
        
        // 출력
        ans.append(answer)
    }
    
    return ans
}
