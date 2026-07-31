impl Solution {
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let turned_on_u32 = turned_on as u32;
        let mut res: Vec<String> = Vec::new();

        for h in 0..=11_i32 {
            for m in 0..=59_i32 {
                if h.count_ones() + m.count_ones() == turned_on_u32 {
                    if m < 10 {
                        res.push(format!("{h}:0{m}"));
                    } else {
                        res.push(format!("{h}:{m}"));
                    }
                }
            }
        }

        res
    }
}
