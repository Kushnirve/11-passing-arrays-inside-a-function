#include <iostream>
using namespace std;

//1.1
int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
	if (m < 3) y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

int LeapYears(int year, int month)
{
	int years = year;

	// Check if the current year needs to be considered 
	// for the count of leap years or not 
	if (month < 3)
		years--;

	// An year is a leap year if it is a multiple of 4, 
	// multiple of 400 and not a multiple of 100. 
	return years / 4 - years / 100 + years / 400;
}

int betweenDates(int y1, int m1, int d1, int y2, int m2, int d2)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE date1
	// initialize count using years and day 
	long int n1 = y1 * 365 + d1;

	// Add days for months in given date 
	for (int i = 0; i < m1 - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days, 
	// Add a day for every leap year 
	n1 += LeapYears(y1, m1);

	// COUNT TOTAL NUMBER OF DAYS BEFORE date2 
	long int n2 = y2 * 365 + d2;
	for (int i = 0; i < m2 - 1; i++)
		n2 += monthDays[i];
	n2 += LeapYears(y2, m2);

	// return difference between two counts 
	return (n2 - n1);
}

// 1.2
void Average(int masiv[], int size) {
	int average = 0;
	for (int i = 0; i < size; i++) {
		average += masiv[i];
	}
	average /= size;
	cout << "Average is: " << average;
}

// 1.3
void NegPosNull(int masiv[], int size) {
	int negsum = 0, nullsum = 0, possum = 0;
	for (int i = 0; i < size; i++) {
		if (masiv[i] < 0) negsum++;
		else if (masiv[i] == 0) nullsum++;
		else possum++;
	}
	cout << "Positive: " << possum << " Null: " << nullsum << " Negative: " << negsum;
}

//2.1
int LinearSearch(int array[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (array[i] == key) return i;
	}
	return -1;
}

// 2.2
int BinarySearch(int array[], int size, int key) {
	int half = size / 2;
	for (int i = 0; i < size; i++) {
		if (key < array[half]) {
			size = half;
			half = size / 2;
		}
		if (key > array[half]) {
			i = half;
			half = (size + half) / 2;
		}
		if (array[i] == key) return i = i + 1;
	}
	return -1;
}

// 2.3
void BintoDecTrans(int binnum) {
	int a, b = 1, result = 0;
	while (binnum != 0) {
		a = binnum % 10;
		binnum /= 10;
		a *= b;
		result += a;
		b *= 2;
	}
	cout << result;
}

int main() {
	setlocale(0, "rus");

	////1.1
	int first_year, first_month, first_day, second_year, second_month, second_day;
	cin >> first_year >> first_month >> first_day;
	cin >> second_year >> second_month >> second_day;
	// v1
	int days = rdn(first_year, first_month, first_day) - rdn(second_year, second_month, second_day);
	cout << "V1. Количество дней: " << abs(days) << endl; // функция abs выводит значение по модулю чтобы было все равно какую дату вводить первой большую или меньшую
	// v2
	cout << "V2. Количество дней: " << abs(betweenDates(first_year, first_month, first_day, second_year, second_month, second_day));

	// 1.2
	const int size = 10;
	int masiv[size] = { 5,1,5,1,5,1,5,1,5,1 };
	Average(masiv, size);

	// 1.3
	const int size = 10;
	int masiv[size] = { -5,1,5,1,0,-1,5,0,5,1 };
	NegPosNull(masiv, size);

	//// 2.1
	const int arraySize = 100;
	int masiv[arraySize], searchKey, element;
	for (int i = 0; i < arraySize; i++) {
		masiv[i] = 2 * i;
		cout << masiv[i] << " ";
	}
	cout << "Введите ключ: ";
	cin >> searchKey;
	element = LinearSearch(masiv, arraySize, searchKey);
	if (element != -1) cout << "\nКлюч найден в элементе " << element << '\n';
	else cout << "\nЗначение не найдено ";

	// 2.2
	const int arraySize = 100;
	int masiv[arraySize], searchKey, element;
	for (int i = 0; i < arraySize; i++) {
		masiv[i] = 2 * i;
		cout << masiv[i] << " ";
	}
	cout << "\nВведите ключ: ";
	cin >> searchKey;
	element = BinarySearch(masiv, arraySize, searchKey);
	if (element != -1) cout << "\nКлюч найден в элементе " << element << '\n';
	else cout << "\nЗначение не найдено ";

	// 2.3
	int binnum;
	cin >> binnum;
	BintoDecTrans(binnum);
}