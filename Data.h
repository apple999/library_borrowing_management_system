#pragma once
using namespace std;


inline CString S2C(const string& str) {
	return CString(str.c_str());
}
inline string C2S(const CString& cstr) {
	USES_CONVERSION;
	return T2CA(cstr);
}
inline CString I2C(const int x) {
	CString t;
	t.Format(_T("%d"), x);
	return t;
}
inline int C2I(const CString& cstr) {
	return _ttoi(cstr);
}

inline CString T2C(const tm& time) {
	CString a, b, c;
	a.Format(_T("%04d"), time.tm_year + 1900);
	b.Format(_T("%02d"), time.tm_mon + 1);
	c.Format(_T("%02d"), time.tm_mday);
	return a + b + c;
}
inline tm C2T(const CString& cstr) {
	USES_CONVERSION;
	string str = T2CA(cstr);
	tm time;
	time.tm_year = stoi(str.substr(0, 4)) - 1900;
	time.tm_mon = stoi(str.substr(4, 2)) - 1;
	time.tm_mday = stoi(str.substr(6, 2));
	return time;
}

inline tm _getTime() {
	time_t t;
	time(&t);
	return *localtime(&t);
}

/*
string _mT2S(const tm& time) {
	stringstream ss;
	ss << setw(4) << setfill('0') << time.tm_year << setw(4) << setfill('0') << time.tm_mon << setw(4) << setfill('0') << time.tm_mday;
	return ss.str();
}
*/

string _mC2S(const CString& cstr) {
	USES_CONVERSION;
	return T2CA(cstr);
}

class account : public pair<string, string> {
public:
	int userType; // 0不存在 1学生 2管理员 3管理员（&学生） //游客...
	account(const string& first = "", const string& second = "", const int userType = 0) :userType(userType), pair<string, string>(first, second) {}
	template<typename T>
	friend T& operator >> (T& in, account& acc) {
		in >> acc.first;
		in >> acc.second;
		in >> acc.userType;
		return in;
	}
	template<typename T>
	friend T& operator << (T& out, const account& acc) {
		const int len = 30;
		out << setw(len) << acc.first;
		out << setw(len) << acc.second;
		out << setw(len) << acc.userType;
		return out;
	}

	bool operator == (const account& other)const {
		return std::operator == (pair<string, string>(*this), pair<string, string>(other));
	}
};

class accounts :public map<string, account> {
public:
	void insert(const account& acc) {
		(*this)[acc.first] = acc;
	}
	int login(const account& acc) {
		if (count(acc.first) && acc == (*this)[acc.first]) return  (*this)[acc.first].userType;
		return 0;
	}
	void init(const string& address = "accounts.Tensei") {
		clear();
		load(address);
		if (empty()) {
			insert({ "admin", "123", 2 });
			insert({ "4035", "999", 1 });
		}
	}
	void load(const string& address = "accounts.Tensei") {
		fstream fp(address, ios::in);
		string temp;
		fp >> temp;
		if (temp != "acc_") {
			AfxMessageBox(CString((address + "不是账户文件！").c_str()));
			fp.close();
		}
		account acc;
		while (fp >> acc) {
			insert(acc);
		}
		fp.close();
	}
	void save(const string& address = "accounts.Tensei") {
		fstream fp(address, ios::out);
		fp << "acc_" << endl;
		for (auto& [_, acc] : *this) {
			fp << acc << endl;
		}
		fp.close();
	}
};

template<typename T>
T& operator >> (T& in, tm& time) {
	time = tm{ 0 };
	in >> time.tm_year; time.tm_year -= 1900;/* 年份，其值等于实际年份减去1900 */
	in >> time.tm_mon;
	in >> time.tm_mday;
	return in;
}
template<typename T>
T& operator << (T& out, const tm& time) {
	const int len = 30;
	out << setw(len) << time.tm_year + 1900;/* 年份，其值等于实际年份减去1900 */
	out << setw(len) << time.tm_mon;
	out << setw(len) << time.tm_mday;
	return out;
}
//图书管理
class Book {
public:
	//书号 书名 作者 出版社 出版日期
	string number, name, author, publisher;
	int totalNum, borrowNum;
	tm pubDay;//tm是库中时间类型
public:
	Book(string number = "", string name = "", string author = "", string publisher = "", int totalNum = 0, int borrowNum = 0, int year = -1, int month = -1, int day = -1) :number(number), name(name), author(author), publisher(publisher), totalNum(totalNum), borrowNum(borrowNum) {
		stringstream ss;
		ss << year << " " << month << " " << day;
		ss >> pubDay;
	}
	Book(string number, string name = "", string author = "", string publisher = "", int totalNum = 0, int borrowNum = 0, tm pubDay = tm()) :number(number), name(name), author(author), publisher(publisher), totalNum(totalNum), borrowNum(borrowNum), pubDay(pubDay) {
		
	}
	bool operator == (Book& other) const { return number == other.number; }

	bool findNumber(string& str) { return number.find(str) != number.npos; }
	bool finName(string& str) { 
		setlocale(LC_ALL, "chs");
		bool t = name.find(str) != name.npos;
		setlocale(LC_ALL, "C");
		return t; }
	bool findAuthor(string& str) { return author.find(str) != author.npos; }
	bool findPublisher(string& str) { return publisher.find(str) != publisher.npos; }
	bool findPubDay(string& str) { 
		stringstream ss;
		ss << setw(4) << setfill('0') << pubDay.tm_year << setw(4) << setfill('0') << pubDay.tm_mon << setw(4) << setfill('0') << pubDay.tm_mday;
		return ss.str().find(str) != ss.str().npos;
	}
	
	template<typename T>
	friend T& operator >> (T& in, Book& item) {
		in >> item.number;
		in >> item.name;
		in >> item.author;
		in >> item.publisher;
		in >> item.totalNum;
		in >> item.borrowNum;
		in >> item.pubDay;
		return in;
	}

	template<typename T>
	friend T& operator << (T& out, const Book& item) {
		const int len = 30;
		out << setw(len) << item.number;
		out << setw(len) << item.name;
		out << setw(len) << item.author;
		out << setw(len) << item.publisher;
		out << setw(len) << item.totalNum;
		out << setw(len) << item.borrowNum;
		out << setw(len) << item.pubDay;
		return out;
	}
	
	/* 0 number 1 name 2 author 3 publisher 4 totalNum 5 borrowNum 6 pubDay */
	vector<CString> getInfo() const{
		vector<CString> ret; 
		auto S2C = [](const string& str) {
			return CString(str.c_str());
		};
		auto I2C = [](const int x) {
			CString t;
			t.Format(_T("%d"), x);
			return t;
		};
		auto T2C = [&](const tm& time) {
			CString a, b, c;
			a.Format(_T("%04d"), time.tm_year + 1900);
			b.Format(_T("%02d"), time.tm_mon + 1);
			c.Format(_T("%02d"), time.tm_mday);
			return a + b + c;
		};
		ret.push_back(S2C(number));
		ret.push_back(S2C(name));
		ret.push_back(S2C(author));
		ret.push_back(S2C(publisher));
		ret.push_back(I2C(totalNum));
		ret.push_back(I2C(borrowNum));
		ret.push_back(T2C(pubDay));

		return ret;
	}
};


class Books : public map<string, Book> {
public:
	void insert(const Book& book) {
		if (count(book.number)) {
			Book& b = (*this)[book.number];
			b.totalNum += book.totalNum;
		}
		else {
			(*this)[book.number] = book;
		}
	}
	void init(const string& address = "Books.Tensei") {
		clear();
		load(address);
		
		/* 以下代码为测试用*/
		if (empty()) 
			insert(Book("TestBook01", "测试书目01", "Muriya", "Tensei", 10, 0, 2021, 7, 10));
	}
	void load(const string& address = "Books.Tensei") {
		fstream fp(address, ios::in);
		string temp;
		fp >> temp;
		if (temp != "book_") {
			AfxMessageBox(CString((address + "不是图书文件！").c_str()));
			fp.close();
		}
		Book bk;
		while (fp >> bk) {
			insert(bk);
		}
		fp.close();
	}
	void save(const string& address = "Books.Tensei") {
		fstream fp(address, ios::out);
		fp << "book_" << endl;
		for (auto& [_, bk] : *this) {
			fp << bk << endl;
		}
		fp.close();
	}

	void lend(const Book& book) {
		Book& target = (*this)[book.number];
		if (target.totalNum == target.borrowNum)throw "无书可借";
		target.borrowNum++;
	}

	void back(const Book& book) {
		Book& target = (*this)[book.number];
		if (0 == target.borrowNum)throw "无书可还";
		target.borrowNum--;
	}
};

//学生管理
class Student {
	//学号、姓名、专业、班级、手机号等
public:
	string id, name, major, classes, phone;
	vector<pair<string, tm>> myBorrowList;
public:
	Student(const string& id = "", const string& name = "", const string& major = "", const string& classes = "", const string& phone = "") :id(id), name(name), major(major), classes(classes), phone(phone) {
		
	}


	/*Student(const CString& id, const CString& name, const CString& major, const CString& classes, const CString& phone) : id(_mC2S(id)), name(_mC2S(name)), major(_mC2S(major)), classes(_mC2S(classes)), phone(_mC2S(phone)) {
		
	}*/
	bool operator == (Student& stu) const { return id == stu.id; };

	bool findId(string& str) { return id.find(str) != id.npos; }
	bool findName(string& str) { return name.find(str) != name.npos; }
	bool findMajor(string& str) { return major.find(str) != major.npos; }
	bool findClasses(string& str) { return classes.find(str) != classes.npos; }
	bool findPhone(string& str) { return phone.find(str) != phone.npos; }

	template<typename T>
	friend T& operator >> (T& in, Student& item) {
		in >> item.id;
		in >> item.name;
		in >> item.major;
		in >> item.classes;
		in >> item.phone;
		string s, stime;
		while (true) {
			in >> s >> stime;
			if (stime == "@@@" || stime.empty()) break;
			item.myBorrowList.emplace_back(s, C2T(S2C(stime)));
		}
		return in;
	}

	template<typename T>
	friend T& operator << (T& out, const Student& item) {
		const int len = 30;
		out << setw(len) << item.id;
		out << setw(len) << item.name;
		out << setw(len) << item.major;
		out << setw(len) << item.classes;
		out << setw(len) << item.phone;
		for (auto&& [id, time] : item.myBorrowList) {
			out << setw(len) << id;
			out << setw(len) << C2S(T2C(time));
		}
		out << setw(len) << "**" << " @@@";
		return out;
	}

	/* 0 id 1 name 2 major 3 classes 4 phone */
	vector<CString> getInfo() const{
		vector<CString> ret;
		auto S2C = [](const string& str) {
			return CString(str.c_str());
		};
		auto I2C = [](const int x) {
			CString t;
			t.Format(_T("%d"), x);
			return t;
		};
		ret.push_back(S2C(id));
		ret.push_back(S2C(name));
		ret.push_back(S2C(major));
		ret.push_back(S2C(classes));
		ret.push_back(S2C(phone));

		return ret;
	}

	void borrowBook(const Book& book) {
		myBorrowList.push_back(pair<string, tm>{book.number, _getTime()});
	}

	void returnBook(const pair<string, tm>& backbook) {
		myBorrowList.erase(find_if(begin(myBorrowList), end(myBorrowList),
			[&](auto& x) {return forward_as_tuple(x.first, C2S(T2C(x.second))) == forward_as_tuple(backbook.first, C2S(T2C(backbook.second))); }
		));
	}

	void renew(const pair<string, tm>& backbook) {
		find_if(begin(myBorrowList), end(myBorrowList),
			[&](auto& x) {return forward_as_tuple(x.first, C2S(T2C(x.second))) == forward_as_tuple(backbook.first, C2S(T2C(backbook.second))); }
		)->second = _getTime();
	}



};

class Students : public map<string, Student> {
public:
	void insert(const Student& stu) {
		(*this)[stu.id] = stu;
	}



	void init(const string& address = "Students.Tensei") {
		clear();
		load(address);
		/* test */
		//insert({ "4035", "XML","JK","2","133********" });
		if (empty())insert({"4035", "夏茂林","JK","2","133********"});
	}
	void load(const string& address = "Students.Tensei") {
		fstream fp(address, ios::in);
		Student stu;
		string temp;
		fp >> temp;
		if (temp != "stu_") {
			AfxMessageBox(CString((address + "不是学生文件！").c_str()));
			fp.close();
		}
		while (fp >> stu) {
			insert(stu);
			stu.myBorrowList.clear();
		}
		fp.close();
	}
	void save(const string& address = "Students.Tensei") {
		fstream fp(address, ios::out);
		fp << "stu_" << endl;
		for (auto& [_, stu] : *this) {
			fp << stu << endl;
		}
		fp.close();
	}
};

