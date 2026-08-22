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
use std::cell::UnsafeCell;

const MAX_ALLOWED_NUM: i32 = 10_000;
const TABLE_LEN: usize = (MAX_ALLOWED_NUM + 1) as usize;

thread_local! { 
    static TABLE: UnsafeCell<[u8; TABLE_LEN]> = UnsafeCell::new([0; TABLE_LEN]);
    static STAMP: UnsafeCell<u8> = UnsafeCell::new(0);
}

impl Solution {
    pub fn num_components(head: Option<Box<ListNode>>, nums: Vec<i32>) -> i32 {
        let table = unsafe { &mut *(TABLE.with(|t| t.get())) };
        let stamp_ref = unsafe { &mut *(STAMP.with(|s| s.get())) };

        if *stamp_ref == u8::MAX {
            table.fill(0);
            *stamp_ref = 1;
        } else {
            *stamp_ref += 1;
        }

        let stamp = *stamp_ref;
        for &num in &nums {
            table[num as usize] = stamp;
        }
        let mut is_prev_valid = false;
        let mut cnt = 0_i32;
        let mut curr_opt = head;

        while let Some(mut curr) = curr_opt {
            curr_opt = curr.next.take();
            if table[curr.val as usize] == stamp {
                cnt += if is_prev_valid { 0 } else { 1 };
                is_prev_valid = true;
            } else {
                is_prev_valid = false;
            }
        }

        cnt
    }
}
