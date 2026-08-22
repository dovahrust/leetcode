/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static int numComponents(ListNode* head, const vector<int>& nums) {
        bool is_prev_valid = false;
        int cnt = 0;
        ListNode* curr = head;
        auto set = unordered_set<int>(nums.cbegin(), nums.cend());

        while (curr != nullptr) {
            const int val = curr->val;
            curr = curr->next;

            if (set.contains(val)) {
                cnt += is_prev_valid ? 0 : 1;
                is_prev_valid = true;
            } else {
                is_prev_valid = false;
            }
        }

        return cnt;
    }
};
