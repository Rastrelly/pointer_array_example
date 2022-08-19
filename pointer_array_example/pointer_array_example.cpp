#include <iostream>
#include <ctime>

int * arr1; //об'явлення масиву 1 як покажчика
int * arr2; //об'явлення масиву 2 як покажчика

//функція заповнює масив випадковими числами
void fillArray(int n, int *&pArr)
//конструкція *&pArr дозволяє передавати посилання
//на "динамічний" масив, де * декларує параметр
//pArr як покажчик, а & дозволяє функції виконувати
//операції з об'єктом, що знаходиться за адресою
//цього покажчика
{
	if (n > 0)
	{
		delete(pArr);//очищення пам'яті для масиву
		
		pArr = new int[n]; //створення нового масиву

		for (int i = 0; i < n; i++)
		{
			pArr[i] = rand() % 100;
		}
	}
}

void printArray(int n, int * pArr)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d) %d\n", i, pArr[i]);
	}
}

int main()
{
	srand(time(NULL)); //вмикаємо генератор випадкових чисел
	fillArray(10, arr1); //заповнюємо масив 1
	fillArray(10, arr2); //заповнюємо масив 2
	printArray(10, arr1); //друкуємо масив 1
	printArray(10, arr2); //друкуємо масив 2
	delete(arr1); //вивільняємо пам'ять
	delete(arr2);
	system("pause");
}