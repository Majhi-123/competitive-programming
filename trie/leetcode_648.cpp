class Solution {
public:
    struct trie{
        bool isend;
        trie* child[26];
    };

    trie* getnode(){
        trie* node = new trie();
        node->isend  =false;
        for(int i=0;i<=25;i++){
            node->child[i] = NULL;
        }
        return node;
    }

    //trie* root;
    void insert(string st,trie* root){
        trie* temp = root;

        for(int i=0;i<st.size();i++){
            int idx = st[i] - 'a';
            if(temp->child[idx] == NULL){
                trie* tt = getnode();
                temp->child[idx] = tt;
            }
            temp = temp->child[idx];
        }
        temp->isend = true;
    }
    string prefix(string st,trie* root){
         trie* temp = root;
         string ans  ="";
         bool ch = false;
        for(int i=0;i<st.size();i++){
            int idx = st[i] - 'a';
            if(temp->child[idx] != NULL){
                ans += st[i];
                temp = temp->child[idx];
                if(temp!=NULL && temp->isend==true){
                    ch = true;
                    break;
                    //return ans;
                }
            }
            else{
                
                string tt = "";
                return tt;
               
            }
        }
        if(ch){
            //string tt ="";
            return ans;
        }

        string tt ="";
        return tt;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
         trie* root = getnode();

         for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i],root);
         }
         string final ="";
         string st ="";
         for(int i=0;i<sentence.size();i++){
            if(sentence[i]-'a' >=0 && sentence[i]-'a'<=25){
                
                st += sentence[i];
            }
            else{
                string pre = prefix(st,root);
                if(pre.size()==0){
                    pre = st;
                }
                 for(int j=0;j<pre.size();j++){
                    final += pre[j];
                 }
                 final += " ";
                 st = "";
            }
         }
         string pre = prefix(st,root);
         if(pre.size()==0){
            pre = st;
         }
                for(int j=0;j<pre.size();j++){
                   final += pre[j];
                }
                 return final;
    }
};
