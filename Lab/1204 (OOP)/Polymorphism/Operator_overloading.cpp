//Topic 2
#include <iostream>
using namespace std;

class Circuit
{
private:
    float real;
    float img;

public:
    Circuit(float r = 0, float i = 0)
    {
        real = r;
        img = i;
    }
    Circuit operator+(Circuit const &obj)
    {
        Circuit res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }
    void Show()
    {
        if (img < 0)
            cout << real << " -j" << img * -1 << endl;
        else
            cout << real << " +j" << img << endl;
    }
    Circuit operator*(Circuit const &obj)
    {
        Circuit res;
        res.real = real * (obj.real) - img * (obj.img);
        res.img = img * (obj.real) + real * (obj.img);
        return res;
    }
    Circuit operator/(Circuit const &obj)
    {
        Circuit res;
        int temp = obj.real * obj.real + obj.img * obj.img;
        res.real = (real * (obj.real) + img * (obj.img)) / temp;
        res.img = (img * (obj.real) - real * (obj.img)) / temp;
        return res;
    }
    Circuit operator||(Circuit const &obj)
    {
        Circuit N, D, res;
        N = ((*this) * (obj));
        D = ((*this) + (obj));
        res = N / D; // this works
        // res = ((*this) * (obj)) / ((*this) + (obj)) ; this does't . Don't know why.
        return res;
    }
};

int main()
{
    Circuit z1(3, 4), z2(4, -3), z3(0, 6), v(100, 50), Zeq, i;
    // Zeq = z1 || z2 || z3;
    Zeq = (z1 * z2 * z3) / ((z1 * z2) + (z2 * z3) + (z3 * z1));
    i = v / Zeq;
    Zeq.Show();
    i.Show();
}