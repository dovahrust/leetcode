use std::collections::BinaryHeap;

impl Solution {
    pub fn furthest_building(heights: Vec<i32>, mut bricks: i32, mut ladders: i32) -> i32 {
        if heights.is_empty() { return -1; }

        let len = heights.len();
        let mut heap: BinaryHeap<i32> = BinaryHeap::new();

        for idx in 0..(len - 1) {
            if heights[idx] < heights[idx + 1] {
                let need = heights[idx + 1] - heights[idx];
                bricks -= need;
                heap.push(need);
                if bricks < 0 {
                    bricks += heap.pop().unwrap();
                    ladders -= 1;
                    if ladders < 0 {
                        return idx.try_into().unwrap();
                    }
                }
            }
        }

        (len - 1).try_into().unwrap()
    }
}
