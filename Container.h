#pragma once

#include <iostream>

//Implementation by doubly linked list
template <typename T>
class Container 
{
public:

  Container() 
  {
    _head = NULL;
    _last = NULL;
    _size = 0;
  }

  Container(const T& param) 
  {
    _head = new node;
    _head->val = param;
    _head->next = NULL;
    _head->prev = NULL;
    _last = _head;
    _size = 1;
  }

  ~Container() 
  {
    while (!IsEmpty()) {
      node* tmp = _head;
      _head = _head->next;
      delete tmp;
    }
  }

  Container(const Container& a) = delete;

  void operator=(const Container& a) = delete;

  void PushFront(const T& param)
  {
    node* tmp = new node;
    tmp->val = param;
    tmp->next = _head;
    tmp->prev = NULL;
    _head = tmp;
    _size++;
  }

  void PushBack(const T& param)
  {
    node* tmp = new node;
    tmp->val = param;
    tmp->next = NULL;
    tmp->prev = _last;
    IsEmpty() ? _head = tmp : _last->next = tmp;
    _last = tmp;
    _size++;
  }

  void RemoveFirst() 
  {
    try {
      if (!IsEmpty()) {
        node* tmp = _last;
        _last = tmp->prev;
        (_last != NULL) ? _last->next = NULL : _head = NULL;
        delete tmp;
        _size--;
      }
      else
        throw std::out_of_range("the container is empty!");
    }
    catch (std::out_of_range err) {
      std::cout << err.what() << std::endl;
    }
  }

  void RemoveLast() 
  {
    try {
      if (!IsEmpty()) {
        node* tmp = _last;
        _last = tmp->prev;
        (_last != NULL) ? _last->next = NULL : _head = NULL;
        delete tmp;
        _size--;
      }
      else
        throw std::out_of_range("the container is empty!");
    }
    catch (std::out_of_range err) {
      std::cout << err.what() << std::endl;
    }
  }

  const T& GetFirst() const
  {
    try {
      return (!IsEmpty()) ? _head->val : throw std::out_of_range("the container is empty!");
    }
    catch (std::out_of_range err) {
      std::cout << err.what() << std::endl;
    }
  }

  const T& GetLast() const
  {
    try {
      return (!IsEmpty()) ? _last->val : throw std::out_of_range("the container is empty!");
    }
    catch (std::out_of_range err) {
      std::cout << err.what() << std::endl;
    }
  }

  size_t GetQuantityElements() const
  {
    try {
      return (!IsEmpty()) ? _size : throw std::out_of_range("the container is empty!");
    }
    catch (std::out_of_range err) {
      std::cout << err.what() << std::endl;
    }
  }

  bool IsEmpty() const
  {
    return _head == NULL;
  }

  void Swap(Container& other)
  {
    std::swap(this->_head, other->_head);
    std::swap(this->_size, other->_last);
    std::swap(this->_size, other->_size);
  }

  void Reverse()
  {
    node* tmp = _head->next;
    while (tmp != _last)
    {
      node* next = tmp->next;
      std::swap(tmp->next, tmp->pred);
      tmp = next;
    }
  }

  class Iterator
  {
  public:
    Iterator()
    {
      _it = _head;
    }

    Iterator(struct node* param)
    {
      _it = param;
    }

    Iterator& operator ++()
    {
      try {
        (_it != NULL) ? _it = _it->next : throw std::out_of_range("out of range");
        return *this;
      }
      catch (std::out_of_range err) {
        std::cout << err.what() << std::endl;
      }
    }

    bool operator !=(const Iterator tmp)const
    {
     return this->_it != tmp._it;
    }

    T& operator *()
    {
      return _it->val;
    }

  private:
    struct node* _it;
  };

  Iterator begin()const
  {
    return Iterator(_head);
  }

  Iterator end()const
  {
    return Iterator(NULL);
  }

private:

  struct node
  {
    T val;
    node* next;
    node* prev;
  };

  node* _head;
  node* _last;
  size_t _size;
};
