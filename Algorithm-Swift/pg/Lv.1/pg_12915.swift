//
//  pg_12915.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/05.
//
//  문자열 내 마음대로 정렬하기

import Foundation

func solution1(_ strings:[String], _ n:Int) -> [String] {
    let idx = strings[0].index(strings[0].startIndex, offsetBy: n)
    
    return strings.sorted { ($0[idx] == $1[idx]) ? $0 < $1 : $0[idx] < $1[idx] }
}

func solution2(_ strings:[String], _ n:Int) -> [String] {
    return strings.sorted{  Array($0)[n] == Array($1)[n] ? $0 < $1 :  Array($0)[n] < Array($1)[n] }
}
