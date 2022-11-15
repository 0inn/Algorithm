//
//  pg_42579.swift
//  Algorithm-Swift
//
//  Created by 김영인 on 2022/11/15.
//
//  베스트앨범

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var genre = [String: Int]()
    var playList = [String: [(Int, Int)]]()
    var ans = [Int]()
    
    for i in 0..<plays.count {
        let g = genres[i]
        let p = plays[i]
        
        if let song = genre[g] {
            genre[g] = song + p
        } else {
            genre[g] = p
        }
        
        if let play = playList[g] {
            playList[g]!.append((p, i))
        } else {
            playList[g] = [(p, i)]
        }
    }
    
    let sortGenre = genre.sorted { $0.1 > $1.1 }.map { String($0.0) }
    
    for g in sortGenre {
        let sortPlayList = playList[g]!.sorted { $0.0 > $1.0 }.map { Int($0.1) }
        
        if playList[g]!.count < 2 {
            ans.append(playList[g]![0].1)
            continue
        }
        for i in 0...1 {
            ans.append(sortPlayList[i])
        }
    }
    
    return ans
}
