//
//  pg_12901.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/07.
//
//  2016

import Foundation

func solution1(_ a:Int, _ b:Int) -> String {
    let days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    var day = 0
    var cnt = 4
    for i in 1 ..< a {
        switch i {
            case 1, 3, 5, 7, 8, 10, 12:
                day = 31
            case 2:
                day = 29
            default:
                day = 30
        }
        for _ in 1 ... day {
            (cnt == 6) ? (cnt = 0) : (cnt += 1)
        }
    }
    for _ in 1 ... b {
        (cnt == 6) ? (cnt = 0) : (cnt += 1)
    }
    return days[cnt]
}

func solution2(_ a:Int, _ b:Int) -> String {
    let days = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]
    let months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    let total = months[0..<a-1].reduce(0, +) + b
    return days[total % 7]
}
