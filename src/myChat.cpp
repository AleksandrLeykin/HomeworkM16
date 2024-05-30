#include "myChat.h"
#include <iostream>
#include <fstream>

myChat::myChat()
{
	m_countUser = 0;
	// тестовое окрытие файла для чтения
	std::ifstream in("persons.txt");
	if (in.is_open()) {
		Persons newP;
		while (in >> newP.m_login >> newP.m_password >> newP.m_nickName)
			m_data.push_back(newP);
	}
	in.close();
}

void myChat::userRegistration()
{
	std::cout << "Введите логин: ";
	m_user.m_login = getValue();
	cinClear();
	std::cout << "\n";
	std::cout << "Введите пароль: ";
	m_user.m_password = getValue();
	cinClear();
	std::cout << "\n";
	std::cout << "Введите имя: ";
	m_user.m_nickName = getValue();
	cinClear();
	std::cout << "\n";

	m_data.push_back(m_user);
	m_countUser++;
	//тестовая запись
	userRecording(m_user);
}

void myChat::userRegistration(const std::string& name, const std::string& password, const std::string nick) {
	m_user.m_login = name;
	m_user.m_password = password;
	m_user.m_nickName = nick;

	bool userIsTrue = false;
	for (int i = 0; i < m_data.size(); ++i) {
		if (m_data[i].m_login == name && m_data[i].m_password == password)
			userIsTrue = true;		
	}
	if (userIsTrue == false) {
		userRecording(m_user); //тестовая запись
		m_data.push_back(m_user);
		m_countUser++;
	}	
}

void myChat::enterChat()
{
	while (true)
	{
		std::cout << "Для входа нажмите - 1, для регистрации - 2, для выхода 3: ";
		int number = getint();
		switch (number)
		{
		case 1:
			if(sing_in() == false)
			{
				std::cout << "Не верный логин или пароль!!" << std::endl;
				break;
			}
			return;
		case 2:
			userRegistration();
			return;
		case 3:
			return;
		default:
			std::cout << "Введен не верный символ!!" << "\n";
			break;
		}

	}
}

void myChat::getPersons()
{
	std::cout << "Зарегестрированных пользователей: " << m_data.size() << std::endl;
	for (int i = 0; i < m_data.size(); ++i)
	{
		std::cout << (i + 1) << ")." << m_data[i].m_nickName << " ";
	}
	std::cout << std::endl;
}

bool myChat::sing_in()
{
	std::cout << "Введите свое имя:" << std::endl;
	std::string buffer_login = "";
	std::cin >> buffer_login;
	int count = 0;
	for (int i = 0; i < m_data.size(); ++i) {
		if (m_data[i].m_login == buffer_login) {
			std::cout << "Enter password:" << std::endl;
			std::string buffer_password = "";
			std::cin >> buffer_password;
			if (m_data[i].m_password == buffer_password) {
				std::cout << m_data[i].m_nickName << ", welcome!" << std::endl;
				++count;
			}
			++count;
		}
		else
			continue;
	}
	if (count != 2)
		return false;
	return true;	
}

std::string myChat::getValue() {
	std::string str = "";
	std::cin >> str;
	return str;
}

int myChat::getint() {
	while (true) {
		int num = 0;
		std::cin >> num;
		if (std::cin.fail()) {
			cinClear();
			std::cout << "Веден не верный символ! ";
		}
		else
			return num;
	}	
}

void myChat::cinClear() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void myChat::userRecording(Persons user) {
	// поток для записи(stream to write)
	std::ofstream out;
	//дозапись текста в файле (adding text to a file)
	out.open("persons.txt", std::ios::app);
	if (out.is_open())
		out << user.m_login << " " << user.m_password << " " << user.m_nickName <<std::endl;
	out.close();
}
