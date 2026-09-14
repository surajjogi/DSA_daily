class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<bool>row(mat.size(),false);
        vector<bool>col(mat[0].size(),false);
          int y=mat[0].size();
          int x=mat.size();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(mat[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

         for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
               if(row[i]==true||col[j]==true){
                mat[i][j]=0;
               }
            }
        }
    }
};