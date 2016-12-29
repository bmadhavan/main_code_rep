/* 
Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Key things to remember:
* Handle sign. Make the number positive and handle it. Add sign during return. 
* Handle over flow cases. Check everytime result is either multiplied or added with.  

*/

    int reverse(int x) {
        int result=0;
        int max = INT_MAX;
        int minus = x < 0 ? 1 : 0; 
        if ( minus ) x=x*-1;
        
        while ( x ) {
           if (/* Handle if result * 10 overflows */ (result > max/10 ) || 
               /* Handle if adding x overflows    */ ( max - result*10 < x%10 ) ) return 0;   
          
           result = result * 10 + x % 10;
           x = x/10;
        }
        if ( minus )  return result*-1;
        else return result;
    }
