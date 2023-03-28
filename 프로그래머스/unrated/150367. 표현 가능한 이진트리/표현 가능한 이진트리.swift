import Foundation

var isTree: Bool = true

// 포화이진트리로 표현 가능한지 여부 확인하기
func checkIfTree(_ tree: [String], _ start: Int, _ end: Int) {
    let parent = (end + start) / 2

    // 리프 노드라면 종료
    if start == end { return }
    
    // 부모는 더미인데 자식은 더미가 아니라면 불가능
    if tree[parent] == "0" {
        let left = (start + parent - 1) / 2
        let right = (parent + 1 + end) / 2
        if tree[left] == "1" || tree[right] == "1" {
            isTree = false
            return
        }
    }
    
    checkIfTree(tree, start, parent-1)
    checkIfTree(tree, parent+1, end)
}

// 포화이진트리 만들기
func makeTree(_ num: String) -> [String] {
    var tree = num
    let cnt = num.count
    let log = Int(log2(Double(num.count)) + 1)
    let treeCnt = Int(pow(2, Double(log))) - 1

    for _ in 0..<Int(treeCnt-cnt) {
        tree = "0" + tree
    }
    
    let treeArr = tree.map { String($0) }
    
    return treeArr
}

func solution(_ numbers:[Int64]) -> [Int] {
    var ans: [Int] = []
    
    for num in numbers {
        isTree = true
        
        let treeArr = makeTree(String(num, radix: 2))
        checkIfTree(treeArr, 0, treeArr.count-1)
        
        if isTree {
            ans.append(1)
        } else {
            ans.append(0)
        }
    }
    
    return ans
}