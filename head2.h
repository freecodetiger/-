#define ROWS 40
#define COLS 40
#define SPACE 20
bool isContinue = 1;
using namespace std;

class GetAndSet {
public:
	//获取鼠标信息，与界面交互
	void getAndSet(int map[ROWS][COLS]) {
		MOUSEMSG msg;
		while (isContinue) {
			msg = GetMouseMsg();
			if (msg.mkLButton) {
				map[msg.y / SPACE][msg.x / SPACE] = 1;
			}
			else if (msg.mkRButton) {
				map[msg.y / SPACE][msg.x / SPACE] = 0;
			}
		}
	}
};
