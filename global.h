#pragma once
using namespace std;

const vector<string> studentTitle = { "ѧ��", "����", "רҵ", "���", "�绰����" }; 
const vector<string> bookTitle = { "���", "����", "����", "������", "�ݲر���" ,"�ѽ�����", "��������" };
const vector<string> borrowBookTitle = { "���", "����", "����", "������", "��������", "��������" };

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
