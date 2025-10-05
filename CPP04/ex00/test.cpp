#include <iostream>
#include <string>

class Per
{
    protected:
        int  x;
    public:
        Per() : x(1){std::cout << "Def-Constr, Per" << std::endl;};
        Per(int x) : x(x){std::cout << "Constr, Per" << std::endl;};
        ~Per(){std::cout << "Destr, Per" << std::endl;}; 
        void prin(void)
        {
            std::cout<<"hello"<<std::endl;
        }
       int getx()
        {
            return x;
        }

};
class fil : public Per
{
    private :
        int y;
    public:
        fil(): y(2){x = 2; std::cout << "Def-Constr, fil" << std::endl;};
        fil(int x, int y) : Per(x), y(y){std::cout << "Constr, fil" << std::endl;};
        ~fil(){std::cout << "Destr, Per" << std::endl;};
    void prin(void)
    {
        std::cout<<"world"<<std::endl;
    }
    int gety()
    {
        return y;
    }
};

int main ()
{
    //  Per *objp = new Per(2);
    //  fil *objf = new fil(2, 2);
    //  Per *objpf = new fil(2, 2);
    //  objf->prin();
    //  objp->prin();
    //  objpf->prin();
    fil obj(2, 2);
    obj.prin();

}
