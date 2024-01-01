template <typename T>
class GenericContainer {
public:
    int size;
    int maxCapacity;

    GenericContainer(int maxCapacity) {
        this->size = 0;
        this->maxCapacity = maxCapacity;
        this->dataArray = new T[maxCapacity];
    }

    ~GenericContainer() {
        delete[] dataArray;
    }

    T *getArray() {
        return dataArray;
    }

private:
    T *dataArray;
};