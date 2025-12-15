class Trie {
public:
    struct trienode{
        bool isend;
        trienode* children[26];
    };
    trienode* makenode(){
        trienode* node = new trienode();
        node->isend = false;
        for(int i=0;i<=25;i++){
            node->children[i] = NULL;
        }
        return node;
    }
    trienode* root;
    Trie() {
        root = makenode();
    }
    
    void insert(string word) {
        trienode* temp = root;

        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(temp->children[idx] == NULL){
                trienode* node = makenode();
                temp->children[idx] = node;
            }
            temp = temp->children[idx];
        }
        temp->isend = true;
    }
    
    bool search(string word) {
        trienode* temp = root;

        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(temp->children[idx] == NULL){
                return false;
            }
            temp = temp->children[idx];
        }
        if(temp!=NULL && temp->isend==true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trienode* temp = root;

        for(int i=0;i<prefix.size();i++){
            int idx = prefix[i]-'a';
            if(temp->children[idx] == NULL){
                return false;
            }
            temp = temp->children[idx];
        }
       
        return true;
    }
};
