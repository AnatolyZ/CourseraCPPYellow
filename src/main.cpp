#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

TaskStatus& operator++(TaskStatus& t){
	int result = (static_cast<int>(t));
	result++;
	t =(static_cast<TaskStatus>(result));
	return t;
}


class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const{
		return dev_to_tasks.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person){
		dev_to_tasks[person][TaskStatus::NEW]++;
	}
	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person,
			int task_count){
		TasksInfo updated;
		TasksInfo untouched = dev_to_tasks[person];
		for (auto& [task,count]:dev_to_tasks[person]) {
			if (task != TaskStatus::DONE) {
				if (count != 0) {
					if (count <= task_count) {
						TaskStatus tmp = task;
						updated[++tmp] = count;
						untouched[task] = 0;
						task_count -= count;
					} else {
						TaskStatus tmp = task;
						updated[++tmp] = task_count;
						untouched[task] = count - task_count;
						task_count = 0;
					}
				}
			} else{
				task_count = 0;
			}
		}

		for (auto& [task,count]:untouched) {
			dev_to_tasks[person][task] = untouched[task];
		}
		for (auto& [task,count]:updated) {
			dev_to_tasks[person][task] += updated[task];
		}
		for (int i = 0; i < 4; ++i){
			TaskStatus tmp_stat = static_cast<TaskStatus>(i);
			if (untouched.count(tmp_stat) != 0){
				if (untouched[tmp_stat] == 0){
					untouched.erase(tmp_stat);
				}
			}
			if (updated.count(tmp_stat) != 0) {
				if (updated[tmp_stat] == 0) {
					updated.erase(tmp_stat);
				}
			}
		}
		untouched.erase(TaskStatus::DONE);
		return make_tuple(updated,untouched);
	}
private:
	map<string,TasksInfo> dev_to_tasks;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" << ", "
			<< tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
			<< ", " << tasks_info[TaskStatus::TESTING]
			<< " tasks are being tested" << ", " << tasks_info[TaskStatus::DONE]
			<< " tasks are done" << endl;
}
void PrintUpdInfo(TasksInfo upd_info,TasksInfo unt_info) {
	cout << "[{\"NEW:\" " << upd_info[TaskStatus::NEW]
		 << ", \"IN PROGRESS:\" " << upd_info[TaskStatus::IN_PROGRESS]
		 << ", \"TESTING:\" " << upd_info[TaskStatus::TESTING]
		 << ", \"DONE:\" " << upd_info[TaskStatus::DONE] << "}, "
		 << "{\"NEW:\" " << unt_info[TaskStatus::NEW]
		 << ", \"IN PROGRESS:\" " << unt_info[TaskStatus::IN_PROGRESS]
		 << ", \"TESTING:\" " << unt_info[TaskStatus::TESTING]
		 << ", \"DONE:\" " << unt_info[TaskStatus::DONE] << "}]"
		 << endl;
}

int main() {
	TeamTasks tasks;
	/*
	*AddNewTasks Alice 5
	PerformPersonTasks Alice 5
	PerformPersonTasks Alice 5
	PerformPersonTasks Alice 1
	AddNewTasks Alice 5
	PerformPersonTasks Alice 2
	GetPersonTasksInfo Alice
	PerformPersonTasks Alice 4
	GetPersonTasksInfo Alice
	*/
	for (int i = 0; i < 5; ++i) {
		tasks.AddNewTask("Alice");
	}
	cout << "Added 5 NEW" << endl;
	cout << "Alices's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    cout << endl;
	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	cout << "Performed 5" << endl;
	PrintUpdInfo(updated_tasks,untouched_tasks);

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	cout << "Performed 5" << endl;
	PrintUpdInfo(updated_tasks,untouched_tasks);

	cout << endl;
	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
	cout << "Performed 1" << endl;
	PrintUpdInfo(updated_tasks,untouched_tasks);
	cout << endl;
	cout << "Alices's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	cout << endl;
	cout << "Added 5 NEW" << endl;
	for (int i = 0; i < 5; ++i) {
			tasks.AddNewTask("Alice");
		}
	cout << "Alices's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	cout << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
	cout << "Performed 2" << endl;
	PrintUpdInfo(updated_tasks,untouched_tasks);
	cout << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
	cout << "Performed 4" << endl;
	PrintUpdInfo(updated_tasks,untouched_tasks);
	cout << endl;




	return 0;
}

