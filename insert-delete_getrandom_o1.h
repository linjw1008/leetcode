#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> dataIndex;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, int>::iterator it;
        if ((it = dataIndex.find(val)) != dataIndex.end())
        {
            return false;
        }
        data.push_back(val);
        dataIndex[val] = data.size() - 1;
        return true;
    }

    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator it;
        if ((it = dataIndex.find(val)) == dataIndex.end())
        {
            return false;
        }
        data[it->second] = data[data.size() - 1];
        dataIndex[data[data.size() - 1]] = it->second;
        data.pop_back();
        dataIndex.erase(it);
        return true;
    }    
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */