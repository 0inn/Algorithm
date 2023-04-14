import Foundation

var ans = 0, cnt = 0, ansWord = ""
var words = ["A", "E", "I", "O", "U"]

func sol(_ str: String) {
    var str = str
    
    if str == ansWord { 
        ans = cnt
        return 
    }
    cnt += 1
    
    if str.count == 5 { return }
    
    for i in 0..<5 {
        str += words[i]
        sol(str)
        str.removeLast()
    }
}

func solution(_ word: String) -> Int {
    ansWord = word
    
    sol("")
    
    return ans
}