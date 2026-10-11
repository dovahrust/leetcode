def calc_valid_pairs_cnt(s):
    pair_cnt = 0
    open_cnt = 0

    for b in s:
        match b:
            case '(':
                open_cnt += 1
            case ')':
                if open_cnt > 0:
                    open_cnt -= 1
                    pair_cnt += 1

    return pair_cnt

def dfs(s, idx, valid_pairs, open_use, close_use, stack, res):
    if open_use > valid_pairs: return

    if idx == len(s):
        if open_use == valid_pairs and close_use == valid_pairs:
            res.add("".join(stack))

        return

    match s[idx]:
        case '(':
            stack.append('(')
            dfs(s, idx + 1, valid_pairs, open_use + 1, close_use, stack, res)
            stack.pop()

            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res)
        case ')':
            if close_use < open_use:
                stack.append(')')
                dfs(s, idx + 1, valid_pairs, open_use, close_use + 1, stack, res)
                stack.pop()
            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res)
        case _:
            stack.append(s[idx])
            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res)
            stack.pop()

class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        valid_pairs = calc_valid_pairs_cnt(s)
        res = set()
        stack = []

        dfs(s, 0, valid_pairs, 0, 0, stack, res)

        return list(res)
