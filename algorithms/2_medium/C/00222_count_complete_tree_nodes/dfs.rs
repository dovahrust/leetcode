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
impl Solution {
    fn dfs_h_right(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            return 1 + Self::dfs_h_right(curr_node.right.as_ref());
        }

        0
    }

    fn dfs_h_left(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            return 1 + Self::dfs_h_left(curr_node.left.as_ref());
        }

        0
    }

    fn dfs(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> i32 {
        let h_left = Self::dfs_h_left(curr_node_rc_opt);
        let h_right = Self::dfs_h_right(curr_node_rc_opt);

        if h_right == h_left {
            return (1_i32 << h_left) - 1;
        } else {
            let curr_node_rc = curr_node_rc_opt.unwrap();
            let curr_node = curr_node_rc.borrow();
            return 1 + Self::dfs(curr_node.left.as_ref()) +  Self::dfs(curr_node.right.as_ref());
        }
    }

    pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(root.as_ref())
    }
}
