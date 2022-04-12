#pragma once
#include<string>
#include<random>
#include"Container.h"

class Object;
class Task;
class Named;
template <typename T> class BinaryOperation;
class AddTaskToContainer;
class Number_Of_Objects_In_Current_Container;
class Number_Of_Tasks_With_Result;
class Clean;
class Number_Of_Objects;


class Object 
{
public:
  virtual std::string toString() const = 0;
protected:
  static size_t _count;
};

class Task: public Object
{
public:
  virtual std::string toString() const override;
  virtual bool HasResult() const;
  virtual std::string GetType() const;
};

class Named: public Object 
{
public:
  Named();
  Named(std::string name);
  virtual std::string toString() const;
protected:
  std::string _name;
};

template <typename T>
class BinaryOperation: public Task, public Named
{
public:
  BinaryOperation(T value_1, T value_2) 
  {
    _name = "BinaryOperation";
    _value_1 = value_1;
    _value_2 = value_2;
    Object::_count++;
  }

  void sum()
  {
    _result = _value_1 + _value_2;
    _operation = "+";
  }

  void sub()
  {
    _result = _value_1 - _value_2;
    _operation = "-";
  }

  void mul()
  {
    _result = _value_1 * _value_2;
    _operation = "*";
  }

  void div()
  {
    _result = _value_1 / _value_2;
    _operation = "/";
  }

  bool HasResult() const
  {
    return true;
  }

  void Solve()
  {
    size_t pr = rand() % 4;
    switch (pr) {
    case 0: {
      sum();
      break;
    }
    case 1: {
      sub();
        break;
    }
    case 2: {
      mul();
        break;
    }
    case 3: {
      div();
        break;
    }
    }
  }

  virtual std::string toString() const
  {
    std::string str = _name + ". " + std::to_string(_value_1) + " " + _operation + " " 
      + std::to_string(_value_2) + " = " + std::to_string(_result);
    return str;
  }

  std::string _type;

private:
  T _result;
  T _value_1;
  T _value_2;
  std::string _operation;
};

class AddTaskToContainer : public Task, public Named
{
public:
  AddTaskToContainer();
  void Add(Container<Task*>& container, Task* task);
  bool HasResult() const;
  std::string toString() const;
  std::string GetType() const;
};

class Number_Of_Objects_In_Current_Container: public Task, public Named
{
public:
  Number_Of_Objects_In_Current_Container();
  bool HasResult() const;
  void Number(const Container<Task*>& container);
  std::string toString() const;
  std::string GetType() const;
private:
  size_t _result;
};

class Number_Of_Tasks_With_Result : public Task, public Named
{
public:
  Number_Of_Tasks_With_Result();
  bool HasResult() const;
  void Number(const Container<Task*>& container);
  std::string toString() const;
  std::string GetType() const;
private:
  size_t _result;
};

class Clean : public Task
{
public:
  Clean();
  bool HasResult() const;
  void CleanContainer(Container<Task*>& container);
  std::string toString() const;
  std::string GetType() const;
private:
  size_t FindNumberDeletedInString(const std::string str) const; //Look CleanContainer(Container<Task*>& container)
  size_t _number_deleted;
};

class Number_Of_Objects : public Task, public Named
{
public:
  Number_Of_Objects();
  bool HasResult() const;
  std::string toString() const;
  std::string GetType() const;
private:
  size_t _result;
};