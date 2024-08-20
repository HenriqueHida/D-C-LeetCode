#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

ListNode* vectorToListNode(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

vector<int> listNodeToVector(ListNode* node) {
    vector<int> result;
    while (node) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

int main() {
    // Example input
    vector<ListNode*> lists = {
        vectorToListNode({1, 4, 5}),
        vectorToListNode({1, 3, 4}),
        vectorToListNode({2, 6})
    };

    // Start time measurement
    auto start_time = high_resolution_clock::now();

    // Call the solution
    Solution solution;
    ListNode* result_node = solution.mergeKLists(lists);

    // End time measurement
    auto end_time = high_resolution_clock::now();
    auto elapsed_time = duration_cast<duration<double>>(end_time - start_time).count();

    // Convert the result back to vector form
    vector<int> result = listNodeToVector(result_node);

    // Output the result and elapsed time
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Time: " << elapsed_time << " sec" << endl;

    return 0;
}
