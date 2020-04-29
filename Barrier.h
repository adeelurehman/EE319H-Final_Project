#ifndef Barrierh
#define Barrierh

class Barrier {
public:
	int x;
	int y;
	int w;
	int h;
	
	Barrier(int x, int y, int w, int h);
	void drawMe() const;

	//calculates if passed rect overlaps with self
	//false for overlap
	//true for no overlap
	bool test(int x, int y, int w, int h) const;
};

#endif
