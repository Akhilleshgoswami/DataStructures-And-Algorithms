vector<int> topView(struct Node *root)
{
    vector<int>ans;
     map<int,int> m;
    queue<pair<struct Node*,int> > que;
    que.push(make_pair(root,0));
    
    while(!que.empty())
    {
        pair<struct Node*,int> cur=que.front();
        que.pop();
        if(m.find(cur.second)==m.end())
        {
         
            m[cur.second]=cur.first->data;
        }
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








void topview(Node*root){
    if(!root)return;
    queue<pair<Node*,int>>q;
    map<int,int>map;
    q.push({root,0});
    while(!q.empty()){
        pair<Node*,int>cur = q.front();
        q.pop();
        if(map.find(cur->second)==map.end()){
            map[cur->first] = cur->second->data;
        }
         if(cur.first->left)
        que.push(make_pair(cur.first->left,cur.second-1));
        if(cur.first->right)
        que.push(make_pair(cur.first->right,cur.second+1));
    }
    for(auto i : map)cout<<i.second<<" ";
}