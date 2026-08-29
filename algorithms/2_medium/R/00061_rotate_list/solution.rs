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
impl Solution {
    #[inline(always)]
    fn calc_len(mut curr_opt: Option<&Box<ListNode>>) -> i32 {
        let mut len: i32 = 0;
        while let Some(curr) = curr_opt {
            len += 1;
            curr_opt = curr.next.as_ref();
        }
        len
    }

    #[inline(always)]
    fn split_into_two_list(
        mut head_opt: Option<Box<ListNode>>,
        shift_cnt: i32
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        let mut curr = head_opt.as_mut().unwrap();

        for _ in 0..(shift_cnt - 1) {
            curr = curr.next.as_mut().unwrap();
        }

        let h2 = curr.next.take();

        (head_opt, h2)
    }

    pub fn rotate_right(head_opt: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let len = Self::calc_len(head_opt.as_ref());
        if len <= 1 { return head_opt; }
        let shift_cnt = (len - (k % len)) % len;
        if shift_cnt == 0 { return head_opt; }

        let (h1, mut h2) = Self::split_into_two_list(head_opt, shift_cnt);
        
        let mut curr = h2.as_mut().unwrap();

        while curr.next.is_some() {
            curr = curr.next.as_mut().unwrap();
        }

        curr.next = h1;

        h2
    }
}
