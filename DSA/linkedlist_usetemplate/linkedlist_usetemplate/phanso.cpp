class phanso
{
protected:
    int tu;
    int mau;

public:
    phanso(/* args */);
    ~phanso();
    bool operator>(phanso another)
    {
        return this->tu * another.mau > this->mau * another.tu;
    }
    // chuyen kieu
    operator float()
    {
        return (float)this->tu / this->mau;
    }
};

phanso::phanso()
{
    mau = 1;
    tu = 0;
}