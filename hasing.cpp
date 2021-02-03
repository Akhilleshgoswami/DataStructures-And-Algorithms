//Hasing
1)2 sum problem
     std::vector<int> v;
  unordered_map<int,int>mpp;
  for(int i =0;i<arr.size();i++){
    if(mpp.find(target-arr[i])!=mpp.end())
    {
      v.push_back(mpp[target-arr[i]]);
      v.push_back(i);
      return v;
    }
    mpp[arr[i]] = i;
  }
  return v;

2)
4 sum problem
    int n= nums.size();
    
    if(n < 4) return {};
    
    vector<vector<int>> res;
    //sort the vector 
    sort(nums.begin(),nums.end());
    
    for(int i =0 ;i<n;i++){
        for(int j=i+1;j<n;j++){
            //take 2 start pointer i, j
            int target_2 = target - nums[i] - nums[j];
            
            //take iterative pointers here for i j -> left & right (total 4 pointer )  
            int left = j+1;
            int right = n-1;
               //left and right work as two sum here                 
            while(left < right){
                
            int twosum = nums[left] + nums[right];
           //bsic pointer logic when its sorted
                if(twosum < target_2){
                    left++;
                }
                else if(twosum > target_2){
                    right--;
                }
                else{
                    //add ans here 
                    vector<int> smallans(4,0);
                    smallans[0] = nums[i]; 
                    smallans[1]=  nums[j];
                    smallans[2]=  nums[left];
                    smallans[3] = nums[right];
                    
                    res.push_back(smallans);
                    
                    //if same than skip
                    while(left < right &&  smallans[2] == nums[left]){
                        left++;
                    }
                    //if same than skip
                    while(left < right &&  smallans[3] == nums[right]){
                        right--;
                    }
                    
                }
            }
            //if same than skip
            while(j+1 < n && nums[j] == nums[j+1] ){
                j++;
            }
        }
        //if same than skip
        while(i+1 < n && nums[i] == nums[i+1]){
            i++;
        }
    }
    return res;

3) Longest consecutive subsequence
    int ans =0;int count =0;
    sort(arr,arr+N);
  vector<int>s;
 s.push_back(arr[0]);
 for(int  i =1;i<N;i++){
     if(arr[i]!=arr[i-1])
        s.push_back(arr[i]);
 }
for(int  i =0;i<s.size();i++){
     
     if (i > 0 && s[i] == s[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;
 
        // update the maximum
        ans = max(ans, count);
    }
    return ans;

3.2)
time O(3N)
  set<int>s;
  for(int i = 0;i<N;i++){
      s.insert(arr[i]);
  }
  int longst  = 0;
  int count = 0;
  for(int i =0;i<N;i++){
      if(!s.count(arr[i]-1)){
          int num =  arr[i];
          count = 1;
          while(s.count(num+1)){
              num++;
              count++;
          }
         longst   = max(count,longst); 
      }
  }
  return longst;

4) sum as 0 
for(int  i =0;i<n;i++){
  for(int j =0;j<n;j++){
//  	cout<<"Null"<<endl;
    for(int k = i;k<j;k++){
      sum+=arr[k];
      if(sum==0){
      	maxi =max(k,maxi);
	  }
    }
    sum = 0;
  }
//  cout<<endl;
}
cout<<maxi<<endl;
}

4.2)
best solutiont = O(n)
space = O(n)
unordered_map<int,int>mpp;
int maxi = 0;
int sum = 0;
for(int i =0;i<n;i++){
  sum+=arr[i];
  if(sum==0){
    maxi = i+1;
  }
  else{
    if(mpp.find(sum)!=mpp.end()){
      maxi = max(maxi,i-mpp[sum]);

    }else{
      mpp[sum] = i;
    }
  }
}


5)

find the Xor of given m
T (nlogn)
int cnt = 0;
map<int,int>freq;
int xor =  0;
for(auto it :A){
  xorr = xorr^it;
  if(xorr==B){
    cnt++;
  }
if(freq.find(xorr^B)!=freq.end()){
  cnt+=freq[xorr^B];
  
}
freq[xorr]+=1;
}



6) Find the longetst non repating sub string
T = 2N
s N
int  r = 0; int  l = 0;
int count = 0;
set<char>ss;
while(r!=arr.size()-1){

  while(ss.count(arr[r])){

ss.erase(arr[l]);l++;
  }

count = max(count,r-l+1);
ss.insert(arr[r]);
r++;
}
cout<<count<<endl;


7) LONGEST NON REPATIN SUBSEQUENCE STRING
std::vector<int>mpp(256 ,-1);
int l =  0 ;int  r = 0;
int n = s.size();
int len = 0;
while(r<n){
  if(mpp[s[r]]!=-1) l =  max(mpp[s[r]]+1,l);
  mpp[s[r]] =r;
  len=max(len ,r-l+1);
  r++;
}
return len;
