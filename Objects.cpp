#include"Objects.h"

size_t Object::_count(0);

bool Task::HasResult() const
{
  return false;
}

std::string Task::GetType() const
{
  return "Task type";
}

std::string Task::toString() const
{
  std::string str = "It's task.";
  return str;
}


Named::Named() 
{
  _name = "Default name";
}

Named::Named(std::string name)
{
  _name = name;
}

std::string Named::toString() const
{
  std::string str = "Object: " + _name;
  return str;
}


AddTaskToContainer::AddTaskToContainer() 
{
  _name = "AddTaskToContainer";
  Object::_count++;
}

std::string AddTaskToContainer::GetType() const 
{
  return "AddTaskToContainer type";
}

bool AddTaskToContainer::HasResult() const
{
  return false;
}

std::string AddTaskToContainer::toString() const
{
  std::string str = _name;
  return str;
}

void AddTaskToContainer::Add(Container<Task*>& container, Task* task)
{
  container.PushBack(task);
}


Number_Of_Objects_In_Current_Container::Number_Of_Objects_In_Current_Container() 
{
  _name = "Number_Of_Objects_In_Current_Container";
  Object::_count++;
}

std::string Number_Of_Objects_In_Current_Container::GetType() const
{
  return "Number_Of_Objects_In_Current_Container type";
}

bool Number_Of_Objects_In_Current_Container::HasResult() const
{
  return true;
}

void Number_Of_Objects_In_Current_Container::Number(const Container<Task*>& container)
{
  _result = container.GetQuantityElements() + 1;
}

std::string Number_Of_Objects_In_Current_Container::toString() const
{
  std::string str = _name + ". In current container " + std::to_string(_result) + " objects.";
  return str;
}


Number_Of_Tasks_With_Result::Number_Of_Tasks_With_Result() 
{
  _name = "Number_Of_Tasks_With_Result";
  Object::_count++;
}

std::string Number_Of_Tasks_With_Result::GetType() const
{
  return "Number_Of_Tasks_With_Result type";
}

void Number_Of_Tasks_With_Result::Number(const Container<Task*>& container) 
{
  _result = 0;
  for (auto iter = container.begin(); iter != container.end(); ++iter) {
    auto task = *iter;
    if (task->HasResult())
      _result++;
  }
}

std::string Number_Of_Tasks_With_Result::toString() const
{
  std::string str = _name + ". The number of tasks with result in container : " + std::to_string(_result);
  return str;
}

bool Number_Of_Tasks_With_Result::HasResult() const
{
  return true;
}


Clean::Clean() 
{
  _count++;
  _number_deleted = 0;
}

std::string Clean::GetType() const
{
  return "Clean type";
}

size_t Clean::FindNumberDeletedInString(const std::string str) const
{
  size_t result;
  auto it = std::find_if(str.begin(), str.end(), isdigit);
  if (it != str.end()) 
    result = std::atoi(str.c_str() + (it - str.begin()));
  return result;
}

void Clean::CleanContainer(Container<Task*>& container)
{
  size_t size_container = container.GetQuantityElements();
  _number_deleted = 0;
  for (size_t i = 1; i <= size_container; i++) {

    // if first element is Clean task, we need added 
    //number of previous deleted elements
    Task* first_element = container.GetFirst();
    if (first_element->GetType() == "Clean type") {
      std::string str = first_element->toString();
      _number_deleted += FindNumberDeletedInString(str);
    }
    container.RemoveFirst();
    _number_deleted++;
  }
}

std::string Clean::toString() const
{
  std::string str = "Clean. " + std::to_string(_number_deleted) + " tasks were deleted";
  return str;
}

bool Clean::HasResult() const
{
  return false;
}


Number_Of_Objects::Number_Of_Objects() 
{
  _name = "Number_Of_Objects";
  Object::_count++;
  _result = Object::_count;
}

std::string Number_Of_Objects::GetType() const
{
  return "Number_Of_Objects type";
}

std::string Number_Of_Objects::toString() const
{
  std::string str = _name + ". The number of created objects at the moment : " + std::to_string(_result);
  return str;
}

bool Number_Of_Objects::HasResult() const
{
  return true;
}