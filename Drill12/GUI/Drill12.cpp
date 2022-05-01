/*
    g++ Drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images` 
*/
#include "Simple_window.h"
#include "Graph.h"


int main()
{
	try
	{
		using namespace Graph_lib;

		Point tl {100, 100};	

		Simple_window win {tl, 600, 400, "My window"};
		
		Axis xa {Axis::x, Point{20, 300}, 180, 10, "x axis"};
		Axis ya {Axis::y, Point{20, 300}, 280, 5, "y axis"};
		
		ya.set_color(Color::blue);
		ya.label.set_color(Color::yellow);
		
		
		Function sine {sin,0,100,Point{20,150},1000,50,50};
		
		sine.set_color(Color::cyan);
		
		
		Polygon poly;
		poly.add(Point{300,200});
		poly.add(Point{350,100});
		poly.add(Point{400,200});
		
		poly.set_color(Color::dark_red);
		//poly.set_style(Line_style::dash);
		poly.set_style(Line_style(Line_style::dash,4));
		
		
		Rectangle r {Point{200,150}, 100, 50};
		
		r.set_fill_color(Color::magenta);
		
		
		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		poly_rect.add(Point{50,75});
		poly_rect.add(Point{60,55});
		
		poly_rect.set_style(Line_style(Line_style::dash,2));
		poly_rect.set_fill_color(Color::dark_green);
		
		
		Text t {Point(150,150), "Szia uram!"};
		
		t.set_font(Font::times_bold);
		t.set_font_size(20);
		
		
		Image ii {Point{400,210}, "38538.jpg"};
		
		
		Circle c {Point{100,200},50};
		c.set_style(Line_style::dash);
		Ellipse e {Point{100,200},75,25};
		e.set_color(Color::dark_yellow);
		Mark m {Point{100,205},'x'};
		
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};
		
		
		Image cal {Point{225,225}, "Kermit.gif"};
		cal.set_mask(Point{40,40},200,150);
		
		win.attach(xa);
		win.attach(ya);
		win.attach(sine);
		win.attach(poly);
		win.attach(r);
		win.attach(poly_rect);
		win.attach(t);
		win.attach(ii);
		win.attach(c);
		win.attach(e);
		win.attach(m);
		win.attach(sizes);
		win.attach(cal);
		
		//win.set_label("Canvas #2");
		
		win.wait_for_button();
	}
			
	catch  (exception& e)
	{
		cerr << "error:" << e.what() << '\n';
			keep_window_open();
		return 1;
	}
	
	catch (...)
	{
		cerr << "Oops: unknown exeprion&!\n";
			keep_window_open();
		return 2;
	}

}
