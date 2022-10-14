//
//  pg_12909.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/10/14.
//
//  올바른 괄호

import Foundation

func solution1(_ s:String) -> Bool {
    var stack = [String]()
    
    for c in s {
        if c == "(" {
            stack.append("(")
        } else {
            if stack.isEmpty { return false }
            else { stack.removeLast() }
        }
    }
    
    return (stack.isEmpty) ? true : false
}

// Stack<T> 사용
func solution2(_ s:String) -> Bool {
    var stack = Stack<String>()
    
    for c in s {
        if c == "(" {
            stack.push("(")
        } else {
            if stack.isEmpty { return false }
            else { stack.pop() }
        }
    }
    
    return (stack.isEmpty) ? true : false
}
