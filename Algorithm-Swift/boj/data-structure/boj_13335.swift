//
//  boj_13335.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/11.
//
//  트럭

import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
var trucks = readLine()!.split(separator: " ").map { Int($0)! }

let n = input[0]
let w = input[1]
let L = input[2]

var bridge = Array(repeating: 0, count: w)
var newTruckIdx = 0
var weight = 0
var ans = 0
var arrivedTruckCnt = 0

func nextBridge(_ arr: [Int]) {
    var newArr = Array(arr.reversed())
    let finish = newArr.removeLast()
    if finish != 0 { arrivedTruckCnt += 1 }
    newArr.reverse()
    weight -= finish
    bridge = newArr
}

while arrivedTruckCnt != trucks.count {
    ans += 1
    
    if newTruckIdx == trucks.count {
        nextBridge(bridge)
        continue
    }
    
    let truck = trucks[newTruckIdx]
    
    nextBridge(bridge)
    
    if weight + truck <= L {    // 다리 건널 수 있을 경우
        bridge.append(truck)
        weight += truck
        newTruckIdx += 1
    } else {
        bridge.append(0)
    }
}

print(ans)
