//
//  pg_86491.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  최소직사각형

import Foundation

func solution1(_ sizes:[[Int]]) -> Int {
    var size = sizes
    var w = 0
    var h = 0
    
    for i in 0 ..< sizes.count {
        size[i].sort()
        w = max(w, size[i][0])
        h = max(h, size[i][1])
    }
    
    return w * h
}

func solution2(_ sizes:[[Int]]) -> Int {
    var maxNum = 0
    var minNum = 0
    
    for size in sizes {
        maxNum = max(maxNum, size.max()!)
        minNum = max(minNum, size.min()!)
    }
    
    return maxNum * minNum
}
