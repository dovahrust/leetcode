impl Solution {
    pub fn split_num(mut num: i32) -> i32 {
        let mut freqs = [0_i32; 10];

        while num > 0 {
            freqs[(num % 10) as usize] += 1;
            num /= 10;
        }

        let (mut n1, mut n2): (i32, i32) = (0, 0);

        for i in 1..10 {
            while freqs[i] > 0 {
                if n1 < n2 {
                    n1 = (n1 * 10) + i as i32;
                } else {
                    n2 = (n2 * 10) + i as i32;
                }

                freqs[i] -= 1;
            }
        }

        n1 + n2
    }
}
