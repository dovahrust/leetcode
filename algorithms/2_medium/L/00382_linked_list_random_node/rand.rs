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
    arr: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(head: Option<Box<ListNode>>) -> Self {
        assert!(head.is_some());
        let mut arr: Vec<i32> = Vec::default();
        let mut curr_opt = head.as_ref();
        while let Some(curr) = curr_opt {
            curr_opt = curr.next.as_ref();
            arr.push(curr.val);
        }

        Self {
            arr: arr,
        }
    }

    fn get_random(&mut self) -> i32 {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        self.arr[rng.gen_range(0..self.arr.len())]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(head);
 * let ret_1: i32 = obj.get_random();
 */
