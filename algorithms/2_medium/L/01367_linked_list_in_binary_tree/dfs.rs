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
    fn dfs_check(ll_opt: Option<&Box<ListNode>>, node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> bool {
        if ll_opt.is_none() {
            return true;
        }

        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            let ll = ll_opt.unwrap();
            if node.val != ll.val {
                return false;
            }

            return Self::dfs_check(ll.next.as_ref(), node.left.as_ref()) ||
                   Self::dfs_check(ll.next.as_ref(), node.right.as_ref())
        }

        false
    }

    fn dfs_tree(ll_opt: Option<&Box<ListNode>>, node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> bool {
        if Self::dfs_check(ll_opt, node_rc_opt) {
            return true;
        }

        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            return Self::dfs_tree(ll_opt, node.left.as_ref()) ||
                   Self::dfs_tree(ll_opt, node.right.as_ref())
        }

        false
    }

    pub fn is_sub_path(ll_opt: Option<Box<ListNode>>, root_rc_opt: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::dfs_tree(ll_opt.as_ref(), root_rc_opt.as_ref())
    }
}
