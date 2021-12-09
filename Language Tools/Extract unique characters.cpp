Extract Unique characters
Send Feedback
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde


#include<map>

string uniqueChar(string str){
    // Write your code here
    
	map<char, int> m;
    char *arr = new char[1000];//give size anything as it is dynamic 
    int index = 0;
    int i=0;
    while(str[i] != '\0'){
        if(m[str[i]] == 0){
            arr[index] = str[i];
            m[str[i]] += 1;
            index++;
        }
        i++;
    }
    arr[index] = '\0';
    return arr;
    
     
    
}
