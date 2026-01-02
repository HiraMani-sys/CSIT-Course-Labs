#include <iostream>
#include <graphics.h> 
#include <conio.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

	cout << "--- BSA ---"<< endl;
    int x0, y0, x1, y1;
    cout << "Enter starting point (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter ending point (x1, y1): ";
    cin >> x1 >> y1;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int sx = (dx >= 0) ? 1 : -1;   // step direction in x
    int sy = (dy >= 0) ? 1 : -1;   // step direction in y

    dx = (dx >= 0) ? dx : -dx;     // absolute distance in x
    dy = (dy >= 0) ? dy : -dy;     // absolute distance in y

    int x = x0, y = y0;

    // Gentle slope (|m| <= 1)
    if (dy <= dx) {
        int p = 2 * dy - dx;
        
        cout<< endl << "Plotted point (x, y):" << endl;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);                 // draw pixel
            cout << "("<< x << ", " << y << ")\n";
            x += sx;
            if (p >= 0) {
                y += sy;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
            delay(50);
        }
    }
    // Steep slope (|m| > 1)
    else {
        int p = 2 * dx - dy;
        
        cout << endl << "Plotted point (x, y):" << endl;
        for (int i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            cout << "("<< x << ", " << y << ")\n";
            y += sy;
            if (p >= 0) {
                x += sx;
                p += 2 * (dx - dy);
            } else {
                p += 2 * dx;
            }
            delay(50);
        }
    }

    getch();
    closegraph();
    return 0;
}

