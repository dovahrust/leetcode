impl Solution {
    pub fn merge_triplets(triplets: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let (mut seen_0, mut seen_1, mut seen_2) = (false, false, false);

        for t in triplets {
            if t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2] {
                seen_0 |= (t[0] == target[0]);
                seen_1 |= (t[1] == target[1]);
                seen_2 |= (t[2] == target[2]);
            }

            if seen_0 && seen_1 && seen_2 {
                return true;
            }
        }

        false
    }
}
