from typing import List
import collections
class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
class BinaryTree:
    #这是二叉树的中序遍历，方法递归   顺序为左中右
    def inorderTraversal(self,root:TreeNode)->List[int]:
        if not root:
            return []
        left=self.inorderTraversal(root.left)
        right=self.inorderTraversal(root.right)
        return left+[root.val]+right
    #二叉树的前序遍历,递归版本  顺序为中左右
    def preorderTraversal(self,root:TreeNode)->List[int]:
        if not root:
            return []
        left=self.preorderTraversal(root.left)
        right=self.preorderTraversal(root.right)
        return [root.val]+left+right
    #二叉树的后序遍历,递归版本 顺序为左右中
    def postorderTraversal(self,root:TreeNode)->List[int]:
        if not root:
            return []
        left=self.postorderTraversal(root.left)
        right=self.postorderTraversal(root.right)
        return left+[root.val]+right
    #二叉树的前序遍历，迭代版本
    def preorderTraversal2(self,root:TreeNode)->List[int]:
        st=[]
        if not root:
            return []
        stack=[root]
        result=[]
        while stack:
            node=stack.pop()
            #中结点先处理
            result.append(node.val)
            #右孩子先入栈
            if node.right:
                stack.append(node.right)
            #左孩子后入栈
            if node.left:
                stack.append(node.left)
        return result
    #二叉树的中序遍历，迭代版本
    def inorderTraversal2(self,root:TreeNode)->List[int]:
        #处理特殊情况，如果为空
        if not root:
            return []
        stack=[]
        result=[]
        cur=root
        while cur or stack:
            #先迭代访问最底层的左子树结点
            if cur:
                stack.append(cur)
                #把子节点先存起来
                cur=cur.left
            else:
                cur=cur.pop()
                result.append(cur.val)
                cur=cur.right
        return result
    #二叉树的后序遍历
    #实际上就是前序翻转而已,前序是 中左右
    #后续是   左右中，那么我们只需要先处理左右调换位置，然后再逆序result即可
    def postorderTraversal2(self,root:TreeNode)->List[int]:
        if not root:
            return []
        st=[root]
        result=[]
        while st:
            #先处理中间数据
            node=st.pop()
            result.append(node.val)
            #左孩子先入栈
            if node.left:
                st.append(node.left)
            if node.right:
                st.append(node.right)
        return result[::-1]
    #前中后统一迭代版本,如需更换顺序，只用替换位置就可以了
    def Traversal(self,root:TreeNode)->List[int]:
        result=[]
        st=[]
        if root:
            st.append(root)
        while st:
            node=st.pop()
            if node != None:
                if node.right:#右
                    st.append(node.right)
                if node.left: #左
                    st.append(node.left)
                st.append(node)#中
                st.append(None)
            else:
                node=st.pop()
                result.append(node.val)
        return result
    #利用辅助数据结构队列实现
    def levelOrder(self,root)->List[List[int]]:
        if not root:
            return []
        queue=collections.deque([root])
        result=[]
        while queue:
            level=[]
            for _ in range(len(queue)):
                cur=queue.popleft()
                level.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
            result.append(level)
        return result
    #用递归实现
    def levelOrder2(self,root)->List[List[int]]:
        levels=[]
        self.helper(root,0,levels)
        return levels
    def levelOrder2helper(self,node,level,levels):
        if not node:
            return
        if len(levels)==level:
            levels.append([])
            levels[level].append(node.val)
        self.helper(node.left,level+1,levels)
        self.helper(node.right,level+1,levels)







        

    



    