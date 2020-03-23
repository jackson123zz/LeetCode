/*
vector的操作
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (find(numSet.begin(), numSet.end(), val) == numSet.end()) {
            numSet.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        vector<int>::iterator it = find(numSet.begin(), numSet.end(), val);
        if (it != numSet.end()) {
            numSet.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int len = numSet.size();
        int m = rand() % (len - 1 - 0 + 1) + 0;
        return numSet[m];
    }
private:
    vector<int> numSet = {};
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */