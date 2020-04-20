#include <dos.h>
class INPUT_MOUSE {
               private:
	union REGS i,o;
               public:
                     int x,y,button;
	 int status();                       //Returns 0 on success.
	 void show();
	 void hide();
	 void button_location(int &button, int &x,int &y);
	 void gotoxy(int x, int y);
	 void restrict(int x1,int y1, int x2, int y2);
} mouse;
int INPUT_MOUSE :: status() {
	i.x.ax = 0;
	int86(0x33,&i,&o);
	return (o.x.ax);
}
void INPUT_MOUSE :: show() {
	i.x.ax=1;
	int86( 0x33, &i,&o);
}
void INPUT_MOUSE :: hide() {
	i.x.ax=0;
	int86( 0x33, &i, &o);
}
void INPUT_MOUSE :: button_location(int &button, int &x,int &y) {
	i.x.ax=3;
	int86( 0x33, &i, &o);
	button = o.x.bx;
	x = o.x.cx;
	y = o.x.dx;
}
void INPUT_MOUSE :: gotoxy(int x, int y) {
	i.x.ax=4;
	i.x.cx=x;
	i.x.dx=y;
	int86(0x33, &i, &o);
}
void INPUT_MOUSE :: restrict(int x1,int y1, int x2, int y2) {
	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86( 0x33, &i , &o);
	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86( 0x33, &i, &o);
}