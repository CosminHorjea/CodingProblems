#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *prev = NULL;
        ListNode *aux = head;
        while(aux){
            cout<<"aux: "<<aux->val<<endl;
            if(!aux->next){
                break;
            }
            if(prev){
                prev->next = aux->next;
            }else{
                head = aux->next;
            }
            ListNode* first = aux->next;
            ListNode* second = aux->next->next;
            aux->next = second;
            first->next = aux;
            prev = aux;
            aux=aux->next;
        }
        return head;

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size();
        int C = mat[0].size();
        if(R==0 || C==0)
            return mat;
        vector<vector<int>> dist(R,vector<int>(C,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push(make_pair(i,j));
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int rr = r+dr[k];
                int cc = c+dc[k];
                if(rr>=0 && rr<R && cc>=0 && cc<C && dist[rr][cc]>dist[r][c]+1){
                    dist[rr][cc]=dist[r][c]+1;
                    q.push(make_pair(rr,cc));
                }
            }
        }
        return dist;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        if(R==0 || C==0)
            return 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int ans = 0;
        queue<pair<pair<int,int>,int>> q;
        //add rotten oranges to a queue
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==2){
                    q.push({make_pair(i,j),0});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int minute = q.front().second;
            ans = max(ans,minute);
            q.pop();
            for(int k=0;k<4;k++){
                int rr = r+dr[k];
                int cc = c+dc[k];
                if(rr>=0 && rr<R && cc>=0 && cc<C && grid[rr][cc]==1){
                    grid[rr][cc]=2;
                    q.push({make_pair(rr,cc),minute+1});
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return ans;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode *head = NULL;
        ListNode *prev = NULL;
        while(list1 && list2){
            if(list1->val<=list2->val){
                if(!head){
                    head = list1;
                }
                if(prev){
                    prev->next = list1;
                }
                prev = list1;
                list1 = list1->next;
            }else{
                if(!head){
                    head = list2;
                }
                if(prev){
                    prev->next = list2;
                }
                prev = list2;
                list2 = list2->next;
            }
        }
        if(list1){
            prev->next = list1;
        }
        if(list2){
            prev->next = list2;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *next = curr->next; // get the addres of the next node
            curr->next = prev;// reference to the prev node
            prev = curr;//update the prev with the current one
            curr = next;// we go to the (momentan) unlinked node, which is the next one
                        // we are in a state like this  1<-2 3->4->5->6
        }               //                                 ^ ^
                        //                              prev curr
        return prev;    
    }
};
int main(){
    Solution p;
    ListNode *head = new ListNode(1);
    ListNode *aux = head;
    for(int i=2;i<=4;i++){
        aux->next = new ListNode(i);
        aux = aux->next;
    }
    head = p.swapPairs(head);
    while(head){
        cout<<head->val;
        head=head->next;
    }

}