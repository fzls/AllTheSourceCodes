#include <string>
// class Window_mgr;

class Screen
{
	friend class Window_mgr;
	// friend void Window_mgr::clear(Window_mgr::ScreenIndex);

public:
	static int test;
	static void staticTest() {++test; }
	char nonstaticTest() {return get();}
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
	~Screen() {}

	Screen &set(char);
	Screen &set(pos, pos, char);
	char get() const {return contents[cursor];}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	// using pos = std::string::size_type;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}
int Screen::test = 233;
