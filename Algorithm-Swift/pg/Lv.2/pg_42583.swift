//
//  pg_42583.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/13.
//
//  다리를 지나는 트럭

import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var truck = truck_weights
    var bridge = Array(repeating: 0, count: bridge_length)
    var w = 0
    var ans = 0
    
    while !bridge.isEmpty {
        ans += 1
        
        w -= bridge.removeFirst()
        
        if !truck.isEmpty {
            if w + truck.first! <= weight {
                let t = truck.removeFirst()
                w += t
                bridge.append(t)
            } else {
                bridge.append(0)
            }
        }
    }
    
    return ans
}
