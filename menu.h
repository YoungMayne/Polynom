#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>

#ifndef _menu_H
#define _menu_H

#define KEY_UP 72
#define KEY_DOWN 80 
#define ENTER 13
#define ESC 27

class menu {
public:
		menu();
		menu(const std::vector<std::string> items);

		void add(const std::vector<std::string> items);
		void clear();

		std::string join();

private:
		std::vector<std::string> vItems;
		int active = 0;

		HANDLE handle;

		void draw();
		void hide_cursor(bool status);
};

inline menu::menu() {
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

inline menu::menu(const std::vector<std::string> items) : menu() {
		vItems = items;
}

inline void menu::add(const std::vector<std::string> items) {
		for (const auto &i : items) {
				vItems.push_back(i);
		}
}

inline void menu::clear(){
		vItems.clear();
		active = 0;
}

inline std::string menu::join() {
		hide_cursor(true);
		draw();

		while (true) {
				if (_kbhit()) {
						switch (_getch()) {
						case KEY_UP:
								active -= 1;
								if (active < 0) {
										active = vItems.size() - 1;
								}
								draw();
								break;
						case KEY_DOWN:
								active += 1;
								if (active > vItems.size() - 1) {
										active = 0;
								}
								system("cls");
								draw();
								break;
						case	ENTER:
								hide_cursor(false);
								return vItems[active];
						case ESC:
								hide_cursor(false);
								return "NULL";
						}
				}
		}
}

inline void menu::draw() {
		system("cls");
		for (int i = 0; i < vItems.size(); ++i) {
				if (i == active) {
						std::cout << "->\t" << vItems[i] << std::endl;
				}
				else {
						std::cout << '\t' << vItems[i] << std::endl;
				}
		}
}

inline void menu::hide_cursor(bool status){
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(handle, &structCursorInfo);
		structCursorInfo.bVisible = !status;
		SetConsoleCursorInfo(handle, &structCursorInfo);
}

#endif 
