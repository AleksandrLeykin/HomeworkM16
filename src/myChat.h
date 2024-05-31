#pragma once

#include <string>
#include <vector>

#define LOGINLENGTH 10

class myChat {
public:
	myChat();
	~myChat() = default;
	//регистрация пользователя
	void userRegistration();
	void userRegistration(const std::string& name, const std::string& password, const std::string nick);
	//регистрация вход в чат(registration enter chat)
	void enterChat();
	//вывод пользователей (user output)
	void getPersons();
	
	//работа с сщщбщениями
	void MenuChoice();
private:
	struct Persons {
		std::string m_login;
		std::string m_password;
		std::string m_nickName;
		std::vector<std::string> m_mail;		

		Persons() :
			m_login(""),
			m_password(""),
			m_nickName("") 
		{}
		~Persons() = default;
	};

	//ввод информации (entering information)
	std::string getValue();
	int getint();
	//ввод строки с пробелами сообщения (Enter a string with spaces in the message)
	std::string getStringLine();
	//вход (enter chat)
	bool sing_in();
	//выбор пользователя для ввода сообщения (select user to enter message)
	void user_selection();

	std::string writeMessage();
	

	//очистка cin
	void cinClear();
	//количество пользователей (number of users)
	int m_countUser;
	void userRecording(Persons user);

	//хранение пользователей (user storage)
	std::vector<Persons> m_data;
	Persons m_user;
	std::vector<std::string> oldMessage;
};