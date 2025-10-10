class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1){
            return ans;
        }
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2){
            return ans;
        }
        while(numRows-->2){
            vector<int> current;
            current.push_back(1);
            for(int i=0;i<temp.size()-1;i++){
                current.push_back(temp[i]+temp[i+1]);
            }
            current.push_back(1);
            temp=current;
            ans.push_back(current);
        }
        return ans;
    }
};
