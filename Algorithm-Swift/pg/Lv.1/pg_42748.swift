//
//  pg_42748.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  K번째수

import Foundation

func solution1(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var ans = [Int]()
    for cmd in commands {
        ans.append(Array(array[cmd[0]-1..<cmd[1]]).sorted()[cmd[2]-1])
    }
    return ans
}

func solution2(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    return commands.map { (cmd) in
        Array(array[cmd[0]-1..<cmd[1]]).sorted()[cmd[2]-1]
    }
}
