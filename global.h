#pragma once
using namespace std;

const vector<string> studentTitle = { "学号", "姓名", "专业", "班号", "电话号码" }; 
const vector<string> bookTitle = { "书号", "书名", "作者", "出版社", "馆藏本数" ,"已借阅数", "出版日期" };
const vector<string> borrowBookTitle = { "书号", "书名", "作者", "出版社", "出版日期", "借书日期" };

template<typename T, typename Y>
void a2b(const T& a,Y& b) {
	stringstream ss;
	ss << a;
	ss >> b;
}

extern accounts g_accounts;
extern Books g_books;
extern Book g_book;
extern Students g_students;
extern Students copy_students;
extern Book g_clickBook;
extern vector<Book> g_listBook;
extern pair<string, tm>g_clickBorrowBook;

extern Student g_student;
extern Student g_clickStudent;
extern vector<Student> g_StudentList;
