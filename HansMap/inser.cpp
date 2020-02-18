#include<cstdio>
#include<cstdlib>
#include<exception>
#include<hash_map>
#include<string>
#include<time.h>

template<typename T>
class RandomPool{
private:
	std::hash_map<T, int> keyIndexMap;
	std::hash_map<int, T> indexKeyMap;
	int size;
public:
	RandomPool(){ 
		srand((unsigned int)time(NULL));
		size = 0; }
	~RandomPool(){ }
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

int main(){
	RandomPool<std::string> rand;
	rand.insert("sun");
	rand.insert("wu");
	rand.insert("kong");
	rand.insert("shi");
	rand.insert("ge");
	rand.insert("cheng");
	rand.insert("xu");
	rand.insert("yuan");
	printf("%s\n", rand.getRandom().c_str());
	printf("%s\n", rand.getRandom().c_str());
	printf("%s\n", rand.getRandom().c_str());
	rand._delete("sun");
	rand._delete("wu");
	rand._delete("kong");
	rand._delete("shi");
	rand._delete("ge");
	rand._delete("cheng");
	rand._delete("xu");
	rand._delete("yuan");
	try{
		printf("%s\n", rand.getRandom().c_str());
	}
	catch (std::exception& e){
		printf("%s\n", e.what());
	}
	system("pause");
	return 0;
}
