/*
    g++ Drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Point t1 {100,100};
	
	Simple_window win{t1,800,1000,"My window"};
	
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	
	
	Lines grid;
	for (int x = x_grid; x <= x_size; x += x_grid)
		grid.add(Point{x,0}, Point{x,y_size});
	for (int y = y_grid; y <= y_size; y += y_grid)
		grid.add(Point{0,y}, Point{x_size,y});
		
		
	Vector_ref<Rectangle> rec;
	
	int a = 0;
	for (int i = 0; i<8; ++i)
	{
		for (int j = 0; j<8; ++j)
		{
			rec.push_back(new Rectangle{Point{a,a},100,100});
			rec[rec.size()-1].set_fill_color(Color::red);
			win.attach(rec[rec.size()-1]);
		}
		
		a += 100;
		
	}
	
	Image i1 {Point{0, 200}, "orange.jpg"};
	i1.set_mask(Point{0,0},200,200);
	
	Image i2 {Point{200, 0}, "orange.jpg"};
	i1.set_mask(Point{0,0},200,200);
	
	Image i3 {Point{400, 600}, "orange.jpg"};
	i1.set_mask(Point{0,0},200,200);
	
	Image i4{Point{0,0},"run.jpg"};
	i4.set_mask(Point{0,0},100,100);
	
	
	win.attach(grid);
	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	win.attach(i4);
	
	
	for (int x = 0; x < 8; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			win.wait_for_button();
			i4.move(100,0);
			win.set_label("Run");
		}
	i4.move(-800,100);
	}
	
	
}
