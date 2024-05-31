#pragma once

#include <string>
#include <vector>

#define LOGINLENGTH 10

class myChat {
public:
	myChat();
	~myChat() = default;
	//����������� ������������
	void userRegistration();
	void userRegistration(const std::string& name, const std::string& password, const std::string nick);
	//����������� ���� � ���(registration enter chat)
	void enterChat();
	//����� ������������� (user output)
	void getPersons();
	
	//������ � �����������
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

	//���� ���������� (entering information)
	std::string getValue();
	int getint();
	//���� ������ � ��������� ��������� (Enter a string with spaces in the message)
	std::string getStringLine();
	//���� (enter chat)
	bool sing_in();
	//����� ������������ ��� ����� ��������� (select user to enter message)
	void user_selection();

	std::string writeMessage();
	

	//������� cin
	void cinClear();
	//���������� ������������� (number of users)
	int m_countUser;
	void userRecording(Persons user);

	//�������� ������������� (user storage)
	std::vector<Persons> m_data;
	Persons m_user;
	std::vector<std::string> oldMessage;
};