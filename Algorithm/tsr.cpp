#include <iostream>
#include <cmath>
using namespace std;

// Translation
int v, tx, ty;

// Scaling
int sx, sy, xf, yf;

// Rotation
int xr, yr, angle;
float rad;

// Result matrices
int res1[3][10], res2[3][10];
float res3[3][10];

// Matrix multiplication function for integer matrices
void mul(int ip[3][10], int ml[3][3], int res[3][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                res[i][j] += ml[i][k] * ip[k][j];
            }
        }
    }
}

// Matrix multiplication function for float matrices (rotation result)
void mulFloat(int ip[3][10], float ml[3][3], float res[3][10]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                res[i][j] += ml[i][k] * ip[k][j];
            }
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> v;
    int a[3][10], t[3][3], s[3][3];
    float rot[3][3];

    cout << "Enter the values of tx & ty: \n";
    cin >> tx >> ty;

    cout << "Enter the values of sx & sy:\n ";
    cin >> sx >> sy;

    cout << "Enter the values of xr & yr: \n";
    cin >> xr >> yr;

    cout << "Enter the values of xf & yf: \n";
    cin >> xf >> yf;

    cout << "Enter the value of angle: \n";
    cin >> angle;

    // Input matrix
    for (int i = 0; i < v; i++) {
        cout << "Enter vertex [" << i << "]: ";
        cin >> a[0][i] >> a[1][i];
        a[2][i] = 1;  // Homogeneous coordinate
    }

    // Translation Matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t[i][j] = (i == j) ? 1 : 0;
        }
    }
    t[0][2] = tx;
    t[1][2] = ty;

    // Scaling Matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s[i][j] = (i == j) ? 1 : 0;
        }
    }
    s[0][0] = sx;
    s[1][1] = sy;
    s[0][2] = xf * (1 - sx);
    s[1][2] = yf * (1 - sy);

    // Rotation Matrix
    rad = angle * M_PI / 180;  // Convert angle to radians
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rot[i][j] = (i == j) ? 1 : 0;
        }
    }
    rot[0][0] = cos(rad);
    rot[0][1] = -sin(rad);
    rot[0][2] = xr * (1 - cos(rad)) + yr * sin(rad);
    rot[1][0] = sin(rad);
    rot[1][1] = cos(rad);
    rot[1][2] = yr * (1 - cos(rad)) - xr * sin(rad);

    // Perform matrix multiplication
    mul(a, t, res1);         // Translation
    mul(a, s, res2);         // Scaling
    mulFloat(a, rot, res3);  // Rotation (float result)

    // Display matrices and results
    cout << "Input Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nTranslation Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nResult Matrix after Translation:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            cout << res1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nScaling Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nResult Matrix after Scaling:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            cout << res2[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nRotation Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << rot[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nResult Matrix after Rotation:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v; j++) {
            cout << res3[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

