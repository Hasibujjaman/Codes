#include <iostream>
 
using namespace std;
 
class Father
{
private:
    int money;
 
protected:
    int gold;
 
public:
    int land;
};
 
class Son : public Father
{
public:
    // setters
    void setGold(int gold)
    {
        this->gold = gold;
    }
    void setLand(int land)
    {
        this->land = land;
    }
 
    // getters
    int getGold()
    {
        return this->gold;
    }
    int getLand()
    {
        return this->land;
    }
};
 
class GrandSon : public Son
{
};
 
int main()
{
    Son s;
    s.setLand(10);
    cout << s.getLand() << endl;
}