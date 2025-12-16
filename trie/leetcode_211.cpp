class WordDictionary {
public:
     struct trie{
        bool isend;
        trie* child[26];
     };

     trie* getnode(){
        trie* node = new trie();
        node->isend = false;
        for(int i=0;i<26;i++){
            node->child[i] = NULL;
        }

        return node;
     }
    trie* root;
    WordDictionary() {
        root  = getnode();
    }
    
    void addWord(string word) {
        
        trie* temp = root;

        for(int i=0;i<word.size();i++){
            int idx;
            idx = word[i]-'a';

            if(temp->child[idx] == NULL){
                trie* tt = getnode();
                temp->child[idx] = tt;
            }

            temp = temp->child[idx];
        }

        temp->isend = true;
    }
    bool check(trie* node, int pos, string word){

        if(pos ==word.size()){
            if(node !=NULL && node->isend ==true){
                return true;
            }

            return false;
        }
        bool ans= false;
        if(word[pos]!='.'){
            int idx = word[pos] - 'a';
            if(node->child[idx]==NULL){
                return false;
            }
            ans = ans | check(node->child[idx],pos+1,word);
            if(ans){
                return true;
            }
        }
        else{
            for(int i=0;i<26;i++){
                if(node->child[i]!=NULL){
                    ans = ans | check(node->child[i],pos+1,word);
                    if(ans){
                        return ans;
                    }
                }
            }
        }

        return false;
    }
    bool search(string word) {
        
        trie* node = root;
        return check(node,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
