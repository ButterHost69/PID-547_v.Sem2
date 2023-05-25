#pragma once

class Users
{
private:
	std::string __username__;
	std::string __passwd__;

public:
	int register_form();
	int login_form();
};