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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a comparator for the priority queue
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        // Min-heap (priority queue) to keep the nodes sorted
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        // Push the head of each list into the priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        
        // Create a dummy head for the result list
        ListNode dummy;
        ListNode* tail = &dummy;
        
        // Process the nodes in the priority queue
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }
        
        // Return the head of the merged list
        return dummy.next;
    }
};