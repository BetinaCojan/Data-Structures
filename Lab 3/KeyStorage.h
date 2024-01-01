template <typename T> 
class KeyStorage {
public: 
    int key;
    T member;
};

int main() {
    KeyStorage<long> keyElement;
    return 0;
}