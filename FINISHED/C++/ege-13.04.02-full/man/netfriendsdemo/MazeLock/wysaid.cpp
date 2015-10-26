#include "wysaid.h"

const wchar_t g_wblocks[] = { L'��', L'��', L'��', L'��', L'��', L'��', L'��',
                              L'��', L'��', L'��', L'��'
                            };

const char g_cblocks[][4] = { "��", "��", "��", "��", "��", "��", "��",
                              "��", "��", "��", "��"
                            };

const char g_mask[][10] = {  //�Ҫ�ǰ�����ĳɶ�����16λ��short�����߿��������,��֪����᲻�ᵰ��
	"000111000",
	"010010010",
	"000011010",
	"010110000",
	"010011000",
	"000110010",
	"010110010",
	"010111000",
	"010011010",
	"000111010",
	"010111010",
};

Stack::Stack()
{
	size = 0;
	capacity = MAX_CAPACITY;
	point = (Elem*)malloc(capacity * sizeof(Elem));   //Ϊ��ʹ��reallocʡ�£�����new
}

Stack::~Stack()
{
	free(point);
}

void Stack::push(const Elem &elem)
{
	if (size >= capacity)
	{
		capacity *= 2;
		point = (Elem*)realloc(point, capacity * sizeof(Elem));
	}
	point[size++] = elem;
}

int Stack::pop(Elem &elem)
{
	if (size == 0) return 0;
	elem = point[--size];
	return 1;
}

bool Map::initMap(const char* filename)
{
	using std::fstream;
	fstream file(filename, fstream::in | fstream::binary);
	char str[BUFFER_SIZE];
	int i, j = 0;
	bool bflag = true;
	if (!!file) file.getline(str, BUFFER_SIZE);
	else return false;
	m_width = strlen(str) & -2;
	while (!!file)
	{
		for (i = 0; i != m_width; i += 2)
		{
			m_map[j] = reflect(str + i);
			if (m_map[j] < 0)
				return false;
			++j;
		}
		++m_height;
		file.getline(str, BUFFER_SIZE, L'\n');
		if (m_width > strlen(str) || m_width * m_height >= 10 * BUFFER_SIZE) break;
	}
	m_width /= 2;
	file.close();
	return true;
}


void Map::printMap()
{
	LOGFONT fnt;
	setcolor(WHITE);
	getfont(&fnt);
	fnt.lfCharSet = GB2312_CHARSET;
	fnt.lfHeight = SCR_HEIGHT / m_height - 1;
	fnt.lfWidth = SCR_WIDTH / m_width - 1;
	fnt.lfQuality = DEFAULT_QUALITY;
	fnt.lfWeight = FW_DONTCARE;
	setfontbkcolor(DARKGRAY);
	strcpy(fnt.lfFaceName, "����");
	setfont(&fnt);
	for (int i = 0; i != m_height; ++i)
	{
		for (int j = 0; j != m_width; ++j)
			xyprintf(j * fnt.lfWidth, i * fnt.lfHeight, "%s", g_cblocks[m_map[i * m_width + j]]);
	}
	setfontbkcolor(RED);
	fnt.lfWidth = 12;
	fnt.lfHeight = 20;
	setfont(&fnt);
	outtextxy(20, SCR_HEIGHT - fnt.lfHeight - 10, "�����ĵ�ͼ���ϣ����������رղ����¶��룬�����밴�����!");
}

void Map::genMask()
{
	int n = m_width * m_height - 1;
	int m = 0;
	memset(m_mapMask, -1, 100000);
	for (int i = 0; i != m_height; ++i)
	{
		for (int j = 0; j != 3; ++j)
			for (int k = 0; k != m_width; ++k)
				for (int l = 0; l != 3; ++l)
					m_mapMask[m++] = g_mask[m_map[i * m_width + k]][j * 3 + l] - '0';
	}
//	memcpy(m_bkMask, m_mapMask, 100000);
}

void Map::showMask()
{
	int width, height, maskWidth, maskHeight;
	maskWidth = getMaskWitdh();
	maskHeight = getMaskHeight();
	width = (SCR_WIDTH - 10) / maskWidth;
	height = (SCR_HEIGHT - 30) / maskHeight;
	setfillcolor(DARKGRAY);
	for (int i = 0; i < maskHeight; ++i)
	{
		for (int j = 0; j < maskWidth; ++j)
			if (m_mapMask[i * maskWidth + j] == 1)
			{
				bar(j * width, i * height, (j + 1)*width, (i + 1)*height);
//				delay_ms(0);
			}
		Sleep(10);
	}
}

bool Map::showResult()     //������ҳɹ����map����ʹ�ñ�����!
{
	Stack stk;
	int i, cnt = 0, width, height, maskWidth, maskHeight;
	Elem elem;
	maskWidth = getMaskWitdh();
	maskHeight = getMaskHeight();
	width = (SCR_WIDTH - 10) / maskWidth;
	height = (SCR_HEIGHT - 30) / maskHeight;
	for (i = (maskHeight - 2) * maskWidth - 1; i != -2; i = m_mapMask[i] - 1)
	{

		elem.y = i / maskWidth;
		elem.x = i % maskWidth;
		stk.push(elem);
		if (++cnt > 100000)
		{
			return false;
		}
	}
	setfillcolor(YELLOW);
	while (stk.pop(elem))
	{
		bar(elem.x * width, elem.y * height, (elem.x + 1)*width, (elem.y + 1)*height);
		Sleep(2);
	}
	outtextxy(20, SCR_HEIGHT - 40, "�㶨��!��������������ĵ�ͼ!");
	while (kbhit()) getch();
	getch();
	return true;
}

bool Map::fuckit(Stack& stk)
{
	Elem elem, tmp;
	int width = getMaskWitdh(),	height = getMaskHeight();

	while (stk.pop(elem))
	{
		if (elem.x == width - 1 && elem.y == height - 3)
		{
			return true;
		}
		tmp = elem;
		tmp.x -= 1;
		if (tmp.x >= 0 && m_mapMask[tmp.y * width + tmp.x] == 0)
		{
			stk.push(tmp);
			m_mapMask[tmp.y * width + tmp.x] = elem.y * width + elem.x + 1;
		}
		tmp.x = elem.x + 1;
		if (tmp.x < width && m_mapMask[tmp.y * width + tmp.x] == 0)
		{
			stk.push(tmp);
			m_mapMask[tmp.y * width + tmp.x] = elem.y * width + elem.x + 1;
		}
		tmp.x = elem.x;
		tmp.y = elem.y - 1;
		if (tmp.y >= 0 && m_mapMask[tmp.y * width + tmp.x] == 0)
		{
			stk.push(tmp);
			m_mapMask[tmp.y * width + tmp.x] = elem.y * width + elem.x + 1;
		}
		tmp.y = elem.y + 1;
		if (tmp.y < height && m_mapMask[tmp.y * width + tmp.x] == 0)
		{
			stk.push(tmp);
			m_mapMask[tmp.y * width + tmp.x] = elem.y * width + elem.x + 1;
		}
	}
	return 0;
}

char reflect(const char* block)
{
	short n = *reinterpret_cast<const short*>(block);
	for (int i = 0; i != BLOCK_NUM; ++i)
		if (n == *reinterpret_cast<const short*>(g_cblocks + i))
			return i;
	return -1;
}

char reflect(wchar_t block)  //�⺯�����ǵ���
{
	switch (block)
	{
	case L'��': return 0;
	case L'��': return 1;
	case L'��': return 2;
	case L'��': return 3;
	case L'��': return 4;
	case L'��': return 5;
	case L'��': return 6;
	case L'��': return 7;
	case L'��': return 8;
	case L'��': return 9;
	case L'��': return 10;
	}
	return -1;
}

bool getFileNameDlg(HWND hwnd, LPSTR pfilename)
{
	OPENFILENAMEA ofna;
	char szFilter[] = {"�ı��ĵ� (*.txt)\0*.txt\0"
	                  "���ʲô��׺��~ (*.*)\0*.*\0\0"};
	*pfilename = 0;
	memset(&ofna, 0, sizeof(OPENFILENAMEA));
	ofna.lStructSize = sizeof (OPENFILENAMEA);
	ofna.hwndOwner = hwnd;
	ofna.hInstance = NULL;
	ofna.lpstrFilter = szFilter;
	ofna.nMaxFile = MAX_PATH;
	ofna.lpstrDefExt = "txt";
	ofna.lpstrFile = pfilename;
	ofna.lpstrTitle = "���ҵ����ƽ��Թ��ı��ļ�!";
	ofna.Flags = OFN_HIDEREADONLY | OFN_CREATEPROMPT;
	return !!GetOpenFileNameA(&ofna);
}
