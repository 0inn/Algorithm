//
//  pg_17680.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/19.
//
//  [1차] 캐시

import Foundation

func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    var cache = [String]()
    var ans = 0
    var citiesArr = cities.map { $0.lowercased() }
    
    if cacheSize == 0 { return cities.count * 5 }
    
    for city in citiesArr {
        if !cache.contains(city) {
            if cache.count == cacheSize { cache.removeFirst() }
            cache.append(city)
            ans += 5
        } else {
            cache.remove(at: cache.firstIndex(of: city)!)
            cache.append(city)
            ans += 1
        }
    }
    
    return ans
}
