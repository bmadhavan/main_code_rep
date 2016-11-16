class Solution {
public:
string multiply(string num1, string num2) {
     int m = num1.length(); 
     int n = num2.length();
     int pdt[m+n] = {0};
     
     for ( int i=m-1; i >=0 ; i-- ) {
         for ( int j=n-1; j >=0 ; j--) { 
             int rst = (num1[i] - '0') * (num2[j] - '0');
             int p1 = i + j;
             int p2 = i + j + 1;
             // pos0, pos1, pos2 and so on...... 
             rst += pdt[p2];
         
             pdt[p2] = rst%10;
             pdt[p1] += rst/10;
         }
     }
     
     string result=""; 
     for ( int k = 0 ; k < m+n ; k++ ) {
         result[k] = pdt[k] + '0';
     }
   
     return result;
    }
};