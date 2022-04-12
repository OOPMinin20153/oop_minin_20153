#include"Container.h"
#include"Objects.h"

void GenerateTasksContainer(Container<Task*>& container)
{
  size_t pr = rand() % 6;

  for (size_t i = 0; i < 20; i++) {

    switch (pr) {
    case 0: {
      BinaryOperation<double>* tmp = new BinaryOperation<double>(1.5, 2.3);
      tmp->Solve();
      container.PushBack(tmp);
      break;
    }
    case 1: {
      AddTaskToContainer* tmp = new AddTaskToContainer;
      Number_Of_Objects_In_Current_Container* tmp2 = new Number_Of_Objects_In_Current_Container;

      container.PushBack(tmp);
      tmp2->Number(container);
      tmp->Add(container, tmp2);
      break;
    }
    case 2: {
      Number_Of_Objects_In_Current_Container* tmp = new Number_Of_Objects_In_Current_Container;
      tmp->Number(container);
      container.PushBack(tmp);
      break;
    }
    case 3: {
      Number_Of_Tasks_With_Result* tmp = new Number_Of_Tasks_With_Result;
      tmp->Number(container);
      container.PushBack(tmp);
      break;
    }
    case 4: {
      Clean* tmp = new Clean;
      tmp->CleanContainer(container);
      container.PushBack(tmp);
      break;
    }
    case 5: {
      Number_Of_Objects* tmp = new Number_Of_Objects;
      container.PushBack(tmp);
      break;
    }
    default:
      break;
    }

    pr = rand() % 6;

  }

}

void DoneTasks(Container<Task*>& tasks, Container<std::string>& results)
{
  for (auto iter = tasks.begin(); iter != tasks.end(); ++iter) {
    auto task = *iter;
    results.PushBack(task->toString());
  }
}

template <typename T>
void Print(const Container<T>& container)
{
  size_t index = 1;
  for (auto iter = container.begin(); iter != container.end(); ++iter) {
    std::cout << index << ") " << *iter << std::endl;
    ++index;
  }
}

int main()
{
  using namespace std;
  Container<Task*> tasks;
  GenerateTasksContainer(tasks);
 
  Container<string> result_tasks;
  cout <<"Number of tasks : " << tasks.GetNumberElements()<<endl<<endl<<endl;

  DoneTasks(tasks, result_tasks);
  Print(result_tasks);

}