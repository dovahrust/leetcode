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
struct Solution {
    head: Option<Box<ListNode>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(head: Option<Box<ListNode>>) -> Self {
        assert!(head.is_some());
        Self {
            head: head,
        }
    }

    fn get_random(&mut self) -> i32 {
        let mut curr_opt = self.head.as_ref();
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let mut i: i64 = 1;
        let mut res: i32 = 0;

        while let Some(curr) = curr_opt {
            curr_opt = curr.next.as_ref();
            if rng.gen_range(1..=i) == 1 {
                res = curr.val;
            }
            i += 1;
        }

        res
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(head);
 * let ret_1: i32 = obj.get_random();
 */
