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
    #[inline(always)]
    fn get_the_most_left_child(mut node_rc: Rc<RefCell<TreeNode>>) -> Rc<RefCell<TreeNode>> {
        while let node = node_rc.borrow() && node.left.is_some() {
            let next = node.left.clone().unwrap();
            drop(node);
            node_rc = next;
        }
        node_rc
    }

    fn dfs(node_rc_opt: Option<Rc<RefCell<TreeNode>>>, key: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node_rc) = node_rc_opt {
            let mut node = node_rc.borrow_mut();
            if node.val < key {
                node.right = Self::dfs(node.right.take(), key);
                drop(node);
                return Some(node_rc);
            } else if node.val > key {
                node.left = Self::dfs(node.left.take(), key);
                drop(node);
                return Some(node_rc);
            } else {
                let mut l_rc_opt = node.left.take();
                let mut r_rc_opt = node.right.take();

                if l_rc_opt.is_none() {
                    return r_rc_opt;
                } else if r_rc_opt.is_none() {
                    return l_rc_opt;
                } else {
                    let most_left_child_rc = Self::get_the_most_left_child(r_rc_opt.clone().unwrap());
                    let mut most_left_child = most_left_child_rc.borrow_mut();
                    most_left_child.left = l_rc_opt;
                    return r_rc_opt;
                }
            }
        }

        None
    }

    pub fn delete_node(root: Option<Rc<RefCell<TreeNode>>>, key: i32) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(root, key)
    }
}
