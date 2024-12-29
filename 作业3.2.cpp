#include <unordered_map>

class Map 
{
private:
    std::unordered_map<int, int> elements;

public:
    void init() {
        elements.clear();
    }

    int* operator[](int key) {
        auto it = elements.find(key);
        if (it != elements.end()) {
            return &it->second;
        }
        return nullptr;
    }

    void clear() {
        elements.clear();
    }

    void insert(int key, int value) {
        elements[key] = value;
    }

    void remove(int key) {
        elements.erase(key);
    }
};
