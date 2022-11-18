//
//  pg_64063.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/18.
//
//  호텔 방 배정

import Foundation

func solution(_ k:Int64, _ room_number:[Int64]) -> [Int64] {
    var room = [Int64: Int64]()
    var ans = [Int64]()
    
    func find(_ num: Int64) -> Int64 {
        guard let nxtRoom = room[num] else {    // 빈 방인 경우 -> 바로 배정
            room[num] = num + 1
            return num
        }
        // 빈 방이 아닌 경우 -> 다음 방 탐색
        let nxtR = find(nxtRoom)
        room[num] = nxtR + 1
        return nxtR
    }
    
    for num in room_number {
        let nxtRoom = find(num)
        ans.append(nxtRoom)
    }
    
    return ans
}
