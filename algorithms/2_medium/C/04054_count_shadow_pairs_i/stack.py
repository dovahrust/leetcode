class Solution:
    def shadowPairs(self, nums: list[int]) -> int:
        stack = []
        cnt = 0

        for num in nums:
            while stack and stack[-1][0] > num:
                stack.pop()

            if stack:
                (top, prev_num_cnt) = stack[-1]
                if top == num:
                    cnt += prev_num_cnt
                    stack.append((num, prev_num_cnt))
                else:
                    cnt += len(stack)
                    stack.append((num, len(stack)))
            else:
                stack.append((num, 0))

        return cnt
