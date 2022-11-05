//
//  pg_42888.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/05.
//
//  오픈채팅방

import Foundation

func solution(_ record:[String]) -> [String] {
    var ans = [String]()
    var dict = [String: String]()
    
    for r in record {
        var info = r.split(separator: " ").map { String($0) }
        if info[0] != "Leave" {
            dict[info[1]] = info[2]
        }
    }
    
    for r in record {
        var info = r.split(separator: " ").map { String($0) }
        if info[0] == "Enter" {
            ans.append("\(dict[info[1]]!)님이 들어왔습니다.")
        } else if info[0] == "Leave" {
            ans.append("\(dict[info[1]]!)님이 나갔습니다.")
        }
    }
    
    return ans
}
