//
//  pg_12911.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2023/01/06.
//
//  롤케이크 자르기

import Foundation

//  내 풀이
func solution1(_ topping:[Int]) -> Int {
    var ans = 0
    var rollCake = [Int: Int]()
    var one = Set([topping[0]]) // 나
    var two = Set(Array(topping[1..<topping.count]))  // 동생

    for idx in 1..<topping.count {  // 롤케이크 개수 저장
        let t = topping[idx]

        if let exist = rollCake[t] {
            rollCake[t] = exist + 1
        } else {
            rollCake[t] = 1
        }
    }

    for idx in 1..<topping.count {
        let t = topping[idx]

        if one.count == two.count { ans += 1 }
        if one.count > two.count { break }

        if !one.contains(t) { // 나에게 롤케이크 추가
            one.insert(t)
        }
        if rollCake[t]! > 1 { 
            rollCake[t] = rollCake[t]! - 1
        } else {
            two.remove(t) // 동생꺼 롤케이크 제거
        }
    }

    return ans
}

//  다른 사람 풀이
func solution2(_ topping:[Int]) -> Int {
    var ans = 0
    
    var me = [Int: Int]()
    var bro = [Int: Int]()
    
    topping.forEach {
        me[$0, default: 0] += 1
    }
    
    topping.forEach {
        me[$0]! -= 1
        bro[$0, default: 0] += 1
        if me[$0]! == 0 {
            me[$0] = nil
        }
        if me.keys.count == bro.keys.count {
            ans += 1
        }
    }
    
    return ans
}
