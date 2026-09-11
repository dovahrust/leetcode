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
    const ID_NONE: usize = usize::MAX;

    fn dfs(
        node_rc_opt: Option<&Rc<RefCell<TreeNode>>>,
        hashmap: &mut HashMap<(usize, usize, i32), (usize, usize)>,
        next_id: &mut usize,
        res: &mut Vec<Option<Rc<RefCell<TreeNode>>>>,
    ) -> usize {
        let Some(node_rc) = node_rc_opt else { return Self::ID_NONE; };
        let node = node_rc.borrow();
        let l_id = Self::dfs(node.left.as_ref(), hashmap, next_id, res);
        let r_id = Self::dfs(node.right.as_ref(), hashmap, next_id, res);
        let val = node.val;
        drop(node);

        if let Some((freq, node_id)) = hashmap.get_mut(&(l_id, r_id, val)) {
            *freq += 1;
            if *freq == 2 {
                res.push(Some(node_rc.clone()))
            }
            *node_id
        } else {
            let node_id = *next_id;
            *next_id += 1;
            hashmap.insert((l_id, r_id, val), (1, node_id));
            node_id
        }
    }

    pub fn find_duplicate_subtrees(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut hashmap: HashMap<(usize, usize, i32), (usize, usize)> = HashMap::new();
        let mut res: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
        let mut next_id: usize = 0;

        Self::dfs(root.as_ref(), &mut hashmap, &mut next_id, &mut res);

        res
    }
}
