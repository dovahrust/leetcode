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
    pub fn is_complete_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return true;
        }

        let mut q = VecDeque::new();
        q.push_back(root.unwrap());
        let mut seen_last_child = false;

        while let Some(node_rc) = q.pop_front() {
            let node = node_rc.borrow();

            if let Some(left) = node.left.as_ref() {
                if seen_last_child {
                    return false;
                }
                q.push_back(left.clone());
            } else {
                seen_last_child = true;
            }

            if let Some(right) = node.right.as_ref() {
                if seen_last_child {
                    return false;
                }
                q.push_back(right.clone());
            } else {
                seen_last_child = true;
            }
        }

        true
    }
}
