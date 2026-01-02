#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  
	cout << "--- DDA ---"<<endl;
    float x0, y0, x1, y1;
    cout << "Enter the points (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter the points (x1, y1): ";
    cin >> x1 >> y1;

    float dx = x1 - x0;
    float dy = y1 - y0;

    int steps = (fabs(dx) > fabs(dy)) ? abs(dx) : abs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float X = x0;
    float Y = y0;

    cout << "\nPlotted Points (x, y):\n";

    for (int i = 0; i <= steps; i++) {
        int px = (int)(X + 0.5);
        int py = (int)(Y + 0.5);

        putpixel(px, py, WHITE);
        cout << "(" << px << ", " << py << ")\n";

        X += Xinc;
        Y += Yinc;
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
