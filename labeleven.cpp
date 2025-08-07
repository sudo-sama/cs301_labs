/*
 * Build a min heap using insert method.
*/

#include <iostream>

class Heap{
private:
    int* m_array{};
    int m_size{};
    int m_capacity{};
public:
    Heap(int capacity){
        m_array = new int[capacity+1];
        m_capacity = capacity;
        m_size = 0;
    }

    bool isFull(){
        return m_size == m_capacity;
    }

    bool isEmpty(){
        return m_size == 0;
    }

    void insert(const int& x){
        if(isFull()){
            std::cout << "Heap is full! Insertion Failed.\n";
            return;
        }

        int hole = ++m_size;

        for(; hole > 1 && x < m_array[hole/2]; hole = hole/2)
            m_array[hole] = m_array[hole/2];

        m_array[hole] = x;
    }

    void traverse() {
        for (int i = 1; i <= m_size; i++)
            std::cout << m_array[i] << ' ';

        std::cout << '\n';
    }
};

int main(){
    int size = 16, arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96, 97, 42, 94, 57, 29};
	Heap heap(size);
	for (int i = 0; i < size; i++)
		heap.insert(arr[i]);

	std::cout << "Min Heap using insert method: " ;
	heap.traverse();

    return 0;
}
