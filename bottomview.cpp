vector <int> bottomView(Node *root)
{

    vector<int>ans;
     map<int,int> m;
    queue<pair<struct Node*,int> > que;
    que.push(make_pair(root,0));
    
    while(!que.empty())
    {
        pair<struct Node*,int> cur=que.front();
        que.pop();
    
         
            m[cur.second]=cur.first->data;
        
        if(cur.first->left)
        que.push(make_pair(cur.first->left,cur.second-1));
        if(cur.first->right)
        que.push(make_pair(cur.first->right,cur.second+1));
        
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
