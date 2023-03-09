#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Messager.h"
struct UserLoginExp :public std::exception 
{//вызываем класс исключений, в случае, если пользователя all
	const char* what() const noexcept override 
	{
		return "error: user login is busy";
	}

};
struct UserNameExp :public std::exception 
{//вызываем класс исключений, в случае , если пользователь all
	const char* what()const noexcept override 
	{
		return "error: user name is busy";
	}
};
class Chat 
{
	bool isChatWork_ = false;//переменная, отвечающая за работу чата
	std::vector<User> userList_;//создаем вектор, который хранит пользователей чата
	std::vector<Message> messageList_;//создаем вектор, который хранит сообщения в чате
	std::shared_ptr<User> currentUser_ = nullptr;//shared указатель указывает на текущего пользователя

	void login();
	void signUp();
	void showChat()const;
	void showAllUsersName()const;
	void addMessage();

	std::vector<User>& getAllUsers() 
	{
		return userList_;
	}
	std::vector<Message>& getAllMessages() 
	{
		return messageList_;
	}
	std::shared_ptr<User>getUserByLogin(const std::string& login)const;
	std::shared_ptr<User>getUserByName(const std::string& name)const;
public:
	void start();
	bool isChatWork()const 
	{
		return isChatWork_;
	}
	std::shared_ptr<User>getCurrentUser()const 
	{
		return currentUser_;
	}
	void showLoginMenu();
	void showUserMenu();
};