class Node:
    def __init__(self,data=None):
        self.parent=None
        self.left=None
        self.right=None
        self.data = data

def isASym(val):
    if val in ["+","-","*","/","^","%"]:
        return True
    return False

def getPriority(val):
    if(val=="+" or val =="-"):
        return 3
    elif(val=="/"  or val =="*"  or val == "%"):
        return 2
    elif(val == "^") :
        return 1
    else:
        return 0

def main():
    inp=[]
    exprString=input()
    i=0
    tmp=""
    while(i< len(exprString)):
        if(exprString[i]=="(" or exprString[i]==")" or isASym(exprString[i])):
            inp.append(exprString[i])
            i+=1
            continue
        elif(exprString[i] == ' '):
            i+=1
            continue
        elif(ord('0')<=ord(exprString[i]) <= ord('9')):
            tmp=""
            while(i<len(exprString) and ord('0')<=ord(exprString[i])<=ord('9')):
                tmp+=exprString[i]
                i+=1
            inp.append(tmp)
        else:
            tmp=""
            while( i<len(exprString) and (exprString[i] not in ["(",")"," "] and not isASym(exprString[i]))):
                tmp+=exprString[i]
                i+=1
            inp.append(tmp)
    return inp

# places the operation node in right place
def getPriorityRight(node,op):
    if(node.parent == None):
        node.parent = Node(op)
        node.parent.left = node
        node = node.parent
        return node
    if(getPriority(node.parent.data)<=getPriority(op)): # gives left associativity due to = 
        node = node.parent
        return getPriorityRight(node,op)
    else:
        tmp = Node(op)
        tmp.left = node
        tmp.parent = node.parent
        node.parent.right = tmp
        tmp.left.parent = tmp
        node = tmp
        return node


def getExprTree(expr):
    node = Node()
    i=0
    while(i<len(expr)):
        tok = expr[i]
        if(isASym(tok)):
            node = getPriorityRight(node,tok)
        elif(tok == "("):
            stack=["("]
            initial = i
            i+=1
            while(len(stack)!=0):
                if(expr[i]==")"):
                    stack.pop()
                if(expr[i]=="("):
                    stack.append("(")
                i+=1
            i-=1
            tmpNode = getExprTree(expr[initial+1:i])
            if(node.data==None):
                node=tmpNode
                i+=1
                continue
            node.right=tmpNode
            node.right.parent = node
            node = node.right
        else:
            if(node.data==None):
                node.data=tok
                i+=1
                continue
            node.right = Node(tok)
            node.right.parent = node
            while(node.right!=None):
                node=node.right
        i+=1
    while(node.parent != None):
        node = node.parent
    return node

def printInOrder(exprTree):
    if(exprTree ==None):
        return
    printInOrder(exprTree.left)
    print(exprTree.data,end=" ")
    printInOrder(exprTree.right)


def printPostOrder(exprTree):
    if(exprTree ==None):
        return
    printPostOrder(exprTree.left)
    printPostOrder(exprTree.right)
    print(exprTree.data,end=" ")

def printPreOrder(exprTree):
    if(exprTree ==None):
        return
    print(exprTree.data,end=" ")
    printPreOrder(exprTree.left)
    printPreOrder(exprTree.right)

# inp = "2 + 3 - 4 * 5 + ( 6 ^ 2 ) * 8 / 9 / 10 * 4 + 5".split()
inp = main()
a = getExprTree(inp)
printPreOrder(a)
print()
printPostOrder(a)
print()
printInOrder(a)
print()
