//
//  pg_92334.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  신고 결과 받기

import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var repDict = [String: [String]]()
    var badDict = [String: Int]()
    var ans = [Int]()
    
    for id in id_list {
        repDict[id] = [String]()
        badDict[id] = 0
    }
    
    // 아이디 신고하기
    for r in report {
        var myId = String(r.split(separator: " ")[0])
        var badId = String(r.split(separator: " ")[1])
        if repDict[myId]!.contains(badId) { continue }
        repDict[myId]!.append(badId)
        badDict[badId] = badDict[badId]! + 1
    }
    
    // 정지된 아이디 개수 구하기
    for id in id_list {
        ans.append(repDict[id]!.filter { badDict[$0]! >= k }.count)
    }
    
    return ans
}
