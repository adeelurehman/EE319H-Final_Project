
#ifndef ButtonClass
#define ButtonClass

class Button {
public:
	const unsigned short* buttonTexture;

	int w;
	int h;

	int x;
	int y;
	
	int type; 
	int press;

	Button(int x, int y, int w, int h, int t);
	void drawMe();
	void pressed();
	void released();

	bool testButton(int x, int y, int w, int h) const;
};
#endif
