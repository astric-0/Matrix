#include<iostream>
#include<ncurses.h>
#include<cstdlib>
#include<time.h>
using namespace std;

int main(){
	
	initscr();
	
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);	
	init_pair(5, COLOR_CYAN, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_RED, COLOR_RED);

	srand(time(0));

	// standard screen size 
	int maxX=getmaxx(stdscr), maxY=getmaxy(stdscr);
	
	// max width and height of every block
	int max_w = 20, max_h = 20;
	
	// max blocks to print before clearing
	int max_blocks=500;

	// block type [0=random size, 1=cursor sized]
	int b_type = 0;
	// blocks counter
	int i=0;			
	while(true){

		// clear screen
		if(i==max_blocks)
			clear(), refresh(), i=0;

		// make a choice to print block or not
		int choice = rand()%2;
		if(choice){
			int width = rand()%max_w, height = rand()%max_h;
			int x = rand()%maxX, y = rand()%maxY;
			
			// randomly choose color pair
			int color = rand()%8;			
			/* for fixed color int color = [color pair number]; */
			
			// RANDOM SIZED BLOCKS			
			if(b_type==0){
				for(int i=0; i<height; i++){
					for(int j=0; j<width; j++){
						wattron(stdscr, COLOR_PAIR(color));
						mvwaddch(stdscr, y+i, x+j, ' ');
						wattroff(stdscr, COLOR_PAIR(color));
					}
				}				
			}			
			// CURSOR SIZED BLOCKS
			else if(b_type=1){			
				wattron(stdscr, COLOR_PAIR(color));
				mvwaddch(stdscr, y, x, ' ');
				wattroff(stdscr, COLOR_PAIR(color));						
			}

			refresh(), i++;
		}		
	}

	endwin();
	return 0;
}
