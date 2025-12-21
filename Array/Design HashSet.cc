using namespace std;
class MyHashSet {
private:
vector<int> set;
vector<int> hash_index_set;
public:
    MyHashSet() : hash_index_set(1000001, -1){

    }
    void add(int key) {
        if ( hash_index_set[key] != -1 ) return;
        set.push_back(key);
        hash_index_set[key] = set.size() - 1;
    }
    void remove(int key) {
        if ( hash_index_set[key] == -1 ) return;

        hash_index_set[set.back()] = hash_index_set[key];
        set[hash_index_set[key]] = set.back();

        set.pop_back();
        hash_index_set[key] = -1;
    }
    bool contains(int key) {
        if (hash_index_set[key] != -1) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
