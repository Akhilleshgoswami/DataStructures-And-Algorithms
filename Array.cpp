 1) Find the duplicate in an array of N+1 integers. 
/*Frist solution we can also use bruteforces which take O(n2)Time
	Time complexcity O(nlong) for sorting  if we use marge sort
	 and  o(n) for find the elements
	space comp. is o(1)
*/
1.1) sort(v.begin(),v.end());

for(int i =0;i<v.size();i++){
 if(v[i]==v[i+1]){
   cout<<v[i]<<endl;
 }
}


/*Second Solution
T = O(n);
S = O(n);
*/
1.2) Using Hasing
 T = O(n)
space O(N)
unordered_map<int,int>umap;
for(int i =0;i<n;i++){
umap[v[i]]++;
}
  for (auto x : umap) 
      if(x.second>1){
       cout<<x.fir st<<endl;
      }


1.3) Best Solution

T = O(N)
S  =O(n)
std::vector<int> result;
for(int x:v){

 x = abs(x);
 if(v[x-1] > 0) v[x-1]*=-1;
 else cout<<x<<" ";
}

2)

2 (Sort an array of 0’s 1’s 2’s without using extra space or sorting algo )

2.1)simpel solution fro this to just sort the array 

2.2)
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0; 
  
    // Count the number of 0s, 1s and 2s in the array 
    for (i = 0; i < n; i++) { 
        switch (arr[i]) { 
        case 0: 
            cnt0++; 
            break; 
        case 1: 
            cnt1++; 
            break; 
        case 2: 
            cnt2++; 
            break; 
        } 
    } 
  
    // Update the array 
    i = 0; 
  
    // Store all the 0s in the beginning 
    while (cnt0 > 0) { 
        arr[i++] = 0; 
        cnt0--; 
    } 
  
    // Then all the 1s 
    while (cnt1 > 0) { 
        arr[i++] = 1; 
        cnt1--; 
    } 
  
    // Finally all the 2s 
    while (cnt2 > 0) { 
        arr[i++] = 2; 
        cnt2--; 
    } 
  

2.2)
T = O(N);
	S = O(1)
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
    // are sorted 
    while (mid <= hi) { 
        switch (a[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(a[lo++], a[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(a[mid], a[hi--]); 
            break; 
        } 

3) Repeat and Missing Number 

3.1)

 int j =1;
int missing = 0;
int reapeating = 0;
	sort(arr.begin(),arr.end());
for(int i =0;i<n;i++){
 if(arr[i]==j)
 	j++;

 else if(arr[i]!=j and j!=arr[i+1] and j!=arr[i-1]){
 	 missing = j;
     j++;
 }
else{
	j++;
}

if(arr[i]==arr[i+1]){
reapeating = arr[i];
}}
cout<<"reapeating number is"<<reapeating<<" ,  "<<"missing number is "<<missing<<endl; */
 
3.2) second solution using hasing

int arr1[n];
for(int i =0;i<n;i++){
 arr1[i] = 0;
}
for(int i1 =0;i1<n;i1++){
 arr1[arr[i]]++;
}

for(int i1 =0;i1<n;i1++){
 cout<<arr1[i1]<<" ";
}
}
 


/*int i;
3.3) best seolution
    cout << " The repeating element is ";
 

    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] *=-1;
        else
            cout << abs(arr[i]) << "\n";
    }
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }*/


    /* Will hold xor of all elements 
 3.4)   and numbers from 1 to n */
    int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers 
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
     Now divide elements into two 
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same 
    position in each element. Also, 
    get XORs of two sets. The two
    XORs are the output elements. 
    The following two for loops 
    serve the purpose 
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
 
    /* *x and *y hold the desired
        output elements */


4)
//marge two sorted array
t =O(n) s=(1)


second solution
4.1)T = O(n) s =(n)
 map<int, bool> mp; 
      
    // Inserting values to a map. 
    for(int i = 0; i < n; i++) 
    mp[v[i]] = true; 
      
    for(int i = 0;i < m;i++) 
    mp[love[i]] = true; 
      
    // Printing keys of the map. 
    for(auto i: mp) 
    cout<< i.first <<" "; 

4.2)// this is the seocnd solution where we take
// T = (n*m)
// s = (1)
for (int i=n-1; i>=0; i--) 
    { 
        /* Find the smallest element greater than ar2[i]. Move all 
           elements one position ahead till the smallest greater 
           element is not found */
        int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 
  
        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 


4.3 )T O(nlogn);
s = O(1)
// for(int i =0;i<n;i++){

// 	if(v[i]>love[j]){
// 	swap(v[i],love[j]);
// 	}
// sort(love.begin(),love.end());
// }

// for(int &i:v)cout<<i<<" ";
// for(int &i:love)cout<<i<<" ";




/*
4.4)
simple aproch for solving this problem is
T = O(nlong for sorting , O(N) + O(N), S = O(N+M))

std::vector<int> v11;
	for(int &x:v)
v11.push_back(x);

for(int &x:v1)
v11.push_back(x);

sort(v11.begin(),v11.end());
for(int i =0;i<n;i++){
	v[i]=v11[i];
}
for(int i =0;i<m;i++){
	v1[i] = v11[n++];
}
for(int &i:v)cout<<i<<" ";
for(int &i:v1)cout<<i<<" ";*/




5)fint the maximum sum sub array 
Kadane’s Algorithm 

//maximumsubarray sum 
// int sum =0;
// int maxi = INT_MIN;
// for(auto it: love){
// 	sum+=it;
// 	maxi = max(max,sum);
// 	if(sum<0)sum=0;
// }
// cout<<max<<endl;





6)Merge Overlapping Subintervals

6.1)this is the best solutin and time =O(nlogn)

  stack<pair<int,int>>s;
    s.push({a[0].first, a[0].second});
    for(int i =1;i<n;i++){
     int start1 =  s.top().first;
     int end1 = s.top().second;
     int start2 = a[i].first;
     int end2 = a[i].second;
     if(end1<start2)
         s.push({start2,end2});
else{
     s.pop();
     end1 = max(end1,end2);
     s.push({start1,end1});
    }}
    while(!s.empty()){
     cout<<s.top().first<<" "<<s.top().second<<endl;
     s.pop();
    }
    / }
    

6.2)
    std::vector<std::vector<int>> v1;
int start = v[0][0];int end = v[0][1];
 for(auto& i:v){
 	if(i[0]>end){
		v1.push_back({start,end});
 		start =i[0];
		end=i[1];
	}
 	else end= max(end,i[1]);
 }
  v1.push_back({start,end});
 for(auto&i:v1)cout<<i[0]<<" "<<i[1]<<endl;
 }





7) Set Matrix Zeros 

int arr[n][m];
   for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
         cin>>arr[i][j];
     }
    }int col0 =1;
    for(int i =0;i<m;i++){
     if(arr[i][0]==0)col0= 0;
     for(int j =1;j<n;j++){
         if(arr[i][j]==0){
             arr[i][0]=arr[0][j]=0;
         }
     }
    }
    for(int i=m-1;i>=0;i--){
     for(int j = n-1;j>=0;j--)
         if(arr[i][0]==0 || arr[0][j]==0)
             arr[i][j] = 0;
         if(col0==0) arr[i][0]=0;
     
    }
            for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
     cout<<arr[i][j]<<" ";
     }cout<<endl;
        
    }
 7.2)   //this is the second solution for this problenm
    t = n*m+n*m
    s = O(n)+O(m)
int arr1[n]; int arr2[m];
for(int i =0;i<n;i++){
 arr1[i] = -1;
}
for(int i=0;i<m;i++){
 arr2[i]= -1;
}
 for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
     if(arr[i][j]==0){
         arr1[i] = arr2[j] = 0;
     }
     }
    }
 for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
     if(arr1[i]== 0 || arr2[j]== 0){
         arr[i][j]=0;
            
     }
     }
    }
       for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
     cout<<arr[i][j]<<" ";
     }cout<<endl;
        
    }

  7.4)   this is a very simple solution for  zero matrix 
    //t = O(n*m)*(n+m);
    // s= O(1)
    int arr[n][m];
 
    for(int i =0;i<n;i++){
     for(int j =0;j<m;j++)
{
 if(arr[i][j]==0){
     for(int k=0;k<n || k<m ;k++){
         if(arr[k][j]!=0 && k<m)arr[k][j]=-1;

         if(arr[i][k]!=0 && k<n)arr[i][k]=-1;
     }
 }
}    }

    for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
         if(arr[i][j]==-1){
             arr[i][j]=0;
         }
     }
        
    }
        for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
     cout<<arr[i][j]<<" ";
     }cout<<endl;
        
    }


8) pascal tringale 
T =O(N2) 
space = O(N2)
void printPascal(int n) 
{ 
      
    //An auxiliary array to store  
    //generated pscal triangle values 
    int arr[n][n];  
  
    // Iterate through every line and  
    // print integer(s) in it 
    for (int line = 0; line < n; line++) 
    { 
        // Every line has number of integers  
        // equal to line number 
        for (int i = 0; i <= line; i++) 
        { 
        // First and last values in every row are 1 
        if (line == i || i == 0) 
            arr[line][i] = 1; 
        // Other values are sum of values just  
        // above and left of above 
        else
            arr[line][i] = arr[line - 1][i - 1] +  
                            arr[line - 1][i]; 
        cout << arr[line][i] << " "; 
        } 
        cout << "\n"; 
    } 
} 
8.2)
t =O(N)
for (int line = 1; line <= n; line++) 
{ 
    int C = 1; // used to represent C(line, i) 
    for (int i = 1; i <= line; i++)  
    { 
          
        // The first value in a line is always 1 
        cout<< C<<" ";  
        C = C * (line - i) / i;  
    } 
    cout<<"\n"; 
} 
} 




9) count inverstion in the arrayt = O(nlogn)

int _mergeSort(int arr[], int temp[], 
                 int left, int right);
int merge(int arr[], int temp[], int left, 
                   int mid, int right);
int merge(int arr[], int temp[], int left,int mid, int right)
{int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}


int _mergeSort(int arr[], int temp[], 
                 int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, 
                           mid + 1, right);
    }
    return inv_count;
}
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
// Driver code




simplem solution for this problem is 
t = (N2)
for(int i =0;i<n;i++){

for(int j = i+1; j<n;j++){

if(arr[i]>arrr[j] ) count++;

}
}

10) buy or sell the stcok
T =  O(N2)
// for(int i =0;i<n;i++){
//     for(int j = i+1;j<n;j++){
//         if(arr[i]<arr[j]){
//             sum = max(sum, arr[j]-arr[i]);
//         }

//     }
// }

10.2) t = O(N)
// int mini = INT_MAX;

// for(int i =0;i<n;i++){
// mini = min(mini,arr[i]);
// sum = max(sum,arr[i]-mini);
// }
// cout<<sum<<endl;
// }

11)
roteate a metrix
t(n2)
space (n*n)
int arr[n][n];
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++)
    // cout<<"enter a number"<<endl;
      {  cin>>x;
        arr[i][j]=x;
    }
}
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++)
    {
     cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
}

11.2)
int arr1[n][n];
for(int i= 0;i<n;i++){
    for(int j =0;j<n;j++){
        arr1[j][n-1-i]=arr[i][j];
    }
}
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++)
    {
     cout<<arr1[i][j]<<" ";
    }
    cout<<"\n";
}

11.3)
for(int i =0;i<matrix.size();i++)
for(int j= 0;j<i;j++)
    swap(matrix[i][j],matrix[j][i]);

        for(int i =0;i<matrix.size();i++)
        reverse(matrix[i].begin(),matrix[i].end());
        
    }


12)
Search in 2d  Matrix
t =O(N2)
	    for(int  i =0;i<N;i++){
	        for(int j =0;j<M;j++){
	            if(X >mat[i][M-1])
	            break;
	        
	        if(X==mat[i][j])return 1;
	    }
	}
	return 0;
    

this for gfg problem
int i =0 j = 0;
while(i<n and j>=0){

if(arr[i][j] ==x)
cout<<i<<" "<<j<<endl;
return 1;
 if(arr[i][j]>x)j--;
else i++;

we can also use a tamp array of n*m and then do a bainery serach for this if its row are sorted

T= log n*m
     int lo = 0;
        int n = v.size();
        int m = v[0].size();
int hi = (n*m)-1;
        
        while(lo<=hi){
int mid = (lo+(hi-lo)/2);
            if(v[mid/m][mid%m]==target)
                return true;
            if(v[mid/m][mid%m]<target)
                lo = mid+1;
            else hi = mid-1;
        
        
        }
        return false;
   
    }



13)
power(x,n)
t = log(n)
double ans =1.0;
long long nn = n;
if(nn<0) nn= -1*nn;
while(nn){
 
    if(nn%2){
       
        ans = ans*x;
     
    }
    else{
        x= x*x;
        nn = nn/2;
    }}
    if(n<0) ans = (double)(1.0)/(double)(ans);
    return ans;
}

14)
find  > n/2 elements
unordered_map<int ,int>s;
int x1;
 int count = 0;
        int canditate = 0;
        for(int i:nums){

        if(count==0)
         canditate = i;   
        
        if(canditate == i)count+=1;
        
        else count-=1;}   return canditate;
    }

14.2)
for(int i= 0;i<n;i++)
{
	cin>>x1;
	s[x1]++;
}
for(auto i :s){
	if(i.second>n/2)cout<<i.first<<endl;
}

15) mejority m/3
 int count1 = 0, count2 = 0;
    int first=INT_MAX    , second=INT_MAX    ;
 
    for (int i = 0; i < n; i++) {
 
        // if this element is previously seen, 
        // increment count1.
        if (first == arr[i])
            count1++;
 
        // if this element is previously seen, 
        // increment count2.
        else if (second == arr[i])
            count2++;
     
        else if (count1 == 0) {
            count1++;
            first = arr[i];
        }
 
        else if (count2 == 0) {
            count2++;
            second = arr[i];
        }
 
        // if current element is different from
        // both the previously seen variables, 
        // decrement both the counts.
        else {
            count1--;
            count2--;
        }
    }
 
    count1 = 0;
    count2 = 0;
 
    // Again traverse the array and find the
    // actual counts.
    for (int i = 0; i < n; i++) {
        if (arr[i] == first)
            count1++;
 
        else if (arr[i] == second)
            count2++;
    }
 
    if (count1 > n / 3)
        return first;
 
    if (count2 > n / 3)
        return second;
 
    return -1;
}

16)
Grid Unique Paths 

int countPath(int i,int j ,int n, int m){
	if(i==(n-1) and  j==(m-1)) return 1;
	if(i>=n || j>=m) return 0;
	else return countPath(i+1,j)+countPath(i,j+1);
}
int countPath(int i,int j ,int n, int m,std::vector<std::vector<int> > &dp){
	if(i==(n-1) and  j==(m-1)) return 1;
	if(i>=n || j>=m) return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	else return countPath(i+1,j)+countPath(i,j+1);
}



