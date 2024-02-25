/**
 * Implementation of queue using arrays in C++
 * Author: Aghamarsh Varanasi
 * Rool Number: 2023mt93313
*/

#include <iostream>
#include <vector>
typedef unsigned int uint;

template <class T>
class queue {
    public:
        queue() {
            queue(MAX_LENGTH);
        }

        queue(uint size) {
            m_ptr = new T[size];
            m_front = -1;
            m_rear = -1;
            max_length = size;
        }

        ~queue() {
            delete m_ptr;
        }
        
        void enqueue(T val) {
            if (this->size() >= max_length) {
                throw "out of bounds";
            }
            m_ptr[++m_rear] = val;
        }

        T& dequeue() {
            if(this->isEmpty()) {
                throw "array empty";
            }
            return m_ptr[++m_front];
        }

        uint size() {
            return m_rear - m_front;
        }

        bool isEmpty() {
            return (m_front >= m_rear);
        }

        T& front() {
            return m_ptr[m_front + 1];
        }

        T& rear() {
            return m_ptr[m_rear];
        }

    private:
        T* m_ptr;
        int m_front;
        int m_rear;
        uint max_length;
        const uint MAX_LENGTH = 100;
};