/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int larger(ListNode* node)
    {
        int num=node->val;
        while(node!=NULL)
        {
            if(node->val > num)
            {
                return node->val;
            }
            else{
                node=node->next;
            }
        }
        return 0;
    }
    vector<int> nextLargerNodes(ListNode* head)
    {
        //Using Stack
        if(head==NULL)
        {
            vector<int> values;
            return values;
        }
            stack<int> nodes;
            stack<int> max;
            int length=0;
            while(head)
            {
                nodes.push(head->val);
                head=head->next;
                length++;
            }
        vector<int> result(length);
            for(int i=length-1;i>=0;i--)
            {
                while(!max.empty() && max.top()<=nodes.top())
                {
                    max.pop();
                }
                if(max.empty())
                {
                    result[i]=0;
                }
                else
                {
                    result[i]=max.top();
                }
                max.push(nodes.top());
                nodes.pop();
            }
            return result;
    //Brute Force Solution
        vector<int> answer;
        while(head!=NULL)
        {
            answer.push_back(larger(head));
            head=head->next;
        }
        return answer;
    }
};
