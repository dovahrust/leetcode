impl Solution {
    pub fn check_perfect_number(num: i32) -> bool {
        if num <= 1 { return false; }

        let mut sum = 1;
        let sq = num.isqrt();

        for i in 2..=sq {
            if num % i == 0 {
                sum += i;

                let other = num / i;
                if i != other { 
                    sum += other;
                }

                if sum > num {
                    return false;
                }
            }
        }

        sum == num
    }
}
