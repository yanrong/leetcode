#include <vector>
using std::vector;

class Solution {
public:
    //official solution
    /**
     * G(n) represent the total number of generate BST 
     * F(i, n) represent the number of BTS which take in i as root
     * we take the each data in sequence as root, and sum the all generate BTS tree
     * G(n) = F(1,n) + F(2,n) +...+F(n, n), if only have a data or empty tree, there
     * have only a BTS .G(0) = G(1) = 1;
     * for the F(i, n) the generate BTS number of left child and right is G(i - 1) G(n - i)
     * so G(n) = sum(G(i - 1) * G( n - i)) i in [1 to n]
    **/
    int numTrees(int n) {
        vector<int> G(n + 1);
        G[0] = 1;
        G[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                G[i] += G[j - 1] * G[i - j]; 
            }
        }

        return G[n];
    }

    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        long C = 1;
        for(int i = 0; i < n; i++){
            C = C *2 *(2 * i + 1)/(i + 2);
        }
        return C;
    }

    int numTrees(int n) {
        long C = 1;
        for(int i = 1; i <= n; i++){
            C = C * (4 * i - 2)/(i + 1);
        }
        return C;
    }
};