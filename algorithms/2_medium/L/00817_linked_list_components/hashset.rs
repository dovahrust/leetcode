// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::HashSet;

impl Solution {
    pub fn num_components(head: Option<Box<ListNode>>, nums: Vec<i32>) -> i32 {
        let mut is_prev_valid = false;
        let mut cnt = 0_i32;
        let mut curr_opt = head;
        let set: HashSet<i32> = nums.into_iter().collect();

        while let Some(mut curr) = curr_opt {
            curr_opt = curr.next.take();
            if set.contains(&curr.val) {
                cnt += if is_prev_valid { 0 } else { 1 };
                is_prev_valid = true;
            } else {
                is_prev_valid = false;
            }
        }

        cnt
    }
}
