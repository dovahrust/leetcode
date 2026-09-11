// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
impl Solution {
    pub fn width_of_binary_tree(root_rc_opt: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let Some(root_rc) = root_rc_opt else { return 0; };
        let mut q = VecDeque::new();
        q.push_back((0_usize, root_rc));
        let mut res = 0_usize;
        while !q.is_empty() {
            let q_len = q.len();
            res = res.max(q[q_len - 1].0 - q[0].0 + 1);
            for _ in 0..q_len {
                let (pos, node_rc) = q.pop_front().unwrap();
                let node = node_rc.borrow();
                if let Some(l) = node.left.as_ref() {
                    q.push_back((pos * 2, l.clone()));
                }
                if let Some(r) = node.right.as_ref() {
                    q.push_back(((pos * 2) + 1, r.clone()));
                }
            }
        }

        res.try_into().unwrap()
    }
}
