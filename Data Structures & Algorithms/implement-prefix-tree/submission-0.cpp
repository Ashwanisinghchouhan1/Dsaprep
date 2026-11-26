class PrefixTree {

class Trienode{
    public:
    Trienode*children[26];
    bool isleaf;

    Trienode(){
        isleaf = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

Trienode *root;
public:
    PrefixTree() {
         root = new Trienode();
    }
    
    void insert(string word) {
        Trienode*curr = root;
        for(char c : word){
            int idx = c - 'a';

            if(curr->children[idx] == nullptr){
               curr->children[idx] = new Trienode();
                
            }
            curr = curr->children[idx];
        }
        curr->isleaf = true;
    }
    
    bool search(string word) {
        Trienode*curr = root;
        for(char c : word){
            int idx = c - 'a';

            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isleaf;
    }
    
    bool startsWith(string prefix) {
         Trienode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true; 
    }
};
