#define MMINSIZE 2
#include <iostream>
#include "List.h"

template <typename T>

class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;


        public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		friend std::ostream &operator<<(std::ostream &out, const ListArray<T> &list);
		void resize(int new_size);

      

};


ListArray::ListArray(){


}

ListArray::~ListArray(){
	delete[] arr;
}

T ListArray::operator[](int pos){


}


