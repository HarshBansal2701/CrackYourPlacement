class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Approach 
        // Find the sum of first k elements
        // one by one decrease score of element from starting and add the score of end elements

        int n = cardPoints.size();
        int score = 0;
        for(int i = 0 ; i<k ; i++){
            score += cardPoints[i];
        }
        int maxScore = score;

        for(int i = 0 ; i<k ; i++){
            score =  score + cardPoints[n-i-1] - cardPoints[k-i-1];
            maxScore = max(maxScore ,score);
        }

        return maxScore;

        // TC -> O(n) , SC -> O(1)
    }
};