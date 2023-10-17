#define MMINSIZE 2
#include <iostream>
#include "List.h"
#include <ostream>

template <typename T>

class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size);


    public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		template <typename U> friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);
		void insert(int pos, T e) override;
		void append(T e) override;
		void prepend(T e) override;
		T remove(int pos) override;
		T get(int pos) override;
		int search(T e) override;
		int size() override;
      

};


template <typename T>

ListArray<T>::ListArray(){

	arr = new T[MINSIZE];
	max = MINSIZE;
	n = 0;
}

template <typename T>
void ListArray<T>::insert(int pos, T e){

	if(pos > n || pos < 0)
		throw std::out_of_range("fuera de rango");
	for(int i = n; i >= pos; i--)		//Reajustamos la lista
		arr[i+1] = arr[i];
	arr[pos] = e;
	n++;
}

template <typename T>
void ListArray<T>::append(T e){
	
	arr[n] = e;
	n++;
}

template <typename T>
void ListArray<T>::prepend(T e){
	
	for(int i = n; i > 0; i-- )
		arr[i] = arr[i - 1];
	arr[0] = e;
	n++;

}

template <typename T>
T ListArray<T>::remove(int pos){
	if(pos > n - 1 || pos < 0)
		throw std::out_of_range("fuera de rango");
	else{
		T aux = arr[pos];
		for(int i = pos; i < n -1; i++)
			arr[i] = arr[i+1];
		n--;
		return aux;
	}
}

template <typename T>
T ListArray<T>::get(int pos){

	if(pos > n -1 || pos < 0)
                throw std::out_of_range("fuera de rango");
	else
                return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e){
	for(int i = 0; i < n; i++){
		if(arr[i] == e)
			return i;
	}
	return -1;
}

template <typename T>
int ListArray<T>::size(){
        return n;
}


template <typename T>
ListArray<T>::~ListArray(){
	delete[] arr;
}

template <typename T>
T ListArray<T>::operator[](int pos){
	if(pos > n -1 || pos < 0)
		throw std::out_of_range("fuera de rango");
	else
		return arr[pos];
}

template <typename T>
void ListArray<T>::resize(int new_size){
	
	T* a = new T[new_size];
	for(int i = 0; i < n; i++)
		a[i] = arr[i];
	delete[] arr;
	max = new_size;
	arr = a;
}

template <typename T>
bool List<T>::empty(){
	if(size() == 0)
		return true;
	return false;
}

template <typename U>
std::ostream& operator<<(std::ostream &out, const ListArray<U> &list){
	for(int i = 0; i < list.n; i++)
    		out << list.arr[i] << " ";
      	out << std::endl;
   	return out;
}

