impl Solution {
    pub fn remove_stones(stones: Vec<Vec<i32>>) -> i32 {
        let stones_len = stones.len();
        let mut stack: Vec<(i32, i32)> = Vec::with_capacity(stones.len());
        let mut res = 0_i32;
        let mut seen = vec![false; stones_len];

        for i in 0..stones_len {
            if !seen[i] {
                seen[i] = true;
                let mut cnt = 1_i32;
                stack.push((stones[i][0], stones[i][1]));

                while let Some((x, y)) = stack.pop() {
                    for j in 0..stones_len {
                        if !seen[j] && (stones[j][0] == x || stones[j][1] == y)  {
                            seen[j] = true;
                            stack.push((stones[j][0], stones[j][1]));
                            cnt += 1;
                        }
                    }
                }

                res += cnt - 1;
            }
        }

        res
    }
}
