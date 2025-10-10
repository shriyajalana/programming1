class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
        vector<vector<int>> ans;
        ans.push_back({1});
        if(rowIndex==0){
            return ans[rowIndex];
        }
        ans.push_back({1,1});
        if(rowIndex==1){
            return ans[rowIndex];
        }

        for(int i=0;i<numRows-2;i++){
            vector<int> temp=ans[ans.size()-1];
            vector<int> RealTemp={1};
            for(int j=0;j<temp.size()-1;j++){
                RealTemp.push_back(temp[j]+temp[j+1]);
            }
            RealTemp.push_back(1);
            ans.push_back(RealTemp);
        }
        return ans[rowIndex];
        
    }
};
