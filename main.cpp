#include <iostream>

using namespace std;

class cmplx{
private:
    double re,im; //z=re+j*im


public:
    ~cmplx(){cout<<"DESTRUIDO"<<endl;};
    cmplx(){};
    cmplx(double a,double b) : re(a), im(b) {};
    double Re(){return re;}; //retorna Re
    double Im(); //retorna Im
    cmplx& recebe_Re (double a);
    cmplx& recebe_Im (double b);

    static int z_count; //informa qtos numeros complexos foram criados
};

double cmplx::Im(){
return im;
};

cmplx& cmplx::recebe_Re(double a){
re=a;
return *this;
}


cmplx& cmplx::recebe_Im(double b){
im=b;
return *this;
}

cmplx operator+(cmplx& z1, cmplx& z2){
    cmplx  soma;
    soma.recebe_Re(z1.Re()+z2.Re());
    soma.recebe_Im(z1.Im()+z2.Im());
    return soma;
}

cmplx operator-(cmplx& z1, cmplx& z2){
    cmplx  dif;
    dif.recebe_Re(z1.Re()-z2.Re());
    dif.recebe_Im(z1.Im()-z2.Im());
    return dif;
}

cmplx operator-(cmplx& z){
    cmplx oposto;
    oposto.recebe_Re(-z.Re());
    oposto.recebe_Im(-z.Im());
    return oposto;
}

cmplx operator*(cmplx& z1, cmplx&& z2){
    cmplx  resutado;
    resutado.recebe_Re(z1.Re()*z2.Re()-z1.Im()*z2.Im());
    resutado.recebe_Im(z1.Re()*z2.Re()+z1.Im()*z2.Im());
    return resultado;
}

ostream& operator<<(ostream& impressao,cmplx& z){
    if(z.Im()<0.0){impressao<<z.Re()<<"-j"<<(-1*z.Im());}
    else{impressao<<z.Re()<<"+j"<<z.Im();}
return impressao;
}

int main()
{
    cmplx z, z2(3.0,4.0),z3(6,8); //z complexo
    z=-z3;
    cout<<"Z: "<<z<<std::endl;
    cout<<"Z1: "<<z2<<endl;
    cout<<"Z2: "<<z3<<endl;

    return 0;
}
