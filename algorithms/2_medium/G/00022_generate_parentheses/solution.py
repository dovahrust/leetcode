class Solution:
    def dfs(self, n, open_cnt, close_cnt):
        if open_cnt == n and close_cnt == n:
            self.res.append("".join(self.tmp_list))
            return

        if open_cnt < n:
            self.tmp_list.append('(')
            self.dfs(n, open_cnt + 1, close_cnt)
            self.tmp_list.pop()

        if close_cnt < open_cnt:
            self.tmp_list.append(')')
            self.dfs(n, open_cnt, close_cnt + 1)
            self.tmp_list.pop()
    
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.tmp_list = []

        self.dfs(n, 0, 0)

        return self.res
        
