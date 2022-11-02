//
//  pg_92341.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/02.
//
//  주차 요금 계산

import Foundation

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var carInfos = [String : [[String]]]()
    let minute = fees[0]
    let fee = fees[1]
    let perMinute = fees[2]
    let perFee = fees[3]
    var ans = [Int]()
    
    for rec in records {
        let info = rec.split(separator: " ").map { String($0) }
        if let _ = carInfos[info[1]] {
            carInfos[info[1]]!.append([info[0], info[2]])
        } else {
            carInfos[info[1]] = [[info[0], info[2]]]
        }
    }
    
    let carResult = carInfos.sorted { Int($0.0)! < Int($1.0)! }
    for car in carResult {
        let timeArr = car.value
        var time = [[Int]]()
        var totalMinute = 0
        
        for i in 0..<timeArr.count {
            let tmpTime = timeArr[i][0].split(separator: ":").map { Int($0)! }
            if timeArr[i][1] == "IN" {
                time.append([tmpTime[0], tmpTime[1]])
            } else {
                let before = time.last!
                let cur = tmpTime
                totalMinute += (cur[1] - before[1]) + (cur[0] - before[0]) * 60
                time.removeLast()
            }
        }
        
        if !time.isEmpty {
            totalMinute += (59 - time[0][1]) + (23 - time[0][0]) * 60
        }
        
        var timeFee = ceil(Double(totalMinute - minute) / Double(perMinute))
        if timeFee < 0 { timeFee = 0 }
        ans.append(fee + Int(timeFee) * perFee)
    }
    
    return ans
}
