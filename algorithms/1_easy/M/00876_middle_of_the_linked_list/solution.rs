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
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut curr_opt = head.as_ref();
        let mut len = 0;
        while let Some(curr) = curr_opt {
            curr_opt = curr.next.as_ref();
            len += 1;
        }

        let mut curr_opt = head;
        for i in 0..(len / 2) {
            curr_opt = curr_opt.unwrap().next.take();
        }

        curr_opt
    }
}
