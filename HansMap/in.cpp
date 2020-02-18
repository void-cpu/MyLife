#include<cstdio>
#include<cstdlib>
#include<exception>
#include<hash_map>
#include<string>
#include<time.h>

using namespace std;

template<typename T>
class RandomPool{
private:
    hash_map<T, int> keyIndexMap;
    hash_map<int, T> indexKeyMap;
    int size;
	public:
    RandomPool(){
        srand((unsigned int)time(NULL));
        size = 0; }
    ~RandomPool():size(0){}
    void insert(T key);
    void _delete(T key);
    T getRandom();
};

template<typename T>
void RandomPool<T>::insert(T key){
    if (keyIndexMap.find(key) == keyIndexMap.end()){
        keyIndexMap[key] = size;
        indexKeyMap[size++] = key;
    }
}

template<typename T>
void RandomPool<T>::_delete(T key){
    if (keyIndexMap.find(key) != keyIndexMap.end()){
        int index = keyIndexMap[key];
        int lastindex = --size;
        T lastkey = indexKeyMap[lastindex];
        keyIndexMap[lastkey] = index;
        indexKeyMap[index] = lastkey;
        keyIndexMap.erase(key);
        indexKeyMap.erase(lastindex);
    }
}

template<typename T>
T RandomPool<T>::getRandom(){
    if (size == 0){
        throw std::exception("data is null!");
    }
    int index = rand() % size;
    return indexKeyMap[index];
}

