Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


别人的优秀方案：
 void dfs(int pos, vector<int> &num, vector<vector<int>> &result){
    if(pos == num.size()){
        result.push_back(num);
    }
    else{
        for(int i=pos; i<num.size(); i++){
            swap(num[i], num[pos]);
            dfs(pos+1, num, result);
            swap(num[i], num[pos]);
        }
    }