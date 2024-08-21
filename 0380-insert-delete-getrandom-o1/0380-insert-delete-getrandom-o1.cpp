#include <unordered_set>
#include <vector>
#include <cstdlib> // For rand()

class RandomizedSet {
private:
    std::unordered_set<int> s;
    std::vector<int> v;

public:
    RandomizedSet() {
        // Class-level members initialized implicitly.
    }
    
    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        }
        s.insert(val);
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) {
            return false;
        }
        s.erase(val);
        
        // Find the position of the element in the vector.
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == val) {
                // Swap with the last element and pop back.
                std::swap(v[i], v.back());
                v.pop_back();
                break;
            }
        }
        
        return true;
    }
    
    int getRandom() {
        if (v.empty()) return -1; // Optional: handle edge case when set is empty
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
