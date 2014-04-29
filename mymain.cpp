#include "displayprogram.h"
//class Djuping1
//{
//public:
//	Djuping1(string t)
//	{
//		_tp = new string(t);
//		
//	};
//
//	~Djuping1()
//	{
//		delete _tp;
//	}
//
//	Djuping1 & operator=(Djuping1 & d)
//	{
//		delete _tp;
//		_tp = new string(*d._tp);
//		
//		return *this;
//	}
//
//	Djuping1(const Djuping1 & orginal)
//	{
//		_tp = new string(*orginal._tp);
//	
//	}
//
//	Djuping1 & operator+(Djuping1 h)
//	{
//		*_tp += *h._tp;
//		return *this;
//	};
//
//	
//	friend Canvas & operator <<(Canvas & cancan, Djuping1 & dj);
//
//private:
//	string * _tp;
//	
//};


class Djuping1
{
public:
	Djuping1(string t)
	{
		_utp = unique_ptr<string>(new string(t));
		
	};

	Djuping1(const Djuping1 & orginal)
	{
		_utp = unique_ptr<string>(new string(*orginal._utp));
		
	}

	Djuping1 & operator=(Djuping1 & d)
	{
		_utp = unique_ptr<string>(new string(*d._utp));
		
		return *this;
	}

	Djuping1 & operator+(Djuping1 h)
	{
		*_utp += *h._utp;
		return *this;
	};

	

	friend Canvas & operator <<(Canvas & cancan, Djuping1 & dj);

private:
	unique_ptr<string> _utp;
	
};
//Canvas & operator <<(Canvas & cancan, Djuping1 & dj)
//{
//	Font font(cancan, "Arial", 24);
//
//	font.draw_text(cancan, 250, 250, *dj._tp, Colorf(0, 0, 0, 1.0));
//
//	return cancan;
//}
Canvas & operator <<(Canvas & cancan, Djuping1 & dj)
{
	Font font(cancan, "Arial", 24);

	font.draw_text(cancan, 250, 250, *dj._utp, Colorf(0, 0, 0, 1.0));

	return cancan;
}

void DisplayProgram::mymain(DisplayWindow window, Canvas cv, InputDevice keyboard, InputDevice mouse, Font font)
{
	Djuping1 minDjuping("Hej du");
	minDjuping + Djuping1("dudu");    //2 Vad blir fel? Hur löser man det (två steg)  
	//Finns ingen operator
	while (looping(keyboard, window, cv))
	{
		{
			Djuping1 minDjuping3("yes");  //1 Vad blir fel? Hur löser man det?
			//Finns ingen konstruktor och objektet skapas lokalt för varje loop

			minDjuping = minDjuping3;	   //3 Vad blir fel? Hur löser man det
			//Finns ingen operator för Djuping1=Djuping1
		}					   
		cv<<minDjuping;			   //2 Hur löser man detta	?
		//Skapa operator mellan canvas och Djuping1
		
	}

} 