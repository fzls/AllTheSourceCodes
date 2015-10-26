#include "wysaid.h"

char g_filename[MAX_PATH];
clock_t g_time;

int main()
{
	initgraph(SCR_WIDTH, SCR_HEIGHT);
	setrendermode(RENDER_AUTO);
	setcaption("���ڵ����Ի�����ѡ���ͼ�ı��ļ�!");
	cleardevice();
	if(getFileNameDlg(getHWnd(), g_filename))
	{
		setcaption("EGE֮����ר�Ž��ڽ���Թ�СӦ�ÿ�ʼ��ת~~");
		if(!mazeLock())
		{
			cleardevice();
			outtextxy(20, 200, "�����Թ�����ѧ��! Ϊë���߲���ȥ!�ӵ���!");
			outtextxy(10, 300, "�Թ�Ҫ��http://blog.misakamm.org/p/404���ɰ���!");
			outtextxy(20, 400, "����Enter���ɣ��Ұ����͹�ȥ~~��Ȼ�Ͳ���������~~");
			if(getch() == '\r')
				ShellExecuteA(getHWnd(), "open", "http://blog.misakamm.org/p/404", NULL, NULL, SW_SHOWMAXIMIZED);
		}
	}
	else
	{
		outtextxy(100, 100,"��ȡ�����ı�ѡ��Ի��������֪����ͼ�ı����ģ���ο�: ");
		outtextxy(100, 120, "http://tieba.baidu.com/p/1966519660");	
		outtextxy(20, 150, "��Enter���Ὣ�����Զ��򿪴�ҳ��Ȼ�󱾳����Զ��رգ���������ֱ�ӹر�...");
		if(getch() == '\r')
			ShellExecuteA(getHWnd(), "open", "http://tieba.baidu.com/p/1966519660", NULL, NULL, SW_SHOWMAXIMIZED);
	}
	closegraph();
	return 0;
}

bool mazeLock()
{
	Stack stk;
	Map map;
	Elem elem = {0, 2};  //ת��Ϊ�����Ժ�����
	int width, height;
	if(!map.initMap(g_filename)) return false;
	map.printMap();
	getch();
	outtextxy(20, 200, "���ڼ��ѵ�ʶ�������ͼ~~");
	g_time = clock();
	map.genMask();
	width = map.getMaskWitdh();
	height = map.getMaskHeight();
	map.initStartPoint(2 * width); //���������Ժ󣬰ѳ�ʼλ������Ϊ-1.
	map.initStartPoint(3 * width); //ÿ�ο�ʼӦ�������ߣ���Ȼ��Ҫ���Ҳ����ν��
	stk.push(elem);
	if(!map.fuckit(stk)) return false;
	g_time = clock() - g_time;
	xyprintf(20, 300, "�ұ�ʾ���� %d ms ֮������������.", g_time);
	xyprintf(20, 400, "3���Ӻ������ʾ������ȵĻ�����������Ͽ�ʼ!");
	g_time = 3000;
	while(!kbhit() && (g_time -= 100)) Sleep(100);
	cleardevice();
	map.showMask();
	if(!map.showResult())
	{
		MessageBoxA(getHWnd(), "�ƺ�����ʲô���⣬����˵Ӧ�ý�ó�����\r\n���ǣ��ҵ��ˣ������������ԣ�", "��ⳬ��10�����Զ�ֹͣ", MB_OK);
	}
	return true;
}
