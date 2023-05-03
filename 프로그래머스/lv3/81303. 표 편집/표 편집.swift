import Foundation

func solution(_ n:Int, _ k:Int, _ cmds:[String]) -> String {
    var f: String = "", s: Int = 0
    var up: [Int] = []
    var down: [Int] = []
    var cur: Int = k
    var stack: [Int] = []
    var ans: [String] = Array(repeating: "O", count: n)
    
    var num = -1
    for _ in 0..<n {
        up.append(num)
        down.append(num + 2)
        num += 1
    }
    
    func move() {
        if f == "D" {
            for _ in 0..<s {
                cur = down[cur]
            }
        } else if f == "U" {
            for _ in 0..<s {
                cur = up[cur]
            }
        } else if f == "C" {
            stack.append(cur)
            
            if up[cur] != -1 {
                down[up[cur]] = down[cur]
            }
            if down[cur] != n {
                up[down[cur]] = up[cur]  
            }
            
            cur = (down[cur] == n) ? up[cur] : down[cur]
        } else { // Z
            if let z = stack.popLast() {
                if up[z] != -1 {
                    down[up[z]] = z
                }
                if down[z] != n {
                    up[down[z]] = z
                }
            }
        } 
    }
    
    for cmd in cmds {
        let c = cmd.split(separator: " ")
        f = String(c[0])
        if c.count > 1 {
            s = Int(c[1])!
        }
        move()
    }
    
    for s in stack {
        ans[s] = "X"
    }
    
    return ans.joined(separator: "")
}