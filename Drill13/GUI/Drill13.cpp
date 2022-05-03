/*
    g++ Drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` 
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	try
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
	

		for (int i = 0; i < 8; ++i)
		{
			rec.push_back(new Rectangle(Point{i*100, i*100}, 100, 100));
			rec[i].set_fill_color(Color::red);
			
			win.attach(rec[i]);
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
