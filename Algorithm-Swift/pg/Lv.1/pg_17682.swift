//
//  pg_17682.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/12.
//
// [1차] 다트 게임

import Foundation

func solution(_ dartResult:String) -> Int {
    var num = ""
    var nums = [Int]()
    
    for i in Array(dartResult) {
        print(i.isLetter)
        print(i.isNumber)
        if i == "S" {
            nums.append(Int(num)!)
            num = ""
        } else if i == "D" {
            nums.append(Int(pow(Float(num)!, 2)))
            num = ""
        } else if i == "T" {
            nums.append(Int(pow(Float(num)!, 3)))
            num = ""
        } else if i == "*" {
            if nums.count > 1 {
                nums[nums.count-2] *= 2
            }
            nums[nums.count-1] *= 2
        } else if i == "#" {
            nums[nums.count-1] *= -1
        } else {
            num += String(i)
        }
    }
    
    return nums.reduce(0, +)
}
