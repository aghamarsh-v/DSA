#include "./stack/stack.cpp"
#include "./queue/queue.cpp"

int main () {
    queue<int> q(100);
    q.enqueue(15);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(12);
    q.enqueue(11);

    stack<int> s(100);
    int itr = 1;

    while (! q.isEmpty()) {
        if (s.isEmpty() || s.top() <= q.front()) {
            auto x = q.dequeue();
            s.push(x);
        } else {
            auto x = s.pop();
            q.enqueue(x);
        }
    }
    std::cout << "stack push is called :: " << s.push_count << " times \n";
    return 0;
}