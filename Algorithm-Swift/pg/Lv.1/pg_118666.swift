//
//  pg_118666.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  성격 유형 검사하기

import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var dict = ["R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0]
    var score = [0, 3, 2, 1, 0, 1, 2, 3]
    var ans = ["R", "C", "J", "A"]
    
    for i in 0..<survey.count {
        var c = choices[i]
        if c < 4 {
            dict[String(survey[i].first!)] = score[c] + dict[String(survey[i].first!)]!
        } else {
            dict[String(survey[i].last!)] = score[c] + dict[String(survey[i].last!)]!
        }
    }

    if dict["R"]! < dict["T"]! { ans[0] = "T" }
    if dict["C"]! < dict["F"]! { ans[1] = "F" }
    if dict["J"]! < dict["M"]! { ans[2] = "M" }
    if dict["A"]! < dict["N"]! { ans[3] = "N" }
    
    return ans.joined(separator: "")
}
