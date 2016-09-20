#include <iostream>
using namespace std;
typedef double Mat3x3[3][3];
double det(Mat3x3 m)
{
    return (m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2]) - m[0][1]*(m[1][0]*m[2][2]-m[2][0]*m[1][2]) + m[0][2]*(m[1][0]*m[2][1]-m[2][0]*m[1][2]));
}
int main()
{
    Mat3x3 m;

    cout << "Unesi prvu  tacku: "; cin >> m[0][0] >> m[0][1]; m[0][2]=1;
    cout << "Unesi drugu tacku: "; cin >> m[1][0] >> m[1][1]; m[1][2]=1;
    cout << "Unesi trecu tacku: "; cin >> m[2][0] >> m[2][1]; m[2][2]=1;

    if (det(m)) cout << "Tacke su nekolinearne!" << endl;
    else cout << "Tacke su kolinearne!" << endl;

    return 0;
}
