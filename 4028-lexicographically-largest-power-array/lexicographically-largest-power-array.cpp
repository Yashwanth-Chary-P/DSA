class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> grp;
  
  
        grp.push_back(nums);
        
        vector<int> ans(15);

        for(int bit = 14; bit >= 0; bit--){
            vector<vector<int>> nxt;

            int cnt = 0;
            bool done = false;

            for(int i = 0; i < grp.size(); i++){
                vector<int> zero;
                vector<int> one;

                for(int x : grp[i]){
                    if(x & (1 << bit)){
                        one.push_back(x);
                    } else{
                        zero.push_back(x);
                    }
                }

                if(zero.empty()){
                    cnt += grp[i].size();
                    nxt.push_back(grp[i]);
                } 
                
                else if(one.empty()){
                    ans[14-bit] = cnt;

                    for(int j = i; j < grp.size(); j++){
                        nxt.push_back(grp[j]);
                    }

                    done = true;
                    break;
                } 
                
                else {
                    ans[14-bit] = cnt + one.size();

                    nxt.push_back(one);
                    nxt.push_back(zero);

                    for(int j = i + 1; j < grp.size(); j++){
                        nxt.push_back(grp[j]);
                    }

                    done = true;
                    break;
                }
            }

            if(!done)
                ans[14-bit] = cnt;
            

            grp = nxt;
        }

        return ans;
    }
};