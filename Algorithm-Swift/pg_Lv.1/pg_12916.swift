//
//  main.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/09/27.
//

import Foundation

func solution(_ s:String) -> Bool
{
    var arr = String(s).map { String($0) }

    var p = arr.filter { $0 == "p" || $0 == "P"}
    var y = arr.filter { $0 == "y" || $0 == "Y"}
    
    var ans = p.count == y.count ? true : false
    
    return ans
}

print(solution("pPoooyY"))
