class RandomizedSet {
    vector<int> numberList;
    unordered_map<int, int> hashTable;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(hashTable.find(val) != hashTable.end())
        {
            return false;
        }
        hashTable[val] = numberList.size();
        numberList.push_back(val);
        return true;
    }
    bool remove(int val) {
        if(hashTable.find(val) == hashTable.end())
        {
            return false;
        }
        swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
        numberList.pop_back();
        hashTable[numberList[hashTable[val]]] = hashTable[val];
        hashTable.erase(val);
        return true;
    }
    int getRandom() {
        return numberList[rand() % numberList.size()];
    }
};