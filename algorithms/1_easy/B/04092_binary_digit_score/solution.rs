impl Solution {
    pub fn calculate_score(a: i32, b: i32) -> i32 {
        let s1 = a.count_ones() as i32;
        let s2 = b.count_ones() as i32;

        if s1 >= s2 { s1 * s2 } else { s2 / s1 } 
    }
}
