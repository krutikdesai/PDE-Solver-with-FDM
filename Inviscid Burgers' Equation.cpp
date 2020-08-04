#include <fstream>
#include <vector>
#include <iomanip>

void print_at_time(std::vector <double> u, double n, std::ofstream &fp){
    fp << std::fixed << std::setprecision(3);
    for(double x : u){fp << x << "  ";}
    fp << std::endl;
}

int main(){
    double nx = 20, nt = 50, dt = 0.01;
    double dx = 2/(nx - 1);
    std::vector <double> u,x,t,un;
    std::ofstream fout;
    fout.open("IBE.txt");

    for(int i=0; i<nx ; ++i){
        x.push_back(i*dx);
        if (x[i] <= 1 && x[i] >= 0.5) {u.push_back(2);}
        else {u.push_back(1);}
    }

    for(int j=0; j < nt; j++){
        t.push_back(j*dt);
        un = u;
        for(int k=1; k<nx && j>0; ++k){
            u.at(k) = un[k] - ((dt/dx) * (un[k]) * (un[k]- un[k-1]));
        }
        print_at_time(u, t[j],fout);
    }
    fout.close();
    return 0;
}
