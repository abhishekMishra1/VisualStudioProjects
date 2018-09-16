#include"Manager.h"

int main()
{
	Manager m;
	m.createTasks();
	m.ProcessMessages();
#if defined(DEBUG_MODE)
	system("pause");
#endif
	return 0;
}