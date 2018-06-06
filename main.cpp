#include <iostream>

//using namespace std;

class cmplx {
private:
    double re, im; //z=re+j*im
    static int z_count; //static n pode ser iniciado dentro da classe //informa qtos numeros complexos foram criados
    int z_num;

public:
    ~cmplx(){z_count--;}; //destrutor

    cmplx(double a, double b): re(a), im{b}{}; //ao selecionar o c++11, podemos iniciar o objeto im como im{b} ao invés de im(b)
    cmplx(){cmplx(0.0,0.0);z_count++;z_num=z_count;}; //construtor padrão, inicia o numero como 0+0j e faz a contagem de qtos z foram criados
    cmplx(double a){cmplx(a,0.0);}; //construtor para numero real, chamado ao iniciar z(re)

    cmplx& recebe_Re(double a); //atribuicao de valor para a parte real
    cmplx& recebe_Im(double b); //atribuicao de valor para a parte imaginaria

    int num(){return z_num;};
    static int cmplx_count (){return z_count;};

    double Re(){return re;}; //retorna a parte real
    double Im();

};
    int cmplx::z_count=0; //inicializacao da var static deve ser feita FORA da classe
    double cmplx::Im(){return im;}; //retorna a parte imaginaria

    cmplx& cmplx::recebe_Re(double a){re=a; return *this;}  //atribuicao de valor
    cmplx& cmplx::recebe_Im(double b){im=b; return *this;}

    cmplx operator+(cmplx& z1, cmplx& z2){

        cmplx soma;

        soma.recebe_Re(z1.Re()+z2.Re());
        soma.recebe_Im(z1.Im()+z2.Im());
        return soma;
    }

    cmplx operator- (cmplx& z1, cmplx& z2){

        cmplx diff;

        diff.recebe_Re(z1.Re()-z2.Re());
        diff.recebe_Im(z1.Im()-z2.Im());

        return diff;
    }
    cmplx operator-(cmplx& z){

        cmplx oposto;

        oposto.recebe_Re(-z.Re());
        oposto.recebe_Im(-z.Im());

        return oposto;
    }
    cmplx operator*(cmplx& z1, cmplx&& z2){

        cmplx  resultado;

        resultado.recebe_Re(z1.Re()*z2.Re()-z1.Im()*z2.Im());
        resultado.recebe_Im(z1.Re()*z2.Re()+z1.Im()*z2.Im());

        return resultado;
    }

    cmplx operator/(cmplx& z1, cmplx& z2){

        cmplx razao;

        razao.recebe_Re(((z1.Re()*z2.Re()+z1.Im()*z2.Im())/(z2.Re()*z2.Re()+z2.Im()*z2.Im())));
        razao.recebe_Im(((z2.Re()*z1.Im()-z1.Re()*z2.Im())/(z2.Re()*z2.Re()+z2.Im()*z2.Im())));

        return razao;
    }

    std::ostream& operator<<(std::ostream& impressao,cmplx& z){

        if(z.Im()<0.0){impressao<<z.Re()<<"-j"<<(-1*z.Im());}
        else{impressao<<z.Re()<<"+j"<<z.Im();}

        return impressao;
    }
int main()
{
    int a;
    cmplx z,z1(2,0), z2(-1,1);
    z=z1/z2;

    printf("Numeros complexos\n");
    printf("z1: ");
    std::cout<<z1<<std::endl;
    printf("z2: ");
    std::cout<<z2<<std::endl;
    printf("z1/z2: ");
    std::cout <<z<< std::endl;
    //a=cmplx::num();
    //printf("z_num: %d", a);
    return 0;
}
