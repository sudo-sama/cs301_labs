/*
 * Build a min heap using buildheap method
*/

#include <iostream>

class Heap{
private:
    int* m_array{};
    int m_size{};
    int m_capacity{};

    void percolateDown(int hole){
        int child;
        int temp = m_array[hole];
        for ( /*nothing*/ ; hole * 2 <= m_size; hole = child) {
            child = hole*2;
            if (child != m_size && m_array[child+1] < m_array[child] )
                child++;

            if (m_array[child] < temp)
                m_array[hole] = m_array[child];
            else break;
        }
        m_array[hole] = temp;
    }

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

    void build(int* arr, int size){
        for(int i{1}; i <= size; i++)
            m_array[i] = arr[i-1];

        m_size = size;

        for (int hole{m_size / 2}; hole > 0 ; hole--)
            percolateDown(hole);

    }

    void traverse() {
        for (int i = 1; i <= m_size; i++)
            std::cout << m_array[i] << ' ';

        std::cout << '\n';
    }
};

int main(){
    // int size = 16, arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96, 97, 42, 94, 57, 29};
    int size = 11, arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96};
	Heap heap(size);

    heap.build(arr, size);

	std::cout << "Min Heap using Build Heap method: " ;
	heap.traverse();

    return 0;
}
