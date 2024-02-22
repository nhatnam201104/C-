class phanso
{
protected:
    int tu;
    int mau;

public:
    phanso() {
        tu=0;
        mau=1;
    };
    bool operator>(phanso another)
    {
        return this->tu * another.mau > this->mau * another.tu;
    }
    // chuyen kieu
    operator float ()
    {
        return (float) this->tu/this->mau   ;
    }
};
