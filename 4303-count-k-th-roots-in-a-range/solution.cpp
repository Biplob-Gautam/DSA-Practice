// class Solution {
// public:
//     int countKthRoots(int l, int r, int k) {
//         // l=l-1, r=r+1;
//         int i=l;
//         int count = 0;
        
//         while(i<=r){
//             int flag = false;
//             flag = isperfectKthPower(i,k);

//             if(flag) count++;
//             i++;
//         }

//         return count;
//     }

// private:
//     bool isperfectKthPower(int n, int k){
//         int root = round(pow(n,1.0/k));

//         long long val =1;

//         for(int i=0; i<k; i++){
//             val *= root;
//         }

//         return val == n;
//     }

// };


class Solution {
public:

    int countKthRoots(int l, int r, int k){
        int left = ceil(pow(l,1.0/k)- 1e-9);
        int right = floor(pow(r,1.0/k) + 1e-9);

        return max(0,right-left+1);
    }
};
