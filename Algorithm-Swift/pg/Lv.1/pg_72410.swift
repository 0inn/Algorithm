//
//  pg_72410.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/13.
//
//  신규 아이디 추천

import Foundation

// 배열로 만들어 풀기
func solution1(_ new_id:String) -> String {
    // 1
    var id = new_id.lowercased()
    // 2
    var arr = Array(id).filter { $0.isLetter || $0.isNumber || $0 == "-" ||  $0 == "_" || $0 == "." }
    // 3
    for i in 0..<arr.count-1 {
        if (arr[i] == arr[i+1] && arr[i] == ".") { arr[i] = " " }
    }
    var arr2 = arr.filter { $0 != " " }
    // 4
    if !arr2.isEmpty {
        if arr2[0] == "." { arr2.removeFirst() }
    }
    if !arr2.isEmpty {
        if arr2[arr2.count-1] == "." { arr2.remove(at: arr2.count-1) }
    }
    // 5
    if arr2.isEmpty { arr2.append("a") }
    // 6
    if arr2.count >= 16 {
        arr2.removeSubrange(15..<arr2.count)
        if arr2[14] == "." { arr2.remove(at: 14) }
    }
    // 7
    var tmp = " "
    if !arr2.isEmpty {
        tmp = String(arr2[arr2.count-1])
    }
    while arr2.count < 3 {
        arr2.append(contentsOf: tmp)
    }
    return String(arr2)
}

// 문자열 형태로 풀기
func solution2(_ new_id:String) -> String {
    // 1
    var id = new_id.lowercased()
    // 2
    var arr = Array(id).filter { $0.isLetter || $0.isNumber || $0 == "-" ||  $0 == "_" || $0 == "." }
    // 3
    var newId = String(arr)
    while newId.contains("..") {
        newId = newId.replacingOccurrences(of: "..", with: ".")
    }
    // 4
    if newId.hasPrefix(".") { newId.removeFirst() }
    if newId.hasSuffix(".") { newId.removeLast() }
    // 5
    if newId.isEmpty { newId = "a" }
    // 6
    if newId.count >= 16 {
        let index = newId.index(newId.startIndex, offsetBy: 15)
        newId = String(newId[newId.startIndex..<index])
        if newId.hasSuffix(".") { newId.removeLast() }
    }
    // 7
    while newId.count < 3 {
        newId += String(newId.last!)
    }
    return newId
}
