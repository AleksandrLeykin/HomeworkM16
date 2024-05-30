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
	//����� �������������
	void getPersons();
	//����
	bool sing_in();
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

	
	std::string getValue();
	int getint();
	//������� cin
	void cinClear();
	//���������� ������������� (number of users)
	int m_countUser;
	void userRecording(Persons user);
	//�������� ������������� (user storage)
	std::vector<Persons> m_data;
	Persons m_user;
};