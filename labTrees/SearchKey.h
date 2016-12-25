#ifndef SEARCHKEY_H
#define SEARCHKEY_H

/*
SearchKey class implemented for cases in which objects being stored don't have a built in search key 
*/

template <typename T>
class SearchKey
{
public:
	SearchKey() {}
	SearchKey(const T& keyValue) : searchKey(keyValue) {}
	~SearchKey() {}
	T getKey() const { return searchKey; }
	void setKey(T keyValue) { searchKey = keyValue; }
protected:
	T searchKey;
};

#endif SEARCHKEY_H