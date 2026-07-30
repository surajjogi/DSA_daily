class Solution {
public:
    int minimumPushes(string word) {
      int answer = 0;
int n=word.size();
for(int i=0;i<n;i++){
    answer += (i/8) + 1;
}
return answer;
    }
};