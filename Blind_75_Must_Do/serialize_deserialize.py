# Definition for a binary tree node.

from typing import Union
class TreeNode:
   def __init__(self, x):
       self.val = x
       self.left = None
       self.right = None

class Codec:
    def __init__(self):
        self.des =[]
        self.ind = 0
    def serialize(self, root: Union[TreeNode, None]) -> str:
        """Encodes a tree to a single string.
        """
        if(root==None):
            return "$"
        return "#".join([str(root.val),self.serialize(root.left),self.serialize(root.right)])
        
     
    def deserialize(self, data: str) :
        """Decodes your encoded data to tree.
        """
        self.ind =0
        self.des = data.split("#")
        return self.des2()
        
    def des2(self ):
        if (self.ind > len(self.des)):
            return None
        last_str = self.des[self.ind]
        self.ind+=1
        if(last_str=="$"):
            return None
        nd = TreeNode(int(last_str))
        nd.left = self.des2()
        nd.right = self.des2()
        return nd
        
        
# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
