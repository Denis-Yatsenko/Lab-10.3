#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

struct Worker {
	int workerNum;
	string surname;
	string initials;
	string posada;
	int year;
	int salary;
};

void PrintInFile(ofstream& f, Worker* w, const int amount);

void PrintAddedRowInFile(ofstream& f, Worker* w, const int amount);

void CreateTable(Worker* w, const int amount);

void PrintTable(Worker* w, const int amount);

void AddRow_PrintRow(Worker* w, const int amount, ofstream& f);

void ChangeTable(Worker* w, const int amount, ofstream& f);

void ShowInfoWorker(Worker* w, const int amount);

void MainMenu(Worker* w, const int amount, ofstream& f);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int workerAmount = 0, premenu = 0;

	string filename, filenamehelp;

	do {
		cout << "������ ������� ��������: "; cin >> workerAmount;
		if (workerAmount < 1) {
			cout << "ʳ������ ���������� �� ���� ���� ������ ������!" << endl;
		}
	} while (workerAmount < 1);

	Worker* w = new Worker[workerAmount];

	cout << endl << " ������ ����� �����, � ���� ���� ������� �������: "; cin >> filenamehelp;
	filename = filenamehelp + ".txt";
	cout << " ������� ���� �������� � ���� '" << filename << "'" << endl;
	ofstream f(filename);

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ��������� �������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> premenu;

		switch (premenu) {
		case 1:
			cout << endl << "�������� �������:" << endl;

			CreateTable(w, workerAmount);
			PrintInFile(f, w, workerAmount);

			cout << endl << " ������� ������ ��������� �� �������� � ����!" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}

		if (premenu == 1) {
			MainMenu(w, workerAmount, f);
		}
	} while (premenu != 0);

	f.close();
	return 0;
}

void PrintInFile(ofstream& f, Worker* w, const int amount) {
	f << "===================================================================================" << endl;
	f << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	f << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < amount; i++) {
		f << "| " << left << w[i].workerNum << " ";
		f << "| " << setw(18) << left << w[i].surname
			<< " | " << setw(8) << left << w[i].initials
			<< " | " << setw(16) << left << w[i].posada
			<< " | " << setw(13) << left << w[i].year
			<< " | " << setw(8) << left << w[i].salary
			<< " | " << endl;
	}
	f << "-----------------------------------------------------------------------------------" << endl << endl;
}

void PrintAddedRowInFile(ofstream& f, Worker* k, const int amount) {

	f << "===================================================================================" << endl;
	f << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	f << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < amount; i++) {
		f << "| " << left << k[i].workerNum << " ";
		f << "| " << setw(18) << left << k[i].surname
			<< " | " << setw(8) << left << k[i].initials
			<< " | " << setw(16) << left << k[i].posada
			<< " | " << setw(13) << left << k[i].year
			<< " | " << setw(8) << left << k[i].salary
			<< " | " << endl;
	}
	f << "-----------------------------------------------------------------------------------" << endl << endl;
}

void CreateTable(Worker* w, const int amount) {
	for (int i = 0; i < amount; i++) {
		w[i].workerNum = i + 1;
		cout << "���������� � " << w[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   �������: "; getline(cin, w[i].surname);
		cout << "	�������: "; getline(cin, w[i].initials);
		cout << "	������: "; getline(cin, w[i].posada);
		cout << "	г� �������: "; cin >> w[i].year;
		cout << "	��������: "; cin >> w[i].salary;
		cout << endl;
	}
}

void PrintTable(Worker* w, const int amount) {
	cout << "===================================================================================" << endl;
	cout << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < amount; i++) {
		cout << "| " << left << w[i].workerNum << " ";
		cout << "| " << setw(18) << left << w[i].surname
			<< " | " << setw(8) << left << w[i].initials
			<< " | " << setw(16) << left << w[i].posada
			<< " | " << setw(13) << left << w[i].year
			<< " | " << setw(8) << left << w[i].salary
			<< " | " << endl;
	}

	cout << "===================================================================================" << endl << endl;
}

void AddRow_PrintRow(Worker* w, const int amount, ofstream& f) {
	int rowplus, newAmount;
	do {
		cout << endl << "������ ������ ����� ������: "; cin >> rowplus;
		if (rowplus < 1)
			cout << "�� ���� ���� ������ ������ 1 �����!" << endl;
	} while (rowplus < 1);

	newAmount = amount + rowplus;

	Worker* k = new Worker[newAmount];

	for (int i = 0; i < amount; i++) {
		k[i].workerNum = w[i].workerNum;
		k[i].surname = w[i].surname;
		k[i].initials = w[i].initials;
		k[i].posada = w[i].posada;
		k[i].year = w[i].year;
		k[i].salary = w[i].salary;
	}

	for (int j = 1, i = amount; i < newAmount; j++, i++) {
		k[i].workerNum = amount + j;
		cout << "���������� � " << k[i].workerNum << ": " << endl;
		cin.get();
		cin.sync();
		cout << "   �������: "; getline(cin, k[i].surname);
		cout << "	�������: "; getline(cin, k[i].initials);
		cout << "	������: "; getline(cin, k[i].posada);

			cout << "	г� �������: "; cin >> k[i].year;

			cout << "	��������: "; cin >> k[i].salary;
	
		cout << endl;
	}
	PrintTable(k, newAmount);
	PrintAddedRowInFile(f, k, newAmount);
}

void ChangeTable(Worker* w, const int amount, ofstream& f) {
	int changetablemenu = 0;

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ������ ����� �� ������� �������" << endl << endl;
		cout << "������ ��������: "; cin >> changetablemenu;

		switch (changetablemenu) {
		case 1:
			AddRow_PrintRow(w, amount, f);
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (changetablemenu != 1);
}

void ShowInfoWorker(Worker* w, const int amount) {
	string surname;
	bool answer = false;
	int neededIndex = 0;

	do {
		cout << "������ ������� ��������, ���������� ��� ����� ������� �������: ";
		cin.get();
		cin.sync();
		getline(cin, surname);

		for (int i = 0; i < amount; i++) {
			if (surname == w[i].surname) {
				answer = true;
				neededIndex = i;
			}
		}
		if (answer == false) {
			cout << "��������� � ����� �������� ���� � �������!" << endl;
		}
	} while (answer == false);

	cout << endl;
	cout << "===================================================================================" << endl;
	cout << "| � | ������� ��������� | ������� | ������ ��������� | г� ��������� | �������� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "| " << left << w[neededIndex].workerNum << " ";
	cout << "| " << setw(18) << left << w[neededIndex].surname
		<< " | " << setw(8) << left << w[neededIndex].initials
		<< " | " << setw(16) << left << w[neededIndex].posada
		<< " | " << setw(13) << left << w[neededIndex].year
		<< " | " << setw(8) << left << w[neededIndex].salary
		<< " | " << endl;
	cout << "===================================================================================" << endl;
}

void MainMenu(Worker* w, const int amount, ofstream& f) {
	int mainMenu = 0;

	do {
		cout << endl << endl;
		cout << "������� ��:" << endl;
		cout << " [1] - ������� ��������� �������" << endl;
		cout << " [2] - ���������� ��������� �������" << endl;
		cout << " [3] - ������� ���������� ��� ����������� ���������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> mainMenu;

		switch (mainMenu) {
		case 1:
			PrintTable(w, amount);
			break;
		case 2:
			ChangeTable(w, amount, f);
			break;
		case 3:
			ShowInfoWorker(w, amount);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! ��� ������ ����� - ����� ��������� ������ ����!" << endl;
			break;
		}
	} while (mainMenu != 0);
}

