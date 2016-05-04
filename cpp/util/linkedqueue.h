#pragma once


namespace kg {
namespace util {

template<typename T>
class LinkedQueue {
public:
    LinkedQueue();

    bool getFront(T& v);
    bool addBack(const T& v);
    bool isEmpty() const;
    unsigned size() const;

private:
    struct Node {
        Node(const T& v)
            :   _data(v),
                _next(nullptr)
        {}
        T _data;
        Node* _next;
    };

    Node* _head;
    Node* _tail;

};


template<typename T>
LinkedQueue<T>::LinkedQueue()
    :   _head(nullptr), _tail(nullptr)
{}

template<typename T>
bool LinkedQueue<T>::getFront(T& v) {
    if (!_head) {
        return false;
    }

    v = _head->_data;
    Node* tmp = _head;
    _head = _head->_next;

    if(!_head) {
        // no more items
        _tail = nullptr;
    }
    delete tmp;
    return true;
}

template<typename T>
bool LinkedQueue<T>::addBack(const T& v) {
    if(_tail == nullptr) {
        _tail = new Node(v);
        _head = _tail;
    }
    else {
        Node* newNode = new Node(v);
        _tail->_next = newNode;
        _tail = _tail->_next;
    }

    return true;
}

template<typename T>
bool LinkedQueue<T>::isEmpty() const {
    return (!_head);
}

template<typename T>
unsigned LinkedQueue<T>::size() const {
    if(!_head) {
        return 0;
    }

    unsigned cnt = 1;
    const Node* cur = _head->_next;
    while(cur) {
        cur = cur->_next;
        ++cnt;
    }
    return cnt;
}

} // close namespace util
} // close namespace kg
