//for undirecte graph--
//Euler path- start from any node and end on any node
//only 2 nodes have odd no. of degree and rest have even degree ------>1 for in,  1 for exit
//Euler tour - start on one node and end on same node
//all nodes have even no. of degrees

//in euler circuit we can start at any node
//hierholzer for directed graph handles both, euler tour and circuit
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>> adj;
        map<int,int> mp1,mp2;
        for(int i=0;i<pairs.size();i++){
            adj[pairs[i][0]].push_back(pairs[i][1]);
            mp1[pairs[i][1]]++;
            mp2[pairs[i][0]]++;
        }
        int start =-1;
        for(int i=0;i<pairs.size();i++){
            if((mp2[pairs[i][0]] - mp1[pairs[i][0]])%2 ==1){
                start = pairs[i][0];
                break;
            }
            if((mp2[pairs[i][1]] - mp1[pairs[i][1]]%2) ==1){
                start = pairs[i][1];
                break;
            }
        }
        if(start==-1){
            start = pairs[0][0];
        }

        stack<int> st;
        vector<int> res;
        st.push(start);

        while(!st.empty()){

            int node = st.top();
            // st.pop();
            //res.push_back(node);
            if(adj[node].size()!=0){        //push if we can push
                    int x = adj[node].size();           
                    st.push(adj[node][x-1]);
                    adj[node].pop_back();
            }
            else{ //if we can't push , push the node and pop from the stack
                st.pop();
                res.push_back(node);
            }
        }
       
       reverse(res.begin(),res.end()); //cos result is stored is reverse order  
        vector<vector<int>> final;
       
        for(int i=0;i<res.size()-1;i++){
            vector<int> temp;
            temp.push_back(res[i]);
            temp.push_back(res[i+1]);
            final.push_back(temp);
            temp.clear();
        }

        return final;
    }
};
//for directed graph--
//Euler path- 1 node has (in_deg-out_deg) == 1 && (out_deg-in_deg)==1 , rest have in_deg == out_deg
//Euler tour - each node has in_deg == out_deg
