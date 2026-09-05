class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1: return False

        total_sum = 1
        sq = int(sqrt(num))

        for i in range(2, sq + 1):
            if num % i == 0:
                total_sum += i

                other = num // i
                if i != other:
                    total_sum += other

                if total_sum > num:
                    return False

        return total_sum == num
