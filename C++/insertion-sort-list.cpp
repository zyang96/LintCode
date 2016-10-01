// Time:  O(n^2)
// Space: O(1)

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

//my solution with stack implementation space O(N)
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        stack<ListNode *> stk;
        ListNode * curr = head->next;
        while (curr != NULL) {
            stk.push(head);
            int tempVal = curr->val;
            while (stk.top()->next != curr) {
                stk.push(stk.top()->next);
            }
            while (!stk.empty()) {
                if (stk.top()->val > tempVal) {
                    stk.top()->next->val = stk.top()->val;
                    stk.pop();
                } else {
                    stk.top()->next->val = tempVal;
                    break;
                }
            }
            if (!stk.empty()) {
                while (!stk.empty()) {
                    stk.pop();
                }
            } else {
                head->val = tempVal;
            }
            curr = curr->next;
        }
        return head;
    }
};



class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy{numeric_limits<int>::min()};

        auto curr = head;
        ListNode *position = nullptr;

        while (curr) {
            position = findInsertPosition(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = position->next;
            position->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (auto curr = head; curr && curr->val <= x;
             prev = curr, curr = curr->next);
        return prev;
    }
};
