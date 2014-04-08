#include "displayprogram.h"
class Djuping1
{
public: 
	Djuping1(string t)
	{
		_tp = new string(t);
		_t = t;
	};

	~Djuping1()
	{
		delete _tp;
	}

	Djuping1 & operator=(Djuping1 & d)
	{
		delete _tp;
		_tp = new string(*d._tp);
		_t = *_tp;
		return *this;
	}

	Djuping1 (const Djuping1 & orginal)
	{ 
		_tp = new string(*orginal._tp);
		_t = *_tp;
	}

	Djuping1 & operator+(Djuping1 h)
	{
		_t = _t + h.getText();

		return Djuping1(_t);
	};
	
	string getText()
	{
		return _t;
	};

	friend Canvas & operator <<(Canvas & cancan, Djuping1 & dj);

private:
	string * _tp;
	string _t;
	Canvas * _cv;
};

Canvas & operator <<(Canvas & cancan, Djuping1 & dj)
{
	Font font(cancan, "Arial", 24);

	font.draw_text(cancan, 250, 250, dj.getText(), Colorf(0,0,0,1.0));

	return cancan;
}

class Djuping2
{
public:
		Djuping2(string t)
	{
		unique_ptr<string> _utp(new string(t));
		_t = t;
	};

	Djuping2 & operator=(Djuping2 & d)
	{
		unique_ptr<string> _utp(new string(d._t));
		_t = *_utp;
		return *this;
	}

	Djuping2 & operator+(Djuping2 h)
	{
		string text = _t + h.getText();
		return Djuping2(text);
	};

	string getText()
	{
		return _t;
	};

	friend Canvas & operator <<(Canvas & cancan, Djuping2 & dj);

private:
	string _t;
	Canvas * _cv;
};

Canvas & operator <<(Canvas & cancan, Djuping2 & dj)
{
	Font font(cancan, "Arial", 24);

	font.draw_text(cancan, 250, 250, dj.getText(), Colorf(0,0,0,1.0));

	return cancan;
}

void DisplayProgram::mymain(DisplayWindow window, Canvas cv,InputDevice keyboard, InputDevice mouse,Font font)
{
	Djuping2 minDjuping("Hej du");
	minDjuping+Djuping2("dudu");    //2 Vad blir fel? Hur löser man det (två steg). Finns ingen operator för Djuping1+Djuping1
	Djuping2 minDjuping3("yes");
	while (looping(keyboard,window,cv))
	{
		{
			//Djuping2 minDjuping3("yes");  //1 Vad blir fel? Hur löser man det? Finns ingen konstruktor, samt att objektet skapas för varje loop.
			minDjuping=minDjuping3;	   //3 Vad blir fel? Hur löser man det? Finns ingen operator för Djuping=Djuping.
		}					   //3 Vad blir fel? Hur löser man det?
		cv<<minDjuping;			   //2 Hur löser man detta? Skapar en funktion för << operatorn.
	}
}