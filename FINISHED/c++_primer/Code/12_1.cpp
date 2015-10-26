/*
+----------------------------------------------------------
*
* @authors: 风之凌殇 <1054073896@qq.com>
* @FILE NAME:	 12_1.cpp
* @version:
* @Time: 		 2015-08-20 12:15:19
* @Description:
*
+----------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <sstream>


using namespace std;
class QueryResult;
class TextQuery
{
	using line_no = vector<string>::size_type;

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm ;

public:
	TextQuery() = default;
	TextQuery(ifstream &is);
	QueryResult query(const string&) const;
	~TextQuery() {}


};

TextQuery::TextQuery(ifstream &is): file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;

		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult {
	using line_no = vector<string>::size_type;

	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>>p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought)const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}

void runQueries(ifstream &);



int main() {
	ifstream is("test");
	runQueries(is);

	cout << endl;
	system("pause");
	return 0;
}

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}
