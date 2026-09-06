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
use std::collections::HashMap;
impl Solution {
    fn dfs(postorder: &[i32], postorder_idx: isize, hashmap: &HashMap<i32, isize>, lo: isize, hi: isize) -> Option<Rc<RefCell<TreeNode>>> {
        if lo > hi {
            return None;
        }

        let node = Rc::new(RefCell::new(TreeNode::new(postorder[postorder_idx as usize])));
        let i = *hashmap.get(&postorder[postorder_idx as usize]).unwrap();

        node.borrow_mut().right = Self::dfs(postorder, postorder_idx - 1, hashmap, i + 1, hi);
        node.borrow_mut().left = Self::dfs(postorder, postorder_idx - (hi - i) - 1, hashmap, lo, i - 1);
        Some(node)
    }

    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let len = postorder.len();
        let mut hashmap: HashMap<i32, isize> = HashMap::with_capacity(len * 2);
        for (i, v) in inorder.into_iter().enumerate() {
            hashmap.insert(v, i as isize);
        }
        if hashmap.len() != len {
            unreachable!("input values are not unique");
        }
        Self::dfs(&postorder, len as isize - 1, &hashmap, 0, len as isize - 1)
    }
}
