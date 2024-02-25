/**
 * Implementation of stack using arrays in C++
 * Author: Aghamarsh Varanasi
 * Rool Number: 2023mt93313
*/

#include <iostream>
#include <vector>
typedef unsigned int uint;

template <class T>
class stack {
    public:
        stack() {
            stack(MAX_LENGTH);
        }

        stack(uint size) {
            m_ptr = new T[size];
            m_top = -1;
            max_length = size;
        }

        ~stack() {
            delete m_ptr;
        }

        void push(T val) {
            if (this->size() >= max_length) {
                throw "out of bounds";
            }
            push_count += 1;
            m_ptr[++m_top] = val;
        }

        T& pop() {
            if(this->isEmpty()) {
                throw "array empty";
            }
            return m_ptr[m_top--];
        }

        uint size() {
            return m_top + 1;
        }

        bool isEmpty() {
            return (m_top == -1);
        }

        T& top() {
            if (!isEmpty()) {
                return m_ptr[m_top];
            }
            throw "stack empty";
        }

        void print () {
            for(int itr = 0; itr <= m_top; itr ++) {
                std::cout << m_ptr[itr] << " ";
            }
        }

        int push_count = 0;

    private:
        T* m_ptr;
        int m_top;
        uint max_length;
        const uint MAX_LENGTH = 100;
};
