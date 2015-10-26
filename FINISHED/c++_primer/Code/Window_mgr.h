#include "Screen.h"
#include <vector>
#include <string>



class Window_mgr
{
private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
public:
	Window_mgr() = default;
	Window_mgr(int a, int b) {}
	~Window_mgr() {}
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear (ScreenIndex);
};
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
