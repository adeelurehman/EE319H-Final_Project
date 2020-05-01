#ifndef GemClass
#define GemClass

class Gem {
public:
	const unsigned short* gemTexture;

	int w;
	int h;

	int x;
	int y;
	
	int type; //0 for water, 1 for fire
	int collect;

	Gem(int x, int y, int w, int h, int t);
	void drawMe();
	void collected();

	bool testG(int x, int y, int w, int h) const;
};

#endif

