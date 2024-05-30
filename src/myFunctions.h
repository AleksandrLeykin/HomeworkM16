#include "myChat.h"
#include <memory>
#include <iostream>


//запуск проекта(start of the project)
void startMessengerChat() {
	while (true)
	{
		//переменная для работы с чатом (variable for working with chat)
		std::unique_ptr<myChat> user1 = std::make_unique<myChat>();
		user1->userRegistration("masha", "234e", "Masha");
		user1->enterChat();
		//список всех пользователей(list of all users)
		user1->getPersons();


		std::cout << "Хотите продолжить работу с мессенджером?" << std::endl;
		std::cout << "Если да то нажмите - y, если нет то - n" << std::endl;
		char enterExit;
		std::cin >> enterExit;
		switch (enterExit)
		{
		case 'n':
			return;
			break;
		case 'y':
			break;
		default:
			std::cout << "Введен не верный символ! Значит продолжаем работу:)" << std::endl;
			break;
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}