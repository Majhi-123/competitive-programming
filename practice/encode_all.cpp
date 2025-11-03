Bob wants to send an encrypted string consisting of only lowercase Latin alphabets to Alice. He has thought of using the Caesar cipher, but with a small modification. Caesar cipher is a substitution based cipher in which each letter in the plaintext is shifted a certain number of places down the alphabet. With the modification, instead of shifting all letters by the same number, Bob shifts each letter by different numbers based on a keyword K. We will understand his algorithm by an example given below.

Let's take the keyword K as ‘algo’ and the main word as ‘cplusplus’.

Each letter of the keyword symbolizes a number from 0 to 25 where ‘a’ is 0, ‘b’ is 1, ‘c’ is 2 and so on. Now, make an infinite string S joining the keyword repeatedly one after another, so here that string S would be ‘algoalgoalgoalgoalgoal…’.

Next, the main word will be shifted down by its corresponding letter value from the string S, i.e., ‘c’ will be shifted by ‘a’, p will be shifted by ‘l’, ‘l’ will be shifted by ‘g’ and so on. When shifting, if the shifted word goes beyond ‘z’, then start from ‘a’ again (e.g., ‘p’ + ‘l’ = ‘a’). In this case, the encoded string will be 'carisaris'.

Bob does not want to encode the whole message manually. He wants to write a program that automates this encoding process. Can you help him?

Input Format
The first line contains the number of the test cases, T - the number of test cases.
For each test case, there are two strings, first the keyword and next the main word, separated by a single whitespace.

Output Format
Print each of the encoded strings in a new line.

Constraints
1 ≤ T ≤ 105
0 < length of each word ≤ 1000
0 < sum of the lengths of all main words ≤ 105


// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string ff,ss;
        cin>>ff>>ss;
        for(int i=0;i<ss.size();i++){
            int j =i;
            if(j>ff.size()-1){
                j = i%ff.size();
            }
           int x = ss[i] -'a';
           int b = ff[j] - 'a';
           x =(x + b)%26;
           ss[i] = 'a' + x;

        }

        cout<<ss<<"\n";
    }
    return 0;
}
